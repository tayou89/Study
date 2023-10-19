#include "class_friend.hpp"

Numbers::Numbers(int a, int b)
{
	std::cout << "Constructor is called.\n";
	number_1 = a;
	number_2 = b;
}

void	Numbers::print_variables(void)
{
	std::cout << "number_1: " << number_1 << std::endl;
	std::cout << "number_2: " << number_2 << std::endl;
}

Numbers::~Numbers(void)
{
	std::cout << "Destructor is called.\n";
}

Friend::Friend(int a)
{
	std::cout << "Friend constructor is called.\n";
	number = a;
}

void	Friend::add_numbers(Numbers &obj)
{
	std::cout << "Start to add friend class data.\n";
	obj.number_1++;
	obj.number_2++;
}

void	Friend::print_variables(void)
{
	std::cout << "This is Friend class.\n";
	std::cout << "number: " << number << std::endl;
}

void	Friend::print_friend(const Numbers &obj)
{
	std::cout << "Start to print friend class data.\n";
	std::cout << "friend number_1: " << obj.number_1 << std::endl;
	std::cout << "friend number_2: " << obj.number_2 << std::endl;
}

Friend::~Friend(void)
{
	std::cout << "Destructor is called.\n";
}
