#include "heap.h"
#include <stdio.h>

int	main(void)
{
	Heap	heap;

	heap_init(&heap);
	heap_insert(&heap, 'A', 1);
	heap_insert(&heap, 'B', 2);
	heap_insert(&heap, 'C', 3);
	heap_insert(&heap, 'D', 4);
	printf("heap data: %c\n", heap_delete(&heap));

	heap_insert(&heap, 'A', 1);
	heap_insert(&heap, 'B', 2);
	heap_insert(&heap, 'C', 3);
	heap_insert(&heap, 'D', 4);
	printf("heap data: %c\n", heap_delete(&heap));
	while (heap_is_empty(&heap) == FALSE)
		printf("heap data: %c\n", heap_delete(&heap));
	return (0);
}
