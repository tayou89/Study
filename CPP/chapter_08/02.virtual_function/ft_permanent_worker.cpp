#include "is_a_heritance.hpp"

PermanentWorker::PermanentWorker(const char *name, int money)
	: Employee(name), salary(money)
{
}

int	PermanentWorker::get_salary(void) const
{
	return (salary);
}

void	PermanentWorker::print_worker_info(void) const
{
	print_name();
	std::cout << "Salary: " << get_salary() << "\n\n";
}
