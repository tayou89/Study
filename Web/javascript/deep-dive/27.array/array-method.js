const arr = [1, 2, 3];

function changeArray(array)
{
	array.push(1);
	console.log(`Changed array: ${array}`);
}

function unchangeArray(array)
{
	returnArray = array.concat(1);
	console.log(`Changed array: ${array}`);
	console.log(`Return array: ${returnArray}`);
}

changeArray(arr);
unchangeArray(arr);
console.log(arr);

const numbers = [1, 2, 3];
const pows = [];

numbers.forEach(item => pows.push(item ** 2));
console.log(pows);
console.log(numbers);

[1, 2, 3].forEach((item, index, arr) =>
{
	console.log(`item: ${item}, index: ${index}, this: ${JSON.stringify(arr)}`);
});

class Numbers
{
	numberArray = [];
	multiply(array)
	{
		array.forEach(function (item)
		{
			this.numberArray.push(item * item);
		}, this);
	}
}

const a = new Numbers();
a.multiply([1, 2, 3]);
console.log(a.numberArray);

class Prefixer
{
	constructor(prefix)
	{
		this.prefix = prefix;
	}

	add(array)
	{
		return (array.map(item => this.prefix + item));
	}
}

const prefixer = new Prefixer('-webkit-');

console.log(prefixer.add(['transition', 'user-select']));

class Users
{
	constructor()
	{
		this.users = [{ id: 1, name: 'Hoho' }, { id: 2, name: 'Haha' }];
	}

	findById(id)
	{
		return (this.users.filter(user => user.id === id));
	}

	remove(id)
	{
		this.users = this.users.filter(user => user.id !== id);
	}
}

const users = new Users();

let user = users.findById(1);
console.log(user);

users.remove(1);

user = users.findById(1);
console.log(user);