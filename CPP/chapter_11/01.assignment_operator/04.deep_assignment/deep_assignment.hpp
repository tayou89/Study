#ifndef ASSIGNMENT_OPERATOR_HPP
# define ASSIGNMENT_OPERATOR_HPP

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
		Some	&operator=(const Some &ref);
		~Some(void);
};

# endif
