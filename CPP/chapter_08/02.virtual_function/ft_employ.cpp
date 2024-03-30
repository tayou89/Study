#include "is_a_heritance.hpp"

Employee::Employee(const char *name)
{
	int	name_size;

	name_size = strlen(name);
	this->name = new char[name_size];
	strcpy(this->name, name);
}

void	Employee::print_name(void) const
{
	std::cout << "Name: " << name << std::endl;
}

Employee::~Employee(void)
{
	delete []name;
}
