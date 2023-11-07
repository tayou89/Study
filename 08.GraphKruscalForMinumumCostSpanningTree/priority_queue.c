#include "priority_queue.h"

void	pQueue_init(PQueue *pQueue, Function function)
{
	heap_init(pQueue, function);
}

int	pQueue_is_empty(const PQueue *pQueue)
{
	return (heap_is_empty(pQueue));
}

void	enPQueue(PQueue *pQueue, PQData data)
{
	heap_insert(pQueue, data);
}

PQData	dePQueue(PQueue *pQueue)
{
	return (heap_delete(pQueue));
}
