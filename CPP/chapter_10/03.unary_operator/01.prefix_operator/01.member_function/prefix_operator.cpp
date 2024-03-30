#include "prefix_operator.hpp"

Some::Some(int number_1, int number_2)
	: x(number_1), y(number_2)
{
}

Some	&Some::operator++(void)
{
	x++;
	y++;
	return (*this);
}

void	Some::print_number(void)
{
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
}
