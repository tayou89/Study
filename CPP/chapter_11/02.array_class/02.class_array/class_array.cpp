#include "class_array.hpp"

Some::Some(int n)
	: number(n)
{
}
void	Some::print_number(void)
{
	std::cout << "number: " << number << std::endl;
}

BoundCheckArray::BoundCheckArray(int size)
	: array_size(size)
{
	class_array = new Some *[size];
}

Some	*&BoundCheckArray::operator[](int index)
{
	if (index < 0 || index >= array_size)
	{
		std::cout << "Index is out of array boundary.\n";
		exit(0);
	}
	return (class_array[index]);
}

void	BoundCheckArray::print_array_data(void)
{
	for (int i = 0; i < array_size; i++)
	{
		std::cout << "class_array[" << i << "]: ";
		class_array[i]->print_number();
	}
}


BoundCheckArray::~BoundCheckArray(void)
{
	delete []class_array;
}
