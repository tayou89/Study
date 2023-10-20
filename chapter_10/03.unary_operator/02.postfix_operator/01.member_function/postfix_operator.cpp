#include "postfix_operator.hpp"

Some::Some(int number_1, int number_2)
	: x(number_1), y(number_2)
{
}

const Some	Some::operator++(int)
{
	Some	copy(x, y);

	x += 1;
	y += 1;
	return (copy);
}

void	Some::print_number(void)
{
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
}

void	Some::print_number(void) const
{
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
}
