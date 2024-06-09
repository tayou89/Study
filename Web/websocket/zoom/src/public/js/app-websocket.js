const socket = new WebSocket(`ws://${window.location.host}`);
const messageList = document.querySelector("ul");
const messageForm = document.querySelector("#message");
const nickNameForm = document.querySelector("#nickname");

function makeMessage(type, payload){
    return (JSON.stringify({type, payload}));
}

socket.addEventListener("open", () => {
	console.log("Connected to Server!");
});

socket.addEventListener("message", (message) => {
    const li = document.createElement("li");

    li.innerText = message.data;
    messageList.append(li);
});

socket.addEventListener("close", () => {
	console.log("Disconnected from Server!");
});

function handleMessageSubmit(event) {
    event.preventDefault();
    const input = messageForm.querySelector("input");

    socket.send(makeMessage("message", input.value));
    input.value = "";
}

function handleNickNameSubmit(event) {
    event.preventDefault();
    const input = nickNameForm.querySelector("input");

    socket.send(makeMessage("nickname", input.value));
    input.value = "";
}

messageForm.addEventListener("submit", handleMessageSubmit);
nickNameForm.addEventListener("submit",handleNickNameSubmit);