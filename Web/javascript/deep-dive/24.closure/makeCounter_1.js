function makeCounter(aux)
{
	let counter = 0;

	return (function ()
	{
		counter = aux(counter);
		return (counter);
	});
}

function increase(number)
{
	return (++number);
}

function decrease(number)
{
	return (--number);
}

const increaser = makeCounter(increase);
console.log(increaser());
console.log(increaser());

const decreaser = makeCounter(decrease);
console.log(decreaser());
console.log(decreaser());