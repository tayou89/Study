#ifndef CONSTRUCTOR_IN_CLASS_HPP
# define CONSTRUCTOR_IN_CLASS_HPP

# include <iostream>

class	Other
{
	private:
		int	x;
		int	y;
	public:
		Other(int a, int b);
		void	print_variables();
		~Other();
};

class	Origin
{
	private:
		Other	other_class_1;
		Other	other_class_2;
	public:
		Origin(int a, int b, int c, int d);
		void	print_variables();
		~Origin();
};

#endif
