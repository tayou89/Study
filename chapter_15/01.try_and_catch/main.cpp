#include <iostream>

int	main(void)
{
	int	number_1;
	int	number_2;

	std::cout << "number_1: ";
	std::cin >> number_1;
	std::cout << "number_2: ";
	std::cin >> number_2;
	try
	{
		if (number_2 == 0)
			throw (number_2);
		std::cout << "quotient: " << number_1 / number_2 << std::endl;
		std::cout << "remainder: " << number_1 % number_2 << std::endl;
	}
	catch (int exception)
	{
		std::cout << exception << " is not valid number.\n";
		std::cout << "excute program again.\n";
	}
	return (0);
}
