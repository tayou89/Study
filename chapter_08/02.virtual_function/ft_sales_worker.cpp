#include "is_a_heritance.hpp"

SalesWorker::SalesWorker(const char *name, int salary, double ratio)
	: PermanentWorker(name, salary), sales_result(0), bonus_ratio(ratio)
{
}

void	SalesWorker::add_sales_result(int value)
{
	sales_result += value;
}

int SalesWorker::get_salary(void) const
{
	int	salary;

	salary = PermanentWorker::get_salary() + (int) (sales_result * bonus_ratio);
	return (salary);
}

void	SalesWorker::print_worker_info(void) const
{
	print_name();
	std::cout << "Sales Result: " << sales_result << std::endl;
	std::cout << "Bonus Ratio: " << bonus_ratio << std::endl;
	std::cout << "Basic Salary: " << PermanentWorker::get_salary() << std::endl;
	std::cout << "Bonus: " << (int) (sales_result * bonus_ratio) << std::endl;
	std::cout << "Salary: " << get_salary() << "\n\n";
}
