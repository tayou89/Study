#ifndef CONSTRUCTOR_HPP
# define CONSTRUCTOR_HPP

# include <iostream>

class Constructor
{
	private:
		int	number_1;
		int number_2;
	public:
		Constructor(int a, int b);
		void	print_variables();
		~Constructor();
}; 

#endif
