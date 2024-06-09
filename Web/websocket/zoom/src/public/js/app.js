const socket = io();
const welcome = document.querySelector("#welcome");
const form = welcome.querySelector("form");
const room = document.getElementById("room");

room.hidden = true;

let roomName;

function addMessage(message){
    const ul = room.querySelector("ul");
    const li = document.createElement("li");

    li.innerText = message;
    ul.appendChild(li);
}

function done(message) {
    console.log(`Backend message: ${message}`);
}

function handleMessageSubmit(event){
    event.preventDefault();
    const input = room.querySelector("#message input");
    const value = input.value;

    socket.emit("new_message", input.value, roomName, () => {
        addMessage(`You: ${value}`)
    });
    input.value = "";
}

function handleNickNameSubmit(event){
    event.preventDefault();
    const input = room.querySelector("#name input"); 

    socket.emit("nickName", input.value);
    input.value = "";
}

function showRoom(){
    const h3 = document.querySelector("h3");
    const messageForm = room.querySelector("#message"); 
    const nameForm = room.querySelector("#name"); 

    welcome.hidden = true;
    room.hidden = false;
    h3.innerText = `Room: ${roomName}`;
    messageForm.addEventListener("submit", handleMessageSubmit); 
    nameForm.addEventListener("submit", handleNickNameSubmit); 
}

function handleRoomSubmit(event) {
    const input = form.querySelector("input");

    event.preventDefault();
    socket.emit("enter_room", input.value, showRoom);
    roomName = input.value;
    input.value = "";
}

form.addEventListener("submit", handleRoomSubmit);

socket.on("welcome", (user, newCount) => {
    const h3 = document.querySelector("h3");
    h3.innerText = `Room: ${roomName} (${newCount})`;
    addMessage(`${user} arrived!`);
});

socket.on("bye", (left, newCount) => {
    const h3 = document.querySelector("h3");
    h3.innerText = `Room: ${roomName} (${newCount})`;
    addMessage(`${left} left!`);
});

socket.on("new_message", addMessage);

socket.on("room_change", (rooms) => {
    const roomList = welcome.querySelector("ul");

    roomList.innerHTML = "";
    rooms.forEach(room => {
        const li = document.createElement("li");

        li.innerText = room;
        roomList.appendChild(li);
    });
});


// const socket = new WebSocket(`ws://${window.location.host}`);
// const messageList = document.querySelector("ul");
// const messageForm = document.querySelector("#message");
// const nickNameForm = document.querySelector("#nickname");

// function makeMessage(type, payload){
//     const object = {type, payload};

//     return (JSON.stringify(object));
// }

// socket.addEventListener("open", () => {
// 	console.log("Connected to Server!");
// });

// socket.addEventListener("message", (message) => {
//     const li = document.createElement("li");

//     li.innerText = message.data;
//     messageList.append(li);
// });

// socket.addEventListener("close", () => {
// 	console.log("Disconnected from Server!");
// });

// function handleMessageSubmit(event) {
//     event.preventDefault();
//     const input = messageForm.querySelector("input");

//     socket.send(makeMessage("message", input.value));
//     input.value = "";
// }

// function handleNickNameSubmit(event) {
//     event.preventDefault();
//     const input = nickNameForm.querySelector("input");

//     socket.send(makeMessage("nickname", input.value));
//     input.value = "";
// }

// messageForm.addEventListener("submit", handleMessageSubmit);
// nickNameForm.addEventListener("submit",handleNickNameSubmit);