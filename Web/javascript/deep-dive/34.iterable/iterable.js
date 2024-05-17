const array = [1, 2, 3];

const iterator = array[Symbol.iterator]();

console.log(iterator);
console.log('next' in iterator);
console.log(iterator.next());
console.log(iterator.next());
console.log(iterator.next());
console.log(iterator.next());

for (const item of array)
{
	console.log(item);
}

const fibonacciFunction = function (max)
{
	let [pre, cur] = [0, 1];
	
	return { 
		[Symbol.iterator]() { return  this; }, 
		next() 
		{ 
			[pre, cur] = [cur, pre + cur];
			return { value: cur, done: cur >= max};
		}
	};
};

let iter = fibonacciFunction(10);

for (const number of iter)
{
	console.log(number);
}

iter = fibonacciFunction(10);

console.log(iter.next());
console.log(iter.next());
console.log(iter.next());
console.log(iter.next());
console.log(iter.next());
console.log(iter.next());