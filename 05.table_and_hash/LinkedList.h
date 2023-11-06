#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include <stdlib.h>
# include "Slot.h"

typedef Slot	ListData;

typedef	struct Node
{
	ListData	data;
	struct Node	*next;
}	Node;

typedef struct LinkedList
{
	Node	*head;
	Node	*before;
	Node	*current;
	Node	*tail;
	int		numberOfData;	
}	LinkedList;

typedef LinkedList	List;

void		ListInit(List *list);
void		ListInsert(List *list, ListData data);
Node		*ListCurrent(List *list);
Node		*ListFirst(List *list);
Node		*ListNext(List *list);
ListData	ListGetData(List *list);
ListData	ListRemove(List *list);

#endif
