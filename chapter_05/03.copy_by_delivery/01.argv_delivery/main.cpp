#include "argv_delivery.hpp"

void	change_numbers(Numbers &ref);
void	print_variables(Numbers copy);

int	main(void)
{
	Numbers	origin(10, 20);

	origin.print_variables();
	change_numbers(origin);
	print_variables(origin);
	return (0);
}

void	change_numbers(Numbers &ref)
{
	ref.change_numbers(0, 0);
}

void	print_variables(Numbers copy)
{
	copy.print_variables();
}
