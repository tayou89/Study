function* generatorFunction()
{
	yield 1;
	yield 2;
	yield 3;
}

const generator = generatorFunction();

console.log(Symbol.iterator in generator);
console.log('next' in generator);