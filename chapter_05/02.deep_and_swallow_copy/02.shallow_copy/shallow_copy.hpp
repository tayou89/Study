#ifndef SHALLOW_COPY_HPP
# define SHALLOW_COPY_HPP

# include <iostream>
# include <cstring>

class Person
{
	private:
		char	*name;
		int		age;
	public:
		Person(const char *string, int number);
		void	print_variables();
		~Person();
};

#endif
