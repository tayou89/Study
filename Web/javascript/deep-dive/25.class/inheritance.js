class Animal
{
	constructor(age, weight)
	{
		this.age = age;
		this.weight = weight;
	}

	eat() { return ('eat') };

	move() { return ('move') };
}

class Bird extends Animal
{
	fly() { return ('fly') };
}

const bird = new Bird(1, 5);

console.log(bird);

console.log(bird instanceof Bird);
console.log(bird instanceof Animal);

console.log(bird.eat());
console.log(bird.move());
console.log(bird.fly());


class Base 
{
	constructor(a, b)
	{
		this.a = a;
		this.b = b;
	}
}

class Derived extends Base
{
	constructor(a, b, c)
	{
		super(a, b);
		this.c = c;
	}
}

const derived = new Derived(1, 2, 3);
console.log(derived);