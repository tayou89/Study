#include <stdio.h>

void	hanoi_tower(int disk_number, char from, char by, char to);

int	main(void)
{
	int	disk_count;

	printf("disk count: ");
	scanf("%d", &disk_count);
	hanoi_tower(disk_count, 'A', 'B', 'C');
	return (0);
}

void	hanoi_tower(int disk_number, char from, char by, char to)
{
	if (disk_number == 1)
		printf("Disk %d moved from %c to %c.\n", disk_number, from, to);
	else
	{
		hanoi_tower(disk_number - 1, from, to, by);
		printf("Disk %d moved from %c to %c.\n", disk_number, from, to);
		hanoi_tower(disk_number -1, by, from , to);
	}
}
