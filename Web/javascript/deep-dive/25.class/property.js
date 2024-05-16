const person = 
{
	firstName: 'Taegab',
	lastName: 'You',
	get fullName()
	{
		return (`${this.firstName} ${this.lastName}`);
	},
	set fullName(name)
	{
		[this.firstName, this.lastName] = name.split(' ');
	}
};

console.log(`${person.firstName} ${person.lastName}`);
person.fullName = 'Haha Ha';
console.log(person);

console.log(person.fullName);

console.log(Object.getOwnPropertyDescriptor(person, 'fullName'));

class Person
{
	constructor(firstName, lastName)
	{
		this.firstName = firstName;
		this.lastName = lastName;
	}

	get fullName()
	{
		return (`${this.firstName} ${this.lastName}`);
	}

	set fullName(name)
	{
		[this.firstName, this.lastName] = name.split(' ');
	}
}

const me = new Person('Taegab', 'You');

console.log(`${me.firstName} ${me.lastName}`);

me.fullName = 'Haha Ha';
console.log(me);

console.log(me.fullName);

console.log(Object.getOwnPropertyDescriptor(Person.prototype, 'fullName'));

console.log(Object.getOwnPropertyNames(me));

console.log(Object.getOwnPropertyNames(Object.getPrototypeOf(me)));