#include "shallow_assignment.hpp"

Some::Some(const char *string, int number)
	: age(number)
{
	int	name_size;

	name_size = strlen(string);
	name = new char[name_size + 1];
	strcpy(name, string);
}

void	Some::print_data(void)
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << age << std::endl;
}

Some::~Some(void)
{
	delete []name;
}
