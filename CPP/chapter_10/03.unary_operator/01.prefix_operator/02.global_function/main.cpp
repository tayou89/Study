#include "prefix_operator.hpp"

int	main(void)
{
	Some	origin(3, 4);

	origin.print_number();
	++origin;
	std::cout << "variables are incremented.\n";
	origin.print_number();
	++(++origin);
	std::cout << "variables are twice incremented.\n";
	origin.print_number();
	return (0);
}
