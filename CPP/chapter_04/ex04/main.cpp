#include "this_pointer.hpp"

int	main(void)
{
	SelfRef	obj(3);

	obj.print_variables();

	SelfRef	&ref = obj.increase_number();
	ref.print_number().increase_number().print_number().increase_number().print_number();
	return (0);
}
