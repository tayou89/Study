#ifndef COPY_CONSTRUCTOR_HPP
# define COPY_CONSTRUCTOR_HPP

# include <iostream>

class	Abc
{
	private:
		int	number_1;
		int	number_2;

	public:
		Abc(int number_1, int number_2);
		void	print_variables();
		~Abc();
};

#endif
