#include <iostream>

void	print_number(int number);
void	print_number(int number_1, int number_2);

int	main(void)
{
	int	number_1;
	int	number_2;

	std::cout << "number_1: ";
	std::cin >> number_1;
	std::cout << "number_2: ";
	std::cin >> number_2;
	print_number(number_1);
	print_number(number_2);
	print_number(number_1, number_2);
	return (0);
}

void	print_number(int number)
{
	std::cout << "number: " << number << std::endl;
}

void	print_number(int number_1, int number_2)
{
	std::cout << "sum: " << number_1 + number_2 << std::endl;
}
