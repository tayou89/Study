class Person
{
	constructor(name)
	{
		this.name = name;
	}
	sayHi() 
	{
		console.log(`Hi! My name is ${this.name}`);
	}
}

const me = new Person('Taegab');

me.sayHi();

console.log(Object.getPrototypeOf(me) === Person.prototype);
console.log(me instanceof Person);