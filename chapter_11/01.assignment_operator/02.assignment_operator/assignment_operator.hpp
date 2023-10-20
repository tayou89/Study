#ifndef ASSIGNMENT_OPERATOR_HPP
# define ASSIGNMENT_OPERATOR_HPP

# include <iostream>

class	Some
{
	private:
		int	x;
		int	y;
	public:
		Some(int number_1, int number_2);
		void	print_number();
		Some	&operator=(const Some &ref);
};

# endif
