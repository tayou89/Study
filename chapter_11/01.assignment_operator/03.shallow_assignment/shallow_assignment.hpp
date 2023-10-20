#ifndef SHALLOW_ASSIGNMENT_HPP
# define SHALLOW_ASSIGNMENT_HPP

# include <iostream>
# include <cstring>

class	Some
{
	private:
		char	*name;
		int		age;
	public:
		Some(const char *string, int number);
		void	print_data();
		~Some(void);
};

# endif
