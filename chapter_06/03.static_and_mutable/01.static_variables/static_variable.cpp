#include "static_function.hpp"

Numbers::Numbers(int a)
{
	std::cout << "Numbers constructor is called.\n";
	non_static = a;
}

void	Numbers::add_number(void)
{
	non_static++;
	private_static++;
	public_static++;
	std::cout << "Numbers variables are added.\n";
}

void	Numbers::print_variables(void)
{
	std::cout << "Numbers non_static: " << non_static << std::endl;
	std::cout << "Numbers private_static: " << private_static << std::endl;
	std::cout << "Numbers public_static: " << public_static << std::endl;
}

static void	Numbers::change_number(int a)
{
	add_number();
	non_static = a;
	private_static = a;
	public_static = a;
	std::cout << "Numbers variables are changed.\n";
}

Numbers::~Numbers(void)
{
	std::cout << "Numbers destructor is called.\n";
}

Other::Other(int a)
{
	std::cout << "Other constructor is called.\n";
	number = a;
}

void	Other::add_number(void)
{
	number++;
	std::cout << "Other variable is added.\n";
	Numbers::public_static++;
	std::cout << "Other's static variables are added.\n";
}

void	Other::print_variables(void)
{
	std::cout << "Other number: " << number << std::endl;
	std::cout << "Numbers public_static: " << Numbers::public_static << std::endl;
}

Other::~Other(void)
{
	std::cout << "Other destructor is called.\n";
}

