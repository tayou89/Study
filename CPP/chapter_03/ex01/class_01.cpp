#include <iostream>

struct phone_book
{
	char	name[30];
	char	number[3];
	int		age;
	void	input_phonebook_data(struct phone_book &book);
	void	print_phonebook_data(struct phone_book book);
};

int	main(void)
{
	phone_book	book_1;

	book_1.input_phonebook_data(book_1);
	book_1.print_phonebook_data(book_1);
	return (0);
}

void	phone_book::input_phonebook_data(phone_book &book)
{
	std::cout << "Name: ";
	std::cin >> book.name;
	std::cout << "number: ";
	std::cin >> book.number;
	std::cout << "age: ";
	std::cin >> book.age;
}

void	phone_book::print_phonebook_data(phone_book book)
{
	std::cout << "Name: " << book.name << std::endl;
	std::cout << "number: " << book.number << std::endl;
	std::cout << "age: " << book.age << std::endl;
}
