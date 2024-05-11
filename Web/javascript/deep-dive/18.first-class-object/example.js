function square(number)
{
	return (number * number);
}

console.dir(square);

console.log(Object.getOwnPropertyDescriptors(square));
console.log(Object.getOwnPropertyDescriptor(square), '__proto__');

function multiply(x, y)
{
	console.log(arguments);
	const iterator = arguments[Symbol.iterator]();
	console.log(iterator.next());
	console.log(iterator.next());
	console.log(iterator.next());
	console.log(iterator.next());
	return (x + y);
}

console.log(multiply());
console.log(multiply(1));
console.log(multiply(1, 2));
console.log(multiply(1, 2, 3));

function sum()
{
	let result = 0;
	for (let i = 0; i < arguments.length; i++)
		result += arguments[i];
	return (result);
}

console.log(sum());
console.log(sum(1, 2));
console.log(sum(1, 2, 3));

function foo(func)
{
	return (func());
}

function bar() 
{
	return 'caller: ' + bar.caller;
}

console.log(foo(bar));
console.log(bar());