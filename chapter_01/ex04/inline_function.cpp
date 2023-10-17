#include <iostream>

#define SQUARE(x) ((x) * (x))

inline int		square_int_number(int number);
inline double	square_double_number(double number);

int	main(void)
{
	int		number;
	double	double_number;

	number = 5;
	double_number = 3.14;
	std::cout << "=============Macro function result==============" << std::endl;
	std::cout << "integer: " << SQUARE(number) << std::endl;
	std::cout << "double: " << SQUARE(double_number) << std::endl;
	std::cout << std::endl;
	std::cout << "=============Inline function result==============" << std::endl;
	std::cout << "integer: " << square_int_number(number) << std::endl;
	std::cout << "double: " << square_double_number(double_number) << std::endl;
	return (0);
}

inline int	square_int_number(int number)
{
	return (number *number);
}

inline double	square_double_number(double number)
{
	return (number *number);
}
