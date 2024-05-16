console.log(x);
// console.log(y);

var x = 10;

function foo()
{
	y = 20;
}

foo();

console.log(x + y);

console.log(window.x);
console.log(window.y);

delete x;
delete y;

console.log(window.x);
console.log(window.y);