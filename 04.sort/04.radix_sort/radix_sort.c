#include "ListBaseQueue.h"

# define BUCKET_COUNT	10

void	radix_sort(int array[], int size, int max_digit)
{
	Queue	bucket[BUCKET_COUNT];
	int		bucket_index;
	int		array_index;
	int		radix;
	int		divisor = 1;
	int		i;

	for (bucket_index = 0; bucket_index < BUCKET_COUNT; bucket_index++)
		queue_init(&bucket[bucket_index]);
	for (i = 0; i < max_digit; i++)
	{
		for (array_index = 0; array_index < size; array_index++)
		{
			radix = (array[array_index] / divisor) % 10;
			enqueue(&bucket[radix], array[array_index]);
		}
		for (bucket_index = 0, array_index = 0; bucket_index < BUCKET_COUNT; bucket_index++)
		{
			while (queue_is_empty(&bucket[bucket_index]) == FALSE)
				array[array_index++] = dequeue(&bucket[bucket_index]);
		}
		divisor *= 10;
	}
}
