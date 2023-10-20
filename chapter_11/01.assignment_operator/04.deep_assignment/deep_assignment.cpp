#include "deep_assignment.hpp"

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

Some	&Some::operator=(const Some &ref)
{
	int	name_size;

	delete []name;
	name_size = strlen(ref.name);
	name = new char[name_size + 1];
	strcpy(name, ref.name);
	age = ref.age;
	return (*this);
}

Some::~Some(void)
{
	delete []name;
}
