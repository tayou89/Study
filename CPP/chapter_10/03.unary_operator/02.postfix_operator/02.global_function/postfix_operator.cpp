#include "postfix_operator.hpp"

Some::Some(int number_1, int number_2)
	: x(number_1), y(number_2)
{
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

const Some	operator++(Some &ref, int)
{
	Some	copy(ref.x, ref.y);

	ref.x += 1;
	ref.y += 1;
	return (copy);
}
