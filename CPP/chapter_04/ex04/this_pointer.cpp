#include "this_pointer.hpp"

SelfRef::SelfRef(int a)
{
	std::cout << "Constructor is called.\n";
	number = a;
}

void	SelfRef::print_variables(void)
{
	std::cout << "number: " << number << std::endl;
	std::cout << "address: " << this << std::endl;
}

SelfRef::~SelfRef(void)
{
	std::cout << "Desconstructor is called.\n";
}

SelfRef	&SelfRef::increase_number(void)
{
	number++;
	return (*this);
}

SelfRef	&SelfRef::print_number(void)
{
	std::cout << "number: " << number << std::endl;
	return (*this);
}
