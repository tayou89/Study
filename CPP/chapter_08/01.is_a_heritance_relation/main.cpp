#include "is_a_heritance.hpp"

int	main(void)
{
	PermanentWorker	permanent_worker("Tom", 1000);
	TemporaryWorker	temporary_worker("Bread", 20);
	SalesWorker		sales_worker("Lilly", 1000, 0.1);

	permanent_worker.print_worker_info();
	temporary_worker.print_worker_info();
	sales_worker.print_worker_info();
	return (0);
}
