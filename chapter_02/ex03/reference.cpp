#include <iostream>

void	change_number(int number);

int	main(void)
{
	int	number;
	int	&reference_number = number;

	number = 10;
	std::cout << "number: " << number << std::endl;
	std::cout << "reference_number: " << reference_number << std::endl;
	reference_number = 20;
	std::cout << "number: " << number << std::endl;
	std::cout << "reference_number: " << reference_number << std::endl;
	std::cout << "number address: " << &number << std::endl;
	std::cout << "reference_number address: " << &reference_number << std::endl;
	return (0);
}
