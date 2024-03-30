#include "object_oriented.hpp"
#include <iostream>

void	FruitSeller::init_data(int price, int number, int money)
{
	apple_price = price;
	apple_count = number;
	seller_money = money;
}

int	FruitSeller::sell_apple(int money)
{
	int count_to_sell;

	count_to_sell = money / apple_price;
	apple_count -= count_to_sell;
	seller_money += money;
	return (apple_count);
}

void	FruitSeller::print_status()
{
	std::cout << "===============Seller Status==============\n";
	std::cout << "apple count: " << apple_count << std::endl;
	std::cout << "seller money: " << seller_money << "\n\n";
}
