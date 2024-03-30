#include <stdio.h>

extern void	quick_sort(int array[], int left, int right);

int	main(void)
{
	int	array[] = {3, 3, 3};
	int	array_size = sizeof(array) / sizeof(int);
	int	left = 0;
	int right = array_size - 1;
	int	i = 0;

	quick_sort(array, left, right);
	for (i = 0; i < array_size; i++)
		printf("array[%d]: %d\n", i, array[i]);
	return (0);
}
