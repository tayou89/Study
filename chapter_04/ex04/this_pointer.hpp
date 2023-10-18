#ifndef THIS_POINTER_HPP
# define THIS_POINTER_HPP

# include <iostream>

class	SelfRef
{
	private:
		int	number;
	public:
		SelfRef(int a);
		void	print_variables();
		SelfRef	&increase_number();
		SelfRef	&print_number();
		~SelfRef();
};

#endif
