#ifndef CLASS_TEMPLATE_HPP
# define CLASS_TEMPLATE_HPP

# include <iostream>

template <typename T>

class	Some
{
	private:
		T	data_1;
		T	data_2;
	public:
		Some(T number_1, T number_2);
		void	print_data(void);
};

#endif
