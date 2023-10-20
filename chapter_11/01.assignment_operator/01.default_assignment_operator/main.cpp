#include "default_assignment.hpp"

int	main(void)
{
	Some	obj_1(3, 4);
	Some	obj_2(10, 20);

	std::cout << "=============obj_1================\n";
	obj_1.print_number();
	std::cout << "=============obj_2================\n";
	obj_2.print_number();
	obj_2 = obj_1;
	std::cout << "=============obj_1================\n";
	obj_1.print_number();
	std::cout << "=============obj_2================\n";
	obj_2.print_number();
	return (0);
}
