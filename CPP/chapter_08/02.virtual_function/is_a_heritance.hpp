#ifndef IS_A_HERITANCE_HPP
# define IS_A_HERITANCE_HPP

# include <cstring>
# include <iostream>

class Employee
{
	private:
		char	*name;
	public:
		Employee(const char *name);
		void			print_name(void) const;
		virtual int		get_salary() const = 0;
		virtual void	print_worker_info() const = 0;
		virtual	~Employee(void);
};

class PermanentWorker : public Employee
{
	private:
		int	salary;
	public:
		PermanentWorker(const char *name, int money);
		virtual int		get_salary() const;
		virtual void	print_worker_info() const;
};

class TemporaryWorker : public Employee
{
	private:
		int	working_hour;
		int	pay_per_hour;
	public:
		TemporaryWorker(const char *name, int pay);
		void			add_working_hour(int hour);
		virtual int		get_salary() const;
		virtual void	print_worker_info() const;
};

class SalesWorker : public PermanentWorker
{
	private:
		int		sales_result;
		double	bonus_ratio;
	public:
		SalesWorker(const char *name, int salary, double ratio);
		void			add_sales_result(int value);
		virtual int		get_salary() const;
		virtual void	print_worker_info() const;
};

#endif
