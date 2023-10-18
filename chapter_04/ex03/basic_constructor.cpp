#include "constructor.hpp"

Constructor::Constructor(int a, int b)
{
	std::cout << "Constructor is called.\n";
	number_1 = a;
	number_2 = b;
}

void	Constructor::print_variables(void)
{
	std::cout << "number_1: " << number_1 << std::endl;
	std::cout << "number_2: " << number_2 << std::endl;
}
