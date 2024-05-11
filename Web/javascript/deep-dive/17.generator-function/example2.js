function foo() {}

const bar = function () {};

const baz = 
{
	x: function() {}
};

new foo();
new bar();
new baz.x();

const arrow = () => {};

// new arrow();

const obj = 
{
	x() {}
};

// new obj.x();

function add(x, y)
{
	return (x + y);
}

let instance = new add();
console.log(instance);

function createUser(name, role) 
{
	return {name, role};
}

instance = new createUser('You', 'admin');
console.log(instance);

function Circle(radius) 
{
	this.radius = radius;
	this.getDiameter = function () 
	{
		return (2 * this.radius);
	};
}

const circle = Circle(5);
console.log(circle);

console.log(radius);
console.log(getDiameter());

// console.log(circle.getDiameter());