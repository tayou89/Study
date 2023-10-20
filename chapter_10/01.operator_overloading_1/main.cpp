#include "operator.hpp"

int	main(void)
{
	Some	origin(3);
	Some	other(5);
	Some	sum = origin + other;

	origin.print_number();
	other.print_number();
	sum.print_number();
	return (0);
}
