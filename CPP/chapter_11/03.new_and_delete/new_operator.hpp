#ifndef NEW_OPERATOR_HPP
# define NEW_OPERATOR_HPP

# include <iostream>

class	Some
{
	private:
		int	number;
	public:
		Some(int n);
		void	*operator new (size_t size);
		void	operator delete (void *address);
		void	print_number();
};

#endif
