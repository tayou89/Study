#include "priority_queue.h"
#include <stdio.h>

int	define_priority(PQData data_1, PQData data_2);

int	main(void)
{
	PQueue	pQueue;

	pQueue_init(&pQueue, define_priority);
	enPQueue(&pQueue, 'A');
	enPQueue(&pQueue, 'B');
	enPQueue(&pQueue, 'C');
	enPQueue(&pQueue, 'D');
	printf("pQueue data: %c\n", dePQueue(&pQueue));

	enPQueue(&pQueue, 'A');
	enPQueue(&pQueue, 'B');
	enPQueue(&pQueue, 'C');
	enPQueue(&pQueue, 'D');
	printf("pQueue data: %c\n", dePQueue(&pQueue));
	while (pQueue_is_empty(&pQueue) == FALSE)
		printf("pQueue data: %c\n", dePQueue(&pQueue));
	return (0);
}

int	define_priority(PQData data_1, PQData data_2)
{
	return (data_2 - data_1);
}
