#ifndef ARGV_DELIVERY_HPP
# define ARGV_DELIVERY_HPP

# include <iostream>

class Numbers
{
	private:
		int	number_1;
		int number_2;
	public:
		Numbers(int a, int b);
		Numbers(const Numbers &object);
		void	change_numbers(int a, int b);
		void	print_variables();
		~Numbers();
};

#endif
