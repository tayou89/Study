let object = Object.create(null);
console.log(Object.getPrototypeOf(object) === null);

const myProto = { x: 10 };
object = Object.create(myProto);
console.log(object.x);
console.log(Object.getPrototypeOf(object) === myProto);

const object_2 = 
{
	y: 20,
	__proto__: myProto
};

console.log(object_2.x, object_2.y);
console.log(Object.getPrototypeOf(object_2) === myProto);

function Person(name) 
{
	this.name = name;
}

Person.staticProp = 'static prop';

Person.staticMethod = function () 
{
	console.log('staticMethod');
};

const me = new Person('You');

Person.staticMethod();

me.staticMethod();


