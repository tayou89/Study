#include "string_class.hpp"
#include <string>

void	leaks(void)
{
	system("leaks a.out");
}

int	main(void)
{
	std::string	str_1 = "I like ";
	std::string str_2 = "string class";
	std::string str_3 = str_1 + str_2;
	
	atexit(leaks);
	std::cout << str_1 << std::endl;
	std::cout << str_2 << std::endl;
	std::cout << str_3 << std::endl;
	str_1 += str_2;
	if (str_1 == str_3)
		std::cout << "Same string.\n";
	else
		std::cout << "Different string.\n";
	std::string	str_4;
	std::cout << "str_4: ";
	std::cin >> str_4;
	std::cout << "str_4: " << str_4 << std::endl;

	std::cout << "\n====================My String Class==================\n\n";
	String	string_1 = "I like ";
	String 	string_2 = "string class";
	String 	string_3 = string_1 + string_2;
	
	std::cout << string_1 << std::endl;
	std::cout << string_2 << std::endl;
	std::cout << string_3 << std::endl;
	string_1 += string_2;
	if (string_1 == string_3)
		std::cout << "Same stringing.\n";
	else
		std::cout << "Different stringing.\n";
	String	string_4;
	std::cout << "string_4: ";
	std::cin >> string_4;
	std::cout << "string_4: " << string_4 << std::endl;
	return (0);
}
