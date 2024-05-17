const mySymbol = Symbol();

console.log(typeof mySymbol);
console.log(mySymbol);

const s1 = Symbol.for('mySymbol');
const s2 = Symbol.for('mySymbol');

console.log(s1 === s2);
console.log(Symbol.keyFor(s1));

const obj = 
{
	[Symbol.for('mySymbol')]: 1
};

console.log(obj[Symbol.for('mySymbol')]);

Array.prototype[Symbol.for('sum')] = function () 
{
	return (this.reduce((acc, cur) => acc + cur, 0));
};

console.log([1, 2, 3][Symbol.for('sum')]());
