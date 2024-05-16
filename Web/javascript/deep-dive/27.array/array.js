const arr = [];

console.time('Array Performance Test');

for (let i = 0; i < 10000000; i++)
	arr[i] = i;

console.timeEnd('Array Performance Test');

const object = {};

console.time('Object Performance Test');

for (let i = 0; i < 10000000; i++)
	object[i] = i;

console.timeEnd('Object Performance Test');