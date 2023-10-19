#ifndef DEEP_COPY_HPP
# define DEEP_COPY_HPP

# include <iostream>
# include <cstring>

class Person
{
	private:
		char	*name;
		int		age;
	public:
		Person(const char *string, int number);
		Person(const Person &a);
		void	print_variables();
		~Person();
};

#endif
