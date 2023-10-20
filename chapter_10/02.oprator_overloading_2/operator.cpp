#include "operator.hpp"

Some::Some(int n)
	: number(n)
{
}

void	Some::print_number(void)
{
	std::cout << "number: " << number << std::endl;
}

Some	operator+(const Some &origin, const Some &other)
{
	Some	result(origin.number + other.number);
	
	return (result);
}
