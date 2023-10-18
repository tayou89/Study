#include <iostream>

void	change_number(int &ref_1, int &ref_2);

int	main(void)
{
	int	number_1;
	int	number_2;

	number_1 = 10;
	number_2 = 20;
	std::cout << "number_1: " << number_1 << std::endl;
	std::cout << "number_2: " << number_2 << std::endl;
	change_number(number_1, number_2);
	std::cout << "number_1: " << number_1 << std::endl;
	std::cout << "number_2: " << number_2 << std::endl;
	return (0);
}

void	change_number(int &ref_1, int &ref_2)
{
	ref_1++;
	ref_2++;
	std::cout << "numbers are increased." << std::endl;
}
