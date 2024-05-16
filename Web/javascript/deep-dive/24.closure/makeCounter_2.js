const counter = (function () 
{
	let counter = 0;

	return (function (aux)
	{
		counter = aux(counter);
		return (counter);
	});
}());

function increase(number)
{
	return (++number);
}

function decrease(number)
{
	return (--number);
}

console.log(counter(increase));
console.log(counter(increase));

console.log(counter(decrease));
console.log(counter(decrease));