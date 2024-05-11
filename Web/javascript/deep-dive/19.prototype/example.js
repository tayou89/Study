function Circle(radius)
{
	this.radius = radius;
}

Circle.prototype.getArea = function ()
{
	return Math.PI * this.radius ** 2;
};

const circle1 = new Circle(1);
const circle2 = new Circle(2);

console.log(circle1.getArea === circle2.getArea);

console.log(circle1.getArea());
console.log(circle2.getArea());

const obj = {};
const parent = { x: 1 };

Object.getPrototypeOf(obj);
Object.setPrototypeOf(obj, parent);

console.log(obj.x);

function Person(name)
{
	this.name = name;
}

const me = new Person('You');
console.log(Person.prototype === me.__proto__);
