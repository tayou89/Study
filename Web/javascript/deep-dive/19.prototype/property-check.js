const person =
{
	name: 'You',
	address: 'Seoul',
	__proto__: { age: 20 }
};

console.log('name' in person);
console.log('address' in person);
console.log('age' in person);

console.log(Reflect.has(person, 'name'));
console.log(Reflect.has(person, 'age'));

for (const key in person)
{
	console.log(key + ': ' + person[key]);
}

console.log(Object.keys(person));
console.log(Object.values(person));
console.log(Object.entries(person));
