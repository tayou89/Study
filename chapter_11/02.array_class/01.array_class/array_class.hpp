#ifndef ARRAY_CLASS_HPP
# define ARRAY_CLASS_HPP

# include <iostream>

class	BoundCheckArray
{
	private:
		int	*array;
		int	array_size;
		BoundCheckArray(const BoundCheckArray &obj) {}
		BounCheckArray	&operator=(const BoundCheckArray &obj) {}
	public:
		BoundCheckArray(int size);
		int	&operator[](int index);
		void	print_array(void);
		~BoundCheckArray(void);
};

#endif
