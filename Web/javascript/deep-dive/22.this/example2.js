function Person(name)
{
	this.name = name;
}

Person.prototype.getName = function()
{
	return (this.name);
};

const me = new Person('You');

console.log(me.getName());

Person.prototype.name = 'Kim';

console.log(Person.prototype.getName());
console.log(me.getName());

function getThisBinding()
{
	console.log(arguments);
	return (this);
}

const thisArg = { a: 1};

console.log(getThisBinding());

console.log(getThisBinding.apply(thisArg, [1, 2, 3]));
console.log(getThisBinding.call(thisArg, 1, 2, 3));

const person = 
{
	name: 'You',
	foo(callback)
	{
		setTimeout(callback.bind(this), 100);
	}
};

person.foo(function() 
{
	console.log(`Hi! my name is ${this.name}.`);
});