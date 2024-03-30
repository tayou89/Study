#include <stdio.h>

int	binary_search(int array[], int first, int last, int target)
{
	int	mid;

	if (target < array[first] || target > array[last])
		return (-1);
	mid = ((target - array[first]) * (last - first) / (array[last] - array[first])) +
			first;
	printf("mid: %d\n", mid);
	if (array[mid] == target)
		return (mid);
	if (target < array[mid])
		return (binary_search(array, first, mid - 1, target));
	else
		return (binary_search(array, mid + 1, last, target));
}
