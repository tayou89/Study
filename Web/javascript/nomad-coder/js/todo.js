const toDoForm = document.getElementById("todo-form");
const toDoInput = toDoForm.querySelector("#todo-form input");
const toDoList = document.getElementById("todo-list");

const TODOS_KEY = "todos";
let toDos = [];

function saveToDos()
{
	localStorage.setItem(TODOS_KEY, JSON.stringify(toDos));
}

function deleteToDo(event)
{
	const li = event.target.parentElement;
	li.remove();
	toDos = toDos.filter(toDo => toDo.id !== parseInt(li.id));
	saveToDos();
}

function paintToDo(newToDo)
{
	const li = document.createElement("li");
	li.id = newToDo.id;
	const span = document.createElement("span");
	const button = document.createElement("button");

	span.innerText = newToDo.text;
	button.innerText = "X";
	button.addEventListener("click", deleteToDo);
	li.appendChild(span);
	li.appendChild(button);
	toDoList.appendChild(li);
}

function handleToDoSubmit(event)
{
	event.preventDefault();
	const newToDo = toDoInput.value;
	toDoInput.value = "";
	const newToDoObject =
	{
		text: newToDo,
		id: Date.now()
	};
	toDos.push(newToDoObject);
	paintToDo(newToDoObject);
	saveToDos();
}

toDoForm.addEventListener("submit", handleToDoSubmit);

const savedToDos = localStorage.getItem(TODOS_KEY);
if (savedToDos)
{
	const parsedToDos = JSON.parse(savedToDos);

	toDos = parsedToDos;
	parsedToDos.forEach(paintToDo);
}