const { odd, even } = require('./var');
const checkNumber = require('./func');

function checkStringOddOrEven(string) {
	if (string.length % 2)
		return (odd);
	else
		return (even);
}

console.log(checkNumber(10));
console.log(checkStringOddOrEven('hello'));