#include "argv_delivery.hpp"

Numbers::Numbers(int a, int b)
{
	std::cout << "Constructor is called.\n";
	number_1 = a;
	number_2 = b;
}

Numbers::Numbers(const Numbers &object)
{
	std::cout << "Copy constructor is called.\n";
	number_1 = object.number_1;
	number_2 = object.number_2;
}

void	Numbers::change_numbers(int a, int b)
{
	number_1 = a;
	number_2 = b;
}

void	Numbers::print_variables(void)
{
	std::cout << "number_1: " << number_1 << std::endl;
	std::cout << "number_2: " << number_2 << std::endl;
}

Numbers::~Numbers(void)
{
	std::cout << "Destructor is called.\n";
}
