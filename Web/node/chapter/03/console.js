const string = 'abc';
const number = 1;
const boolean = true;
const object = {
	outside: {
		inside: {
			key: 'value',
		},
	},
};

console.time("Total time");
console.log("This is common log");
console.log(string, number, boolean);
