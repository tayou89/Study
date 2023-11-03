#include "heap.h"
#include <stdio.h>

int	define_priority(HeapData data_1, HeapData data_2);

int	main(void)
{
	Heap	heap;

	heap_init(&heap, define_priority);
	heap_insert(&heap, 'A');
	heap_insert(&heap, 'B');
	heap_insert(&heap, 'C');
	heap_insert(&heap, 'D');
	printf("heap data: %c\n", heap_delete(&heap));

	heap_insert(&heap, 'A');
	heap_insert(&heap, 'B');
	heap_insert(&heap, 'C');
	heap_insert(&heap, 'D');
	printf("heap data: %c\n", heap_delete(&heap));
	while (heap_is_empty(&heap) == FALSE)
		printf("heap data: %c\n", heap_delete(&heap));
	return (0);
}

int	define_priority(HeapData data_1, HeapData data_2)
{
	return (data_2 - data_1);
}
