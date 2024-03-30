#include <iostream>

template <typename T>
T	add(T number_1, T number_2);

int	main(void)
{
	std::cout << add(3, 4) << std::endl;
	std::cout << add<int>(3, 4) << std::endl;
	std::cout << add(6.28, 3.14) << std::endl;
	std::cout << add<double>(6.28, 3.14) << std::endl;
	std::cout << add<char>(45, 42) << std::endl;
	return (0);
}

template <typename T>
T	add(T number_1, T number_2)
{
	return (number_1 + number_2);
}
