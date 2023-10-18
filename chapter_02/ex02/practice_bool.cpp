#include <iostream>

bool check_positive_number(int number);

int	main(void)
{
	int		number;

	std::cout << "number: ";
	std::cin >> number;
	if (check_positive_number(number) == true)
		std::cout << "This number is positive number" << std::endl;
	else
		std::cout << "This number is negative number" << std::endl;
	return (0);
}

bool check_positive_number(int number)
{
	if (number >= 0)
		return (true);
	else
		return (false);
}
