const o = {};

o.__proto__

const person = {
	name: 'Lee'
};

person.age = 20;

console.log(Object.getOwnPropertyDescriptor(person, 'name'));
console.log(Object.getOwnPropertyDescriptor(person, 'age'));

const human = {
	firstName: 'Taegab', 
	lastName: 'You',

	get fullName() {
		return `${this.firstName} ${this.lastName}`;
	},
	set fullName(name) {
		[this.firstName, this.lastName] = name.split(' ');
	}
};

console.log(human.firstName + ' ' + human.lastName);
human.fullName = 'Heegun Lee';
console.log(human);
console.log(human.fullName);

let descriptor = Object.getOwnPropertyDescriptor(human, 'firstName');
console.log(descriptor);

descriptor = Object.getOwnPropertyDescriptor(human, 'fullName');
console.log(descriptor);

Object.getOwnPropertyDescriptor(Object.prototype, '__proto__');
Object.getOwnPropertyDescriptor(function() {}, 'prototype');

const person_2 = {};

Object.defineProperty(person_2, 'firstName', {
	value: 'Taegab',
	writable: true,
	enumerable: true,
	configurable: true
});

Object.defineProperty(person_2, 'lastName', {
	value: 'Lee'
});

descriptor  = Object.getOwnPropertyDescriptor(person_2, 'firstName');
console.log('firstName', descriptor);

descriptor = Object.getOwnPropertyDescriptor(person_2, 'lastName');
console.log('lastName', descriptor);
console.log(Object.keys(person_2));

person_2.lastName = 'You';
delete person_2.lastName;

descriptor = Object.getOwnPropertyDescriptor(person_2, 'lastName');
console.log('lastName', descriptor);

Object.defineProperty(person_2, 'fullName', {
	get() {
		return `${this.firstName} ${this.lastName}`;
	},
	set(name) {
		[this.firstName, this.lastName] = name.split(' ');
	},
	enumerable: true,
	configurable: true
});

descriptor = Object.getOwnPropertyDescriptor(person_2, 'fullName');
console.log('fullName', descriptor);

person_2.fullName = 'Heegun Lee';
console.log(person_2);