#include "operator.hpp"

Some::Some(int n)
	: number(n)
{
}

Some	Some::operator+(const Some &other)
{
	Some	result(number + other.number);

	return (result);
}

void	Some::print_number(void)
{
	std::cout << "number: " << number << std::endl;
}
