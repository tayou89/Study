function* generatorFunction() 
{
	try
	{
		yield 1;
		yield 2;
		yield 3;
	}
	catch (e)
	{
		console.log(e);
	}
}

const generator = generatorFunction();

console.log(generator.next());
// console.log(generator.return('End!'));
console.log(generator.throw('Error!'));