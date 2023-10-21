#include "new_operator.hpp"

Some::Some(int n)
	: number(n)
{
	std::cout << "Object is constructed.\n";
}

void	*Some::operator new (size_t size)
{
	void	*address;

	std::cout << "New operator function is called.\n";
	std::cout << "Memory allocating size: " <<  size << std::endl;
	address = new char[size];
	return (address);
}

void	Some::operator delete (void *address)
{
	char	*copy_address;

	std::cout << "Delete operator function is called.\n";
	copy_address = (char *) address;
	delete []copy_address;
}

void	Some::print_number(void)
{
	std::cout << "number: " << number << std::endl;
}
