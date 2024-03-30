#include "smart_pointer.hpp"

int	main(void)
{
	SmartPointer	pointer(new Some(3, 4));

	
	pointer->set_variables(10, 20);
	return (0);
}
