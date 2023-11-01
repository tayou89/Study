int	binary_search(int array[], int first, int last, int target)
{
	int	mid;

	if (first > last)
		return (-1);
	mid = (first + last) / 2;
	if (array[mid] == target)
		return (mid);
	if (target < array[mid])
		return (binary_search(array, first, mid - 1, target));
	else
		return (binary_search(array, mid + 1, last, target));
}
