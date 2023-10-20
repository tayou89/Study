#include "copy_constructor.hpp"

int	main(void)
{
	Abc	obj_1(10,20);
	Abc obj_2 = obj_1;

	obj_1.print_variables();
	obj_2.print_variables();
	return (0);
}
