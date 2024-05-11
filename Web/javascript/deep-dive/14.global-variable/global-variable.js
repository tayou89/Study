var x = 'global';

function foo()
{
	console.log(x);
	var x = 'local';
}

foo();
console.log(x);

//Module pattern

var Counter = (function() {
	var number = 0;

	return {
		increase() 
		{
			return ++number;
		},
		decrease()
		{
			return --number;
		}
	};
}());

console.log(Counter.number);
console.log(Counter.increase());
console.log(Counter.increase());
console.log(Counter.decrease());
console.log(Counter.decrease());