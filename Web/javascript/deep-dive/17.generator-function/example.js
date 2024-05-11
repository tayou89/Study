const stringObject = new String('You');
console.log(typeof(stringObject));
console.log(stringObject);

function Circle(radius)
{
	this.radius = radius;
	this.getDiameter = function () 
	{
		return (2 * this.radius);
	};
}

const circle1 = new Circle(5);
const circle2 = new Circle(10);

console.log(circle1.getDiameter());
console.log(circle2.getDiameter());

function foo() 
{
	console.log(this);
}

foo();

const obj = { foo };

obj.foo();

const instance = new foo();