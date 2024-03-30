#ifndef OPERATOR_HPP
# define OPERATOR_HPP

# include <iostream>

class	Some
{
	private:
		int	number;
	public:
		Some(int n);
		Some	operator+(const Some &other);
		void	print_number(void);
};

#endif
