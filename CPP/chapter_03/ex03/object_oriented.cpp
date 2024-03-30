#include "object_oriented.hpp"

int	main(void)
{
	FruitSeller	seller;
	FruitBuyer	buyer;

	seller.init_data(2000, 20, 0);
	seller.print_status();
	buyer.init_data(0, 30000);
	buyer.buy_apple(seller, 14000);
	seller.print_status();
	buyer.print_status();
	return (0);
}
