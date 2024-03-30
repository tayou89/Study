#include <iostream>

template <class T1, class T2>
void	print(double number);

int	main(void)
{
	print<char, int>(64.2);
	print<short, double>(64.2);
	return (0);
}

template <class T1, class T2>
void	print(double number)
{
	std::cout << (T1)number << ", " << (T2)number << std::endl;
}
