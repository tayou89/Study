#include "new_operator.hpp"

int	main(void)
{
	Some	*address = new Some(3);

	delete address;
	return (0);
}
