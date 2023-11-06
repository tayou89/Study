#include "Table.h"
#include <stdio.h>

int	Function(Key key);

int	main(void)
{
	Table	table;
	Person	*person[10];
	Value	value;
	int		i;

	person[0] = MakePerson("Charlie", 20);
	person[1] = MakePerson("Nancy", 15);
	person[2] = MakePerson("Bread", 18);
	person[3] = MakePerson("Bob", 18);
	person[4] = MakePerson("Candy", 13);
	person[5] = MakePerson("Lisa", 21);
	person[6] = MakePerson("Mike", 14);
	person[7] = MakePerson("Mickey", 25);
	person[8] = MakePerson("Nell", 26);
	person[9] = MakePerson("Harry", 27);

	TableInit(&table, Function);
	for (i = 0; i < 10; i++)
		TableInsert(&table, person[i]->name, person[i]);
	value = TableSearch(&table, "Harry");
	if (value == NULL)
		printf("value is NULL.\n");
	else
	{
		printf("value->name: %s\n", value->name);
		printf("value->age: %d\n", value->age);
	}
	return (0);
}

int	Function(Key key)
{
	int	hash;

	hash = key[0] - 65;
	return (hash);
}
