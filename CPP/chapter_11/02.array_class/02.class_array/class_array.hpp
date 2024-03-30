#ifndef CLASS_ARRAY_HPP
# define CLASS_ARRAY_HPP

# include <iostream>

class	Some
{
	private:
		int	number;
	public:
		Some(int n);
		void	print_number();
};

class	BoundCheckArray
{
	private:
		Some	**class_array;
		int		array_size;
	public:
		BoundCheckArray(int size);
		Some	*&operator[] (int index);
		void	print_array_data(void);
		~BoundCheckArray(void);
};

#endif
