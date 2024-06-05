const wrapper = document.querySelector(".wrapper");

const addWelcome = () => 
{
	const div = `
		<div class="hello">
			<h1 class="title">Hello</h1>
		</div>
	`;
	wrapper.innerHTML = div;
};

setTimeout(addWelcome, 2000);