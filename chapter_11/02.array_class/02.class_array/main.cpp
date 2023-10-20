#include "class_array.hpp"

int	main(void)
{
	BoundCheckArray	array(3);

	for (int i = 0; i < 3; i++)
		array[i] = new Some((i + 1) * 10);
	array.print_array_data();
	for (int i = 0; i < 3; i++)
		delete array[i];
	return (0);
}
