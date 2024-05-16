function foo()
{
	const x = 1;
	const y = 2;

	function bar() 
	{
		const z = 3;
		console.log(x);
	}
	return (bar);
}

const bar = foo();
bar();

const increase = (function () 
{
	let number = 0;

	return (function () 
	{
		return (++number);
	});
}());

console.log(increase());
console.log(increase());
console.log(increase());
console.log(increase());