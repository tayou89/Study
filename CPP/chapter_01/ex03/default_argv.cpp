#include <iostream>

void	print_numbers(int number_1 = 9, int number_2 = 8, int number_3 = 7);
int	main(void)
{
	print_numbers(1);
	print_numbers(1, 2);
	print_numbers(1, 2, 3);
	return (0);
}

void	print_numbers(int number_1, int number_2, int number_3)
{
	std::cout << "number_1: " << number_1 << std::endl;
	std::cout << "number_2: " << number_2 << std::endl;
	std::cout << "number_3: " << number_3 << std::endl;
}
