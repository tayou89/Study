#include <stdio.h>
#include <stdlib.h>

int		*get_numbers(int *number_count);
int		*malloc_number_array(int *number_count);
void	fill_number_array(int *number, int number_count);
int		get_number_to_find(void);
extern int	binary_search(int array[], int first, int last, int target);

int	main(void)
{
	int	*number;
	int	number_count;
	int	number_to_find;
	int	located_index;

	number = get_numbers(&number_count);
	if (number == (void *) 0)
		return (0);
	number_to_find = get_number_to_find();
	located_index = \
	binary_search(number, 0, number_count - 1, number_to_find);
	if (located_index == -1)
		printf("number does not exist.\n");
	else
		printf("located index: %d\n", located_index);
	free(number);
	return (0);
}

int	*get_numbers(int *number_count)
{
	int	*number;

	number = malloc_number_array(number_count);
	if (number == (void *) 0)
		return ((void *) 0);
	fill_number_array(number, *number_count);
	return (number);
}

int	*malloc_number_array(int *number_count)
{
	int	*number;

	printf("number count(more than zero): ");
	scanf("%d", number_count);
	if (*number_count <= 0)
	{
		printf("Wrong number count.\n");
		return ((void *) 0);
	}
	number = (int *) malloc(sizeof(int) * (*number_count));
	if (number == (void *) 0)
	{
		perror("");
		exit(1);
	}
	return (number);
}

void	fill_number_array(int *number, int number_count)
{
	printf("type %d numbers(Ascending order): ", number_count);
	for (int i = 0; i < number_count; i++)
		scanf("%d", &number[i]);
}

int	get_number_to_find(void)
{
	int	number;

	printf("number to find: ");
	scanf("%d", &number);
	return (number);
}
