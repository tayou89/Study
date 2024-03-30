#include "array_class.hpp"

int	main(void)
{
	BoundCheckArray	array(3);
	int				number;

	for (int i = 0; i < 3; i++)
		array[i] = (i + 1) * 10;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "index: " << i << std::endl;
		std::cout << "array[" << i << "]: " << array[i] << std::endl;
	}
	number = array[2];
	std::cout << "number: " << number << std::endl;
	return (0);
}
