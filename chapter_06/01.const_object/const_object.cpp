#include "const_object.hpp"

Numbers::Numbers(int a, int b)
{
	std::cout << "Constructor is called.\n";
	number_1 = a;
	number_2 = b;
}

void	Numbers::print_variables(void)
{
	std::cout << "This is normal function.\n";
	std::cout << "number_1: " << number_1 << std::endl;
	std::cout << "number_2: " << number_2 << std::endl;
}

void	Numbers::print_variables(void) const
{
	std::cout << "This is const function.\n";
	std::cout << "number_1: " << number_1 << std::endl;
	std::cout << "number_2: " << number_2 << std::endl;
}

void	Numbers::add_numbers(Numbers &obj)
{
	obj.number_1++;
	obj.number_2++;
}

void	Numbers::add_numbers(const Numbers &obj) const
{
	obj.number_1++;
	obj.number_2++;
}

Numbers::~Numbers(void)
{
	std::cout << "Destructor is called.\n";
}
