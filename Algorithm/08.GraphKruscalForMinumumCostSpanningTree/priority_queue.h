#ifndef PRIORITY_QUEUE_H
# define PRIORITY_QUEUE_H

# include "heap.h"

typedef Heap		PQueue;
typedef HeapData	PQData;

void	pQueue_init(PQueue *pQueue, Function function);
int		pQueue_is_empty(const PQueue *pQueue);
void	enPQueue(PQueue *pQueue, PQData data);
PQData	dePQueue(PQueue *pQueue);

#endif
