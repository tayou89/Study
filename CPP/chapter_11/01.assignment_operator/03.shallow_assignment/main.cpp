#include "shallow_assignment.hpp"

int	main(void)
{
	Some	obj_1("Tom", 4);
	Some	obj_2("Bread", 20);

	std::cout << "==================obj_1===================\n";
	obj_1.print_data();
	std::cout << "==================obj_2===================\n";
	obj_2.print_data();
	obj_2 = obj_1;
	std::cout << "==================obj_1===================\n";
	obj_1.print_data();
	std::cout << "==================obj_2===================\n";
	obj_2.print_data();
	return (0);
}
