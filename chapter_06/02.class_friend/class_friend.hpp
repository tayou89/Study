#ifndef CLASS_FRIEND_HPP
# define CLASS_FRIEND_HPP

# include <iostream>

class Numbers
{
	private:
		int				number_1;
		int				number_2;
		friend class	Friend;
	public:
		Numbers(int a, int b);
		void	print_variables(void);
		~Numbers();
};

class Friend
{
	private:
		int	number;
	public:
		Friend(int a);
		void	add_numbers(Numbers &obj);
		void	print_variables();
		void	print_friend(const Numbers &obj);
		~Friend();
};

#endif
