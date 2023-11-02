#include <stdio.h>

extern void	merge_sort(int array[], int left, int right);

int	main(void)
{
	int	array[] = {4, 1, 5, 3, 9, 2, 8, 7, 6};
	int	array_size;

	array_size = sizeof(array) / sizeof(int);
	merge_sort(array, 0, array_size - 1);
	for (int i = 0; i < array_size; i++)
		printf("array[%d]: %d\n", i, array[i]);
	return (0);
}
