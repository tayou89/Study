#ifndef PROTECTED_VARIABLE_HPP
# define PROTECTED_VARIABLE_HPP

# include <iostream>

class Father
{
	private:
		int	father_number;
	protected:
		int	protected_number;
	public:
		Father(void);
		Father(int a, int b);
		void	print_father_number();
		~Father();
};

class Son : public Father
{
	private:
		int	son_number;
	public:
		Son(void);
		Son(int n);
		Son(int a, int b, int c);
		void	print_son_number();
		~Son(void);
};

#endif
