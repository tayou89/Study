#ifndef OBJECT_ORIENTED_HPP
# define OBJECT_ORIENTED_HPP

# include <iostream>

class	FruitSeller
{
	private:
		int	apple_price;
		int	apple_count;
		int	seller_money;
	public:
		void	init_data(int price, int count, int money);
		int		sell_apple(int money);
		void	print_status();
};

class	FruitBuyer
{
	private:
		int	buyer_money;
		int	apple_count;
	public:
		void	init_data(int number, int money);
		void	buy_apple(FruitSeller &seller, int money);
		void	print_status();
};

#endif
