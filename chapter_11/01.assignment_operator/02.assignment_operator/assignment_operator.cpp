#include "assignment_operator.hpp"

Some::Some(int number_1, int number_2)
	: x(number_1), y(number_2)
{
}

void	Some::print_number(void)
{
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
}

Some	&Some::operator=(const Some &ref)
{
	std::cout << "operator function is called.\n";
	x = ref.x;
	y = ref.y;
	return (*this);
}
