#ifndef CLASS_INHERITANCE_HPP
# define CLASS_INHERITANCE_HPP

# include <iostream>

class Father
{
	private:
		int	number;
	public:
		Father(void);
		Father(int n);
		void	print_father_number();
		~Father();
};

class Son : public Father
{
	private:
		int	number;
	public:
		Son(void);
		Son(int n);
		Son(int a, int b);
		void	print_son_number();
		~Son(void);
};

#endif
