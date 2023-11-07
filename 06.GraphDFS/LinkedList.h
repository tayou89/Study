#ifndef Linked_List_H
# define Linked_List_H

typedef int	ListData;

# define TRUE	1
# define FALSE	0

typedef struct Node
{
	ListData	data;
	struct Node	*next;
}	Node;

typedef struct LinkedList
{
	Node	*head;
	Node	*tail;
	Node	*current;
	Node	*before;
	int		numberOfData;
}	LinkedList;

typedef LinkedList	List;

void		ListInit(List *list);
int			ListIsEmpty(List *list);

void		ListInsertFront(List *list, ListData data);
void		ListInsertRear(List *list, ListData data);

ListData	ListRemove(List *list);
ListData	ListGetData(List *list);

int			ListFirst(List *list, ListData *data);
int			ListNext(List *list, ListData *data);
void		ListDestroy(List *list);

#endif
