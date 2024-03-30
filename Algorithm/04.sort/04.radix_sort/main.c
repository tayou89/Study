#include "ListBaseQueue.h"

extern void	radix_sort(int array[], int size, int max_digit);

int	main(void)
{
	int	array[] = {10, 21, 5, 33, 22, 107, 3, 100278, 8};
	int	array_size = sizeof(array) / sizeof(int);
	int	i;

	radix_sort(array, array_size, 6);
	for (i = 0; i < array_size; i++)
		printf("array[%d]: %d\n", i, array[i]);
	return (0);
}
