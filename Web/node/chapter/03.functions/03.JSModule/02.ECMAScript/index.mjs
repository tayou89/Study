import { odd, even } from './var.mjs';
import checkNumber from './func.mjs';

function checkStringOddOrEven(string) {
	if (string.length % 2)
		return (odd);
	else
		return (even);
}

console.log(checkNumber(10));
console.log(checkStringOddOrEven('hello'));