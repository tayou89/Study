#include <stdio.h>

int	fibonacci(int number);

int	main(void)
{
	int	number;
	int	result;

	printf("number( > 0): ");
	scanf("%d", &number);
	for (int i = 1; i <= number; i++)
	{
		result = fibonacci(i);
		printf("%d", result);
		printf(" ");
	}
	printf("\n");
	return (0);
}

int	fibonacci(int number)
{
	if (number == 1)
		return (0);
	else if (number == 2)
		return (1);
	else
		return (fibonacci(number - 1) + fibonacci(number - 2));
}
