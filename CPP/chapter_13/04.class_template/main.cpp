#include "class_template.cpp"

int	main(void)
{
	Some<int>	object_1(3, 4);
	Some<char>	object_2('a', 'b');

	object_1.print_data();
	object_2.print_data();
	return (0);
}
