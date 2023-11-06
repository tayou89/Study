#ifndef TABLE_H
# define TABLE_H

# include "LinkedList.h"
# include "Slot.h"

# define TABLE_MAX	100

typedef int	HashFunction (Key);

typedef struct Table
{
	List			slot[TABLE_MAX];
	HashFunction	*hashFunction;
}	Table;

void	TableInit(Table *table, HashFunction hashFunction);
void	TableInsert(Table *table, Key key, Value value);
Value	TableDelete(Table *table, Key key);
Value	TableSearch(Table *table, Key key);	

#endif
