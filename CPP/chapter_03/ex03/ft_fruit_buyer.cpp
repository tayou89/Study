#include "object_oriented.hpp"

void	FruitBuyer::init_data(int number, int money)
{
	apple_count = number;
	buyer_money = money;
}

void	FruitBuyer::buy_apple(FruitSeller &seller, int money)
{
	apple_count += seller.sell_apple(money);
	buyer_money -= money;
}

void	FruitBuyer::print_status(void)
{
	std::cout << "=================Buyer Status===============\n";
	std::cout << "apple count: " << apple_count << std::endl;
	std::cout << "buyer money: " << buyer_money << "\n\n";
}
