#include "Table.h"
#include <string.h>

void	TableInit(Table *table, HashFunction hashFunction)
{
	int	i;

	for (i = 0; i < TABLE_MAX; i++)
		ListInit(&(table->slot[i]));
	table->hashFunction = hashFunction;
}

void	TableInsert(Table *table, Key key, Value value)
{
	int		hash = table->hashFunction(key);
	Slot	slot = {key, value};

	ListInsert(&(table->slot[hash]), slot);
}

Value	TableDelete(Table *table, Key key)
{
	int			hash = table->hashFunction(key);
	List		*list = &(table->slot[hash]);
	ListData	data;

	ListFirst(list);
	while (ListCurrent(list) != NULL)
	{
		data = ListGetData(list);
		if (strcmp(data.key, key) == 0)
		{
			ListRemove(list);
			return (data.value);
		}
		ListNext(list);
	}
	return (NULL);
}

Value	TableSearch(Table *table, Key key)
{
	int			hash = table->hashFunction(key);
	Node		*node = ListFirst(&(table->slot[hash]));

	return (node->data.value);
}
