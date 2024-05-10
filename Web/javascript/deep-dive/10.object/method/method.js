var circle = 
{
	radius: 5,
	getDiameter: function () 
	{
		return 2 * this.radius;
	}
};

console.log(circle.getDiameter());

var person = 
{
	name: 'Lee',
};

console.log(person.name);
console.log(person['name']);

var person = 
{
	'last-name': 'Lee',
	1: 10
};

console.log(person.last-name);

var person = 
{
	name: 'Lee',
};

person.age = 20;
console.log(person);
delete person.age;
delete person.address;
console.log(person);

var x = 1;
var y = 2;

var object =
{
	x: x,
	y: y
};

console.log(object);

const object_2 = {x, y};
console.log(object_2);

var prefix = 'prop';
var i = 0;

var object = {};

object[prefix + '-' + ++i] = i;
object[prefix + '-' + ++i] = i;
object[prefix + '-' + ++i] = i;

console.log(object);

var object = 
{
	[`${prefix}-${++i}`]: i,
	[`${prefix}-${++i}`]: i,
	[`${prefix}-${++i}`]: i,
};

console.log(object);

//ES6

var object = 
{
	name: 'Lee',
	sayHi() 
	{
		console.log('Hi' + this.name);
	}
};

object.sayHi();