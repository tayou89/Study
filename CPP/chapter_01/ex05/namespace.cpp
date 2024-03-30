#include <iostream>

namespace	space_1
{
	void	ask_user_name(void);
}

namespace	space_2
{
	void	ask_user_name(void);
}

int	main(void)
{
	space_1::ask_user_name();
	space_2::ask_user_name();
	return (0);
}

void	space_1::ask_user_name(void)
{
	std::cout << "This is space_1." << std::endl;
	std::cout << "What is your name?." << std::endl;
}

void	space_2::ask_user_name(void)
{
	std::cout << "This is space_2." << std::endl;
	std::cout << "What is your name?." << std::endl;
}
