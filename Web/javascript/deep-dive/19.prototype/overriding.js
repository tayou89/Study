const Person = (function() 
{
	function Person(name)
	{
		this.name = name;
	}
	Person.prototype.sayHello = function ()
	{
		console.log(`Hi! My name is ${this.name}`);
	}
	return Person;
}());

const me = new Person('You');


me.sayHello = function()
{
	console.log(`Hey! My name is ${this.name}`);
};

me.sayHello();

delete me.sayHello;
me.sayHello();
delete me.sayHello;
me.sayHello();

delete Person.prototype.sayHello;
// me.sayHello();

console.log(me instanceof Person);
console.log(me instanceof Object);
