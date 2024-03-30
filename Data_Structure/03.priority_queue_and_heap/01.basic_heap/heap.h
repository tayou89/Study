#ifndef HEAP_H
# define HEAP_H

# define TRUE		1
# define FALSE		0

# define HEAP_SIZE	100

typedef char			Data;
typedef unsigned int	Priority;

typedef struct Head_Element
{
	Priority	priority;
	Data		data;
}	Element;

typedef	struct Heap
{
	int	numberOfData;
	Element	elementArray[HEAP_SIZE];
}	Heap;

void	heap_init(Heap *heap);
int		heap_is_empty(const Heap *heap);

void	heap_insert(Heap *heap, Data data, Priority priority);
Data	heap_delete(Heap *heap);

#endif
