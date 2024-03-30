#ifndef POSTFIX_OPERATOR_HPP
# define POSTFIX_OPERATOR_HPP

# include <iostream>

class	Some
{
	private:
		int	x;
		int	y;
	public:
		Some(int number_1, int number_2);
		friend const Some	operator++(Some &ref, int);
		void	print_number();
		void	print_number() const;
};

const Some	operator++(Some &ref, int);

#endif
