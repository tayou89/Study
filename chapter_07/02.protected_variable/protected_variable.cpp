#include "protected_variable.hpp"

Father::Father(void)
	: father_number(30), protected_number(30)
{
	std::cout << "Father void constructor is called.\n";
}

Father::Father(int a, int b)
	: father_number(a), protected_number(b)
{
	std::cout << "Father number constructor is called.\n";
}

void	Father::print_father_number(void)
{
	std::cout << "Father number: " << father_number << std::endl;
}

Father::~Father(void)
{
	std::cout << "Father destructor is called.\n";
}

Son::Son(void)
	: son_number(30)
{
	std::cout << "Son void constructor is called.\n";
}

Son::Son(int n)
	: son_number(n)
{
	std::cout << "Son number constructor is called.\n";
}

Son::Son(int a, int b, int c)
	: Father(a, b), son_number(c)
{
	std::cout << "Son double number constructor is called.\n";
}

void	Son::print_son_number(void)
{
	std::cout << "Son number: " << son_number << std::endl;
	std::cout << "Father protected_number: " << protected_number << std::endl;
	print_father_number();
}

Son::~Son(void)
{
	std::cout << "Son destructor is called.\n";
}
