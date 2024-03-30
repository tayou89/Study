#include "copy_constructor.hpp"

Abc::Abc(int number_1, int number_2)
{
	std::cout << "Abc constructor is called.\n";
	this->number_1 = number_1;
	this->number_2 = number_2;
}

void	Abc::print_variables(void)
{
	std::cout << "number_1: " << number_1 << std::endl;
	std::cout << "number_2: " << number_2 << std::endl;
}

Abc::~Abc(void)
{
	std::cout << "Abc destructor is called.\n";
}
