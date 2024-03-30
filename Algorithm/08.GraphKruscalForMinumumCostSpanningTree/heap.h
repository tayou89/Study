#ifndef HEAP_H
# define HEAP_H

# define TRUE		1
# define FALSE		0

# define HEAP_SIZE	100

# include "GraphEdge.h"

typedef Edge			HeapData;
typedef unsigned int	Priority;
typedef int Function(HeapData, HeapData);

typedef	struct Heap
{
	Function	*function;
	int			numberOfData;
	HeapData	heapArray[HEAP_SIZE];
}	Heap;

void		heap_init(Heap *heap, Function function);
int			heap_is_empty(const Heap *heap);

void		heap_insert(Heap *heap, HeapData data);
HeapData	heap_delete(Heap *heap);

#endif
