#include "is_a_heritance.hpp"

int	main(void)
{
	Employee	*permanent_worker = new PermanentWorker("Tom", 1000);
	Employee	*temporary_worker = new TemporaryWorker("Bread", 20);
	Employee	*sales_worker = new SalesWorker("Lilly", 1000, 0.1);

	permanent_worker->print_worker_info();
	temporary_worker->print_worker_info();
	sales_worker->print_worker_info();
	delete permanent_worker;
	delete temporary_worker;
	delete sales_worker;
	return (0);
}
