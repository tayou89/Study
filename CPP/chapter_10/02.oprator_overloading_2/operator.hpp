#ifndef OPERATOR_HPP
# define OPERATOR_HPP

# include <iostream>

class	Some
{
	private:
		int	number;
	public:
		Some(int n);
		friend Some	operator+(const Some &origin, const Some &other);
		void	print_number(void);
};

Some	operator+(const Some &origin, const Some &other);

#endif
