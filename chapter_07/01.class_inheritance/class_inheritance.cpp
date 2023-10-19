#include "class_inheritance.hpp"

Father::Father(void)
	: number(30)
{
	std::cout << "Father void constructor is called.\n";
}

Father::Father(int n)
	: number(n)
{
	std::cout << "Father number constructor is called.\n";
}

void	Father::print_father_number(void)
{
	std::cout << "Father number: " << number << std::endl;
}

Father::~Father(void)
{
	std::cout << "Father destructor is called.\n";
}

Son::Son(void)
	: number(30)
{
	std::cout << "Son void constructor is called.\n";
}

Son::Son(int n)
	: number(n)
{
	std::cout << "Son number constructor is called.\n";
}

Son::Son(int a, int b)
	: Father(b), number(a)
{
	std::cout << "Son double number constructor is called.\n";
}

void	Son::print_son_number(void)
{
	std::cout << "Son number: " << number << std::endl;
	print_father_number();
}

Son::~Son(void)
{
	std::cout << "Son destructor is called.\n";
}
