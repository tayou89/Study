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
		friend Some	&operator++(Some &obj);
		void	print_number();
};

Some	&operator++(Some &obj);

#endif
