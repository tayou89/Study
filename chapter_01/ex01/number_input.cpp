#include <iostream>

int	main(void)
{
	int	first_number;

	std::cout << "첫번째 숫자입력: ";
	std::cin >> first_number;

	int	second_number;

	std::cout << "두번째 숫자입력: ";
	std::cin >> second_number;

	int	sum;

	sum = first_number + second_number;
	std::cout << "덧셈결과: " << sum << std::endl;
	return (0);
}
