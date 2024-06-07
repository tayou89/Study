const socket = new WebSocket(`ws://${window.location.host}`);

socket.addEventListener("open", () => {
	console.log("Connected to Server!");
});

socket.addEventListener("message", (message) => {
	console.log("Server Message: ", message.data); 
});

socket.addEventListener("close", () => {
	console.log("Disconnected from Server!");
});

setTimeout(() => socket.send("Hello I'm browser!"), 10000);