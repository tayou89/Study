import http from "http";
import {Server} from "socket.io";
// import WebSocket from "ws";
import express from "express";
import { instrument } from "@socket.io/admin-ui";

const app = express();

app.set("view engine", "pug");
app.set("views", __dirname + "/views");
app.use("/public", express.static(__dirname + "/public"));
app.get("/", (req, res) => res.render("home"));
app.get("/*", (req, res) => res.redirect("/"));

const httpServer = http.createServer(app);
const wsServer = new Server(httpServer, {
    cors: {
        origin: ["https://admin.socket.io"],
        credentials: true
      }
});

instrument(wsServer, {
    auth: false,
  });

function getPublicRooms() {
    const {sockets: {adapter: {sids, rooms}}} = wsServer;
    const publicRooms = [];

    rooms.forEach((_, key) => {
        if (sids.get(key) === undefined)
            publicRooms.push(key);
    });
    return publicRooms;
}

function countRoom(roomName){
    console.log("Count Room: ", wsServer.sockets.adapter.rooms.get(roomName)?.size);
    return wsServer.sockets.adapter.rooms.get(roomName)?.size;
}

wsServer.on("connection", socket => {
    socket["nickName"] = "anonymous";
    socket.onAny((event) => {
        console.log(wsServer.sockets.adapter);
        console.log(`Socket Event: ${event}`);
    });
    socket.on("enter_room", (roomName, done) => {
        socket.join(roomName);
        console.log(socket.rooms);
        done();
        socket.to(roomName).emit("welcome", socket.nickName, countRoom(roomName));
        wsServer.sockets.emit("room_change", getPublicRooms());
    });
    socket.on("disconnecting", () => {
        socket.rooms.forEach(room => socket.to(room).emit("bye", socket.nickName, countRoom(room) - 1));
    });
    socket.on("disconnect", () => {
        wsServer.sockets.emit("room_change", getPublicRooms());
    });
    socket.on("new_message", (message, roomName, done) => {
        socket.to(roomName).emit("new_message", `${socket.nickName}: ${message}`);
        done();
    });
    socket.on("nickName", (nickName) => {
        socket["nickName"] = nickName;
    });
});

// const wss = new WebSocket.Server({ server });
// const sockets = [];

// wss.on("connection", (socket) => {
//     sockets.push(socket);
//     socket["nickname"] = "anonymous";
// 	console.log("Connected to Browser!");
// 	socket.on("close", () => console.log("Disconnected from Browser!"));
// 	socket.on("message", (message) => {
//         const messageObject = JSON.parse(message.toString());

//         switch (messageObject.type) {
//             case "message":
//                 sockets.forEach(aSocket => aSocket.send(`${socket.nickname}: ${messageObject.payload}`));
//             case "nickname":
//                 socket["nickname"] = messageObject.payload;
//         }
// 	});
// });

const handleListen = () => console.log(`Listening on http://localhost:3000`);
httpServer.listen(3000, handleListen);