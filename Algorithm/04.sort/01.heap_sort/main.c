#include "heap.h"
#include <stdio.h>

int	define_priority(HeapData data_1, HeapData data_2);

int	main(void)
{
	int		array[] = {4, 2, 5, 3, 1, 9, 8, 7, 6};
	int		array_size;
	Heap	heap;
	int		i;

	heap_init(&heap, define_priority);
	array_size = sizeof(array) / sizeof(int);
	for (i = 0; i < array_size; i++)
		heap_insert(&heap, array[i]);
	i = 0;
	while (!heap_is_empty(&heap))
		array[i++] = heap_delete(&heap);
	for (i = 0; i < array_size; i++)
		printf("array[%d]: %d\n", i, array[i]);
	return (0);
}

int	define_priority(HeapData data_1, HeapData data_2)
{
	return (data_2 - data_1);
}
