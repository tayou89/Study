function* generatorFunction()
{
	const x = yield 1;
	console.log(`x is ${x}`);
	const y = yield (x + 10);

	return (x + y);
}

const generator = generatorFunction(0);

console.log(generator.next());
console.log(generator.next(20));
console.log(generator.next(30));