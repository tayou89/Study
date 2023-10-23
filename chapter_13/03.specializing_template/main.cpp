#include <iostream>

template <class T>
T	find_big(T data_1, T data_2);

template <>
const char	*find_big<const char *>(const char *string_1, const char *string_2);

int	main(void)
{
	std::cout << find_big(2, 3) << std::endl;
	std::cout << find_big('a', 'b') << std::endl;
	std::cout << find_big("abcd", "abcdefg") << std::endl;
	return (0);
}

template <class T>
T	find_big(T data_1, T data_2)
{
	return (data_1 > data_2 ? data_1 : data_2);
}

template <>
const char	*find_big<const char *>(const char *string_1, const char *string_2)
{
	return (strlen(string_1) > strlen(string_2) ? string_1 : string_2);
}
