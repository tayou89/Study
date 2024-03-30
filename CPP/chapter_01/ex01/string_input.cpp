#include <iostream>

int	main(void)
{
	char	string_1[100];

	std::cout << "첫번째 문자열: ";
	std::cin >> string_1;
	std::cout << "첫번째 문자열은 \"" << string_1 << "\"" << ' ' << "입니다." << std::endl;
	return (0);
}
