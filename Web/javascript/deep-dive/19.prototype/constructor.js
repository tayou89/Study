const obj = new Object();
console.log(obj.constructor === Object);

console.log(Person.prototype);

function Person(name)
{
	this.name = name;
}

const me = new Person('You');

console.log(Object.getPrototypeOf(me) === Person.prototype);
console.log(Object.getPrototypeOf(Person.prototype) === Object.prototype);
