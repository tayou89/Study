#include "class_inheritance.hpp"

int	main(void)
{
	Son	son_1;
	Son	son_2(100);
	Son son_3(200, 200);

	son_1.print_son_number();
	son_2.print_son_number();
	son_3.print_son_number();
	return (0);
}
