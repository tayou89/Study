#ifndef PREFIX_OPERATOR_HPP
# define PREFIX_OPERATOR_HPP

# include <iostream>

class	Some
{
	private:
		int	x;
		int	y;
	public:
		Some(int number_1, int number_2);
		Some	&operator++(void);
		void	print_number();
};

#endif
