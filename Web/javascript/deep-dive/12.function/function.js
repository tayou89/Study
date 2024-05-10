var add = function foo (x, y)
{
	return x + y;
};

console.log(add(3, 4));

console.dir(add_2);
console.dir(sub);

console.log(add_2(2, 5));
// console.log(sub(2, 5));

function add_2(x, y)
{
	return (x + y);
};

var sub = function (x, y)
{
	return (x - y);
};

function add_3(x, y)
{
	console.log(arguments);
	return (x + y);
}
add_3(2, 5, 10);

function add_4(x, y)
{
	if (typeof x !== 'number' || typeof y !== 'number')
		throw new TypeError('Arguments must be a number.');
	return (x + y);
};

// console.log(add_4(2));
//console.log(add_4('a', 'b'));
console.log(add_4(2, 4));

function add_5(a = 0, b = 0, c = 0)
{
	return (a + b + c);
};

console.log(add_5(1, 2, 3));
console.log(add_5(1, 2));
console.log(add_5(1));
console.log(add_5());

function changeVal(primitive, object)
{
	primitive += 100;
	object.name = 'Kim';
};

var number = 100;
var person = { name: 'Lee' };

console.log(number);
console.log(person);

changeVal(number, person);

console.log(number);
console.log(person);

(function foo() 
{
	var a = 3;
	var b = 5;
	return (a + b);
}());

result = (function (a, b)
{
	return (a + b);
}(3, 5));

console.log(result);

var factorial = function poo(number)
{
	if (number <= 1) 
		return (1);
	return (number + poo(number - 1));
};

console.log(factorial(5));
console.log(factorial(3));
// console.log(foo(3));

function repeat(number, f)
{
	for (var i = 0; i < number; i++)
		f(i);
};

var logAll = function (i)
{
	console.log(i);
};

repeat(5, logAll);

var logOdds = function (i)
{
	if (i % 2)
		console.log(i);
};

repeat(5, logOdds);

console.log('=================Scope Test===================');

var x = 1;

function foo()
{
	var x = 10;
	bar();
};

function bar()
{
	console.log(x);
};


foo();
bar();