#include "polymorphism.hpp"

int	main(void)
{
	First	*first = new First();
	First	*second = new Second();

	first->print();
	second->print();
	delete first;
	delete second;
	return (0);
}
