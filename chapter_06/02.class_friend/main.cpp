#include "class_friend.hpp"

int	main(void)
{
	Numbers	obj(10, 20);
	Friend	friend_obj(0);

	obj.print_variables();
	friend_obj.print_variables();
	friend_obj.add_numbers(obj);
	friend_obj.print_friend(obj);
	return (0);
}
