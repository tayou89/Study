#ifndef CONST_OBJECT_HPP
# define CONST_OBJECT_HPP

# include <iostream>

class Numbers
{
	private:
		int	number_1;
		int	number_2;
	public:
		Numbers(int a, int b);
		void	print_variables(void);
		void	print_variables(void) const;
		void	add_numbers(Numbers &obj);
		void	add_numbers(const Numbers &obj) const;
		~Numbers();
};

#endif
