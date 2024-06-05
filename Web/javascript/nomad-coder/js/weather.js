const API_KEY = "2448130c464bfc8fb797d28b21fafa26";

function onGeoOk(position)
{
	console.log(position);
}

function onGeoError()
{
	const lat = 37.4905;
	const lon = 127.0639;
	const url = `https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lon}&appid=${API_KEY}&units=metric`;
	fetch(url).then(response => response.json()).then(data => 
		{ 
			const weather = document.querySelector("#weather span:first-child");
			const city = document.querySelector("#weather span:last-child");

			weather.innerText = data.weather[0].main;
			city.innerText = data.name;
		});
}

navigator.geolocation.getCurrentPosition(onGeoOk, onGeoError);