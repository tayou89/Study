#ifndef STATIC_VARIABLE_HPP
# define STATIC_VARIABLE_HPP

# include <iostream>

class Numbers
{
	private:
		int			non_static;
		static int	private_static;
	public:
		static int	public_static;
		Numbers(int a);
		void	add_number(void);
		void	print_variables(void);
		~Numbers();
	
};

class Other
{
	private:
		int	number;
	public:
		Other(int a);
		void	add_number(void);
		void	print_variables(void);
		~Other(void);
};


#endif
