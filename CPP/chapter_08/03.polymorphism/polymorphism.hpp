#ifndef POLYMORPHISM_HPP
# define POLYMORPHISM_HPP

# include <iostream>

class	First
{
	public:
		virtual void	print(void);
		virtual	~First(void);
};

class	Second : public First
{
	public:
		virtual void	print(void);
		~Second(void);
};

#endif
