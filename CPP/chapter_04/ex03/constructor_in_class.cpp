#include "constructor_in_class.hpp"

Other::Other(int a, int b)
{
	std::cout << "Class Other constructor is called.\n";
	x = a;
	y = b;
}

void	Other::print_variables(void)
{
	std::cout << "Class Other x: " << x << std::endl;
	std::cout << "Class Other y: " << y << std::endl;
}

Other::~Other(void)
{
	std::cout << "Class Other destructor is called.\n";
}

Origin::Origin(int a, int b, int c, int d)
	: other_class_1(a, b), other_class_2(c, d)
{
	std::cout << "Class Origin constructor is called.\n";
}

void	Origin::print_variables(void)
{
	other_class_1.print_variables();
	other_class_2.print_variables();
}

Origin::~Origin(void)
{
	std::cout << "Class Origin constructor is called.\n";
}
