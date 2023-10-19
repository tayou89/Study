#include "const_object.hpp"

int	main(void)
{
	Numbers			obj_1(10, 10);
	const Numbers	obj_2(20, 20);

	obj_1.print_variables();
	obj_1.add_numbers(obj_1);
	obj_2.print_variables();
	obj_2.add_numbers(obj_2);
	return (0);
}
