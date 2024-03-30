#ifndef SMART_POINTER_HPP
# define SMART_POINTER_HPP

# include <iostream>

class	Some
{
	private:
		int	x;
		int	y;
	public:
		Some(int number_1, int number_2);
		void	set_variables(int number_1, int number_2);
		~Some(void);
};

class	SmartPointer
{
	private:
		Some	*obj;
	public:
		SmartPointer(Some *some);
		Some	&operator*(void) const;
		Some	*operator->(void) const;
		~SmartPointer(void);
};

#endif
