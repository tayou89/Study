#ifndef VIRTUAL_HPP
# define VIRTUAL_HPP

# include <iostream>

class	First
{
	public:
		void	print_class(void) {std::cout << "First class.\n";}
};

class	Second : public First
{
	public:
		void	print_class(void) {std::cout << "Second class.\n";}
};

class	Third : public Second
{
	public:
		void	print_class(void) {std::cout << "Third class.\n";}
};

class	One
{
	public:
		virtual void	print_class(void) {std::cout << "One class.\n";}
};

class	Two : public One
{
	public:
		virtual void	print_class(void) {std::cout << "Two class.\n";}
};

class	Three : public Two
{
	public:
		virtual void	print_class(void) {std::cout << "Three class.\n";}
};

#endif
