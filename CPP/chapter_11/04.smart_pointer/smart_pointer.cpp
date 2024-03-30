#include "smart_pointer.cpp"

Some::Some(int number_1, int number_2)
	: x(number_1), y(number_2)
{
	std::cout << "Some object is constructed.\n";
}

void	Some::set_variables(int number_1, int number_2)
{
	x = number_1;
	y = number_2;
}

Some::~Some(void)
{
	std::cout << "Some object is destructed.\n";
}

SmartPointer::SmartPointer(Some *some)
	: obj(some)
{
}

Some	&SmartPointer::operator*(void) const
{
	return (*obj);
}

Some	*SmartPointer::operator->(void) const
{
	return (obj);
}

SmartPointer::~SmartPointer(void)
{
	delete obj;
}
