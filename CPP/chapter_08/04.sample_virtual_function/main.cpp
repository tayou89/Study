#include "virtual.hpp"

int	main(void)
{
	Third	*third_pointer = new Third();
	Second	*second_pointer = third_pointer;
	First	*first_pointer = second_pointer;

	std::cout << "==================Not virtualized function================\n\n";
	first_pointer->print_class();
	second_pointer->print_class();
	third_pointer->print_class();

	Three	*three_pointer = new Three();
	Two		*two_pointer = three_pointer;
	One		*one_pointer = two_pointer;
	std::cout << "\n==================Virtualized function================\n";
	one_pointer->print_class();
	one_pointer->print_class();
	one_pointer->print_class();
	return (0);
}
