#include "static_function.hpp"

int	Numbers::private_static = 0;
int	Numbers::public_static = 0;

int	main(void)
{
	Numbers	obj_1(0);
	Numbers	obj_2(0);
	Other	other(10);

	obj_1.print_variables();
	other.print_variables();
	obj_1.add_number();
	obj_1.print_variables();
	obj_2.add_number();
	obj_2.print_variables();
	other.add_number();
	other.print_variables();
	return (0);
}
