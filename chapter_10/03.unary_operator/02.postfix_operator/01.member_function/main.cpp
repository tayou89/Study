#include "postfix_operator.hpp"

int	main(void)
{
	Some	origin(3, 4);

	(origin++).print_number();
	std::cout << "variables are incremented.\n";
	origin.print_number();
	return (0);
}
