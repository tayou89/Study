#include "deep_copy.hpp"

Person::Person(const char *string, int number)
{
	int	string_size;

	std::cout << "Constructor is called.\n";
	string_size = strlen(string);
	name = new char[string_size + 1];
	strcpy(name, string);
	age = number;
}

Person::Person(const Person &a)
	: age(a.age)
{
	int	name_size;

	std::cout << "Copy constructor is called.\n";
	name_size = strlen(a.name);
	name = new char[name_size + 1];
	strcpy(name, a.name);
}

void	Person::print_variables(void)
{
	std::cout << &name << std::endl;
	std::cout << "name: " << name << std::endl;
	std::cout << "age: " << age << std::endl;
}

Person::~Person(void)
{
	std::cout << "Destructor is called.\n";
	delete []name;
}
