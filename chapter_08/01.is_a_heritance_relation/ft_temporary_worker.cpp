#include "is_a_heritance.hpp"

TemporaryWorker::TemporaryWorker(const char *name, int pay)
	: Employee(name), working_hour(0), pay_per_hour(pay)
{
}

void	TemporaryWorker::add_working_hour(int hour)
{
	working_hour += hour;
}

int	TemporaryWorker::get_salary(void) const
{
	int	salary;

	salary = working_hour * pay_per_hour;
	return (salary);
}

void	TemporaryWorker::print_worker_info(void) const
{
	print_name();
	std::cout << "Working Hour: " << working_hour << std::endl;
	std::cout << "Pay Per Hour: " << pay_per_hour << std::endl;
	std::cout << "Salary: " << get_salary() << "\n\n";
}
