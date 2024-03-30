#include "shallow_copy.hpp"

int	main(void)
{
	Person tom("Tom", 19);
	Person copy_tom = tom;

	tom.print_variables();
	copy_tom.print_variables();
	return (0);
}
