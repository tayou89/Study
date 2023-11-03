static int	get_partition(int array[], int left, int right);
static int	get_pivot(int array[], int left, int right);
static void	bubble_sort(int array[], int array_size);
static void	swap(int *data_1, int *data_2);

void	quick_sort(int array[], int left, int right)
{
	int	pivot_index;

	if (left <= right)
	{
		pivot_index = get_partition(array, left, right);
		quick_sort(array, left, pivot_index - 1);
		quick_sort(array, pivot_index + 1, right);
	}
	else
		return ;
}

int	get_partition(int array[], int left, int right)
{
	int	pivot = get_pivot(array, left, right);
	int	low = left + 1;
	int	high = right;

	while (low <= high)
	{
		while (array[low] <= pivot && low <= right)
			low++;
		while (array[high] >= pivot && high >= left + 1)
			high--;
		if (low <= high)
			swap(&array[low], &array[high]);
	}
	swap(&array[left], &array[high]);
	return (high);
}

int	get_pivot(int array[], int left, int right)
{
	int	mid = (left + right) / 2;
	int	pivot_array[3] = {array[left], array[mid], array[right]};
	int	pivot;

	bubble_sort(pivot_array, 3);
	pivot = pivot_array[1];
	if (array[mid] == pivot)
		swap(&array[left], &array[mid]);
	else if (array[right] == pivot)
		swap(&array[left], &array[right]);
	return (pivot);
}

void	bubble_sort(int array[], int array_size)
{
	int	i;
	int	j;

	for (i = 0; i + 1 < array_size; i++)
	{
		for (j = i; j + 1 < array_size; j++)
		{
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
		}
	}
}

void	swap(int *data_1, int *data_2)
{
	int	temp;

	temp = *data_1;
	*data_1 = *data_2;
	*data_2 = temp;
}
