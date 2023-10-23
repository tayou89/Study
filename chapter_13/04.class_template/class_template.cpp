# include "class_template.hpp"

template <typename T>
Some<T>::Some(T number_1, T number_2)
	: data_1(number_1), data_2(number_2)
{
}

template <typename T>
void	Some<T>::print_data(void)
{
	std::cout << data_1 << ", " << data_2 << std::endl;
}
