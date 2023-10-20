#include "polymorphism.hpp"

void	First::print(void)
{
	std::cout << "This is First class.\n";
}

First::~First(void)
{
}

void	Second::print(void)
{
	std::cout << "This is Second class.\n";
}

Second::~Second(void)
{
}
