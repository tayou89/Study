#include <stdlib.h>

void	merge_two_sort(int array[], int left, int mid, int right);

void	merge_sort(int array[], int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(array, left, mid);
		merge_sort(array, mid + 1, right);
		merge_two_sort(array, left, mid, right);
	}
}

void	merge_two_sort(int array[], int left, int mid, int right)
{
	int	left_side_index = left;
	int	right_side_index = mid + 1;
	int	sort_array_size = right + 1;
	int	*sort_array = (int *) malloc(sizeof(int) * sort_array_size);
	int	sort_array_index = left;

	while (left_side_index <= mid && right_side_index <= right)
	{
		if (array[left_side_index] < array[right_side_index])
			sort_array[sort_array_index++] = array[left_side_index++];
		else
			sort_array[sort_array_index++] = array[right_side_index++];
	}
	while (left_side_index <= mid)
		sort_array[sort_array_index++] = array[left_side_index++];
	while (right_side_index <= right)
		sort_array[sort_array_index++] = array[right_side_index++];
	for (int i = left; i <= right; i++)
		array[i] = sort_array[i];
	free(sort_array);
}
