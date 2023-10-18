#include <iostream>

class	phonebook
{
	private:
		char	name[30];
		char	number[30];
		int		age;

	public:
		void	get_phonebook_data();
		void	print_phonebook_data();
};

int	main(void)
{
	phonebook	book;
	book.get_phonebook_data();
	book.print_phonebook_data();
	return (0);
}

void	phonebook::get_phonebook_data()
{
	std::cout << "Name: ";
	std::cin >> name;
	std::cout << "Number: ";
	std::cin >> number;
	std::cout << "Age: ";
	std::cin >> age;
}

void	phonebook::print_phonebook_data()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Number: " << number << std::endl;
	std::cout << "Age: " << age << std::endl;
}
