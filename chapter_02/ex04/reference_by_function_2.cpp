#include <iostream>

int	&change_number(int &ref);
int	return_number(int &ref);

int	main(void)
{
	int	number;
	int	not_ref;

	number = 10;
	std::cout << "number: " << number << std::endl;
	int	&ref = change_number(number);
	std::cout << "number: " << number << std::endl;
	std::cout << "ref: " << ref << std::endl;
	ref++;
	std::cout << "number: " << number << std::endl;
	std::cout << "ref: " << ref << std::endl;
	not_ref = return_number(number);
	std::cout << "not_ref: " << not_ref << std::endl;
	not_ref++;
	std::cout << "not_ref is increased.\n";
	std::cout << "number: " << number << std::endl;
	std::cout << "not_ref: " << not_ref << std::endl;
	return (0);
}

int	&change_number(int &ref)
{
	ref++;
	std::cout << "Number is increased.\n";
	return (ref);
}

int	return_number(int &ref)
{
	return (ref);
}
