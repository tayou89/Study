#include "array_class.hpp"

BoundCheckArray::BoundCheckArray(int size)
	: array_size(size)
{
	array = new int[size];
}

int	&BoundCheckArray::operator[](int index)
{
	if (index < 0 || index >= array_size)
	{
		std::cout << "Index is out of array boundary.\n";
		exit(0);
	}
	return array[index];
}

void	BoundCheckArray::print_array(void)
{
	for (int i = 0; i < array_size; i++)
		std::cout << "array[" << i << "]:" << array[i] << std::endl;
	std::cout << "array size: " << array_size << std::endl;
}

BoundCheckArray::~BoundCheckArray(void)
{
	delete []array;
}
