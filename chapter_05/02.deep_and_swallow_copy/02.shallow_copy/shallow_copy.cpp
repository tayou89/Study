#include "shallow_copy.hpp"

Person::Person(const char *string, int number)
{
	int	string_size;

	std::cout << "Constructor is called.\n";
	string_size = strlen(string);
	name = new char[string_size + 1];
	strcpy(name, string);
	age = number;
}

void	Person::print_variables(void)
{
	std::cout << (void *) name << std::endl;
	std::cout << "name: " << name << std::endl;
	std::cout << "age: " << age << std::endl;
}

Person::~Person(void)
{
	std::cout << "Destructor is called.\n";
	delete []name;
}
