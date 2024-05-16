const sum = [1, 2, 3, 4].reduce((accumulator, currentValue, index, array) => accumulator + currentValue, 0);

console.log(sum);

const arr = ['hello', 'world'];

console.log(arr.map(x => x.split('')).flat());

console.log(arr.flatMap(x => x.split('')));

