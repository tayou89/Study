// 1. String concatenation
console.log('my' + ' cat');
console.log('1' + 2);
console.log(`string literals:     

''''
1 + 2 = ${1 + 2}`)

console.log("ellie's \n\tbook");

//2. Numeric operator
console.log(1 + 1);
console.log(1 - 1);
console.log(1 / 1);
console.log(1 * 1);
console.log(5 % 2);
console.log(2 ** 3);

//3. increment and decrement operator
let counter = 2;
const preIncrement = ++counter;
console.log(`preIncrement: ${preIncrement}, counter: ${counter}`)
const postIncrement = counter++;
console.log(`preIncrement: ${preIncrement}, counter: ${counter}`)

const preDecrement = --counter;
console.log(`preIncrement: ${preIncrement}, counter: ${counter}`)
const postDecrement = counter--;
console.log(`preIncrement: ${preIncrement}, counter: ${counter}`)

//4. Logical operator
const value1 = true;
const value2 = 4 < 2;

console.log(`or: ${value1 || value2 || check()}`);
console.log(`or: ${value1 && value2 && check()}`);

function check()
{
	for (let i = 0; i < 10; i++)
		console.log('');
	return true;
}

console.log(!value1);