function* generatorFunction()
{
	yield 1;
	yield 2;
	yield 3;
}

const generator = generatorFunction();

console.log(generator.next());
console.log(generator.next());
console.log(generator.next());
console.log(generator.next());