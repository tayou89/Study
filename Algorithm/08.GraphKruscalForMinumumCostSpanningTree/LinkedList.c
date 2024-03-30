#include "LinkedList.h"
#include <stdlib.h>

void	ListInit(List *list)
{
	list->head = (Node *) malloc(sizeof(Node));
	list->head->next = NULL;
	list->tail = list->head;
	list->current = NULL;
	list->before = NULL;
	list->numberOfData = 0;
}

int		ListIsEmpty(List *list)
{
	if (list->numberOfData == 0)
		return (TRUE);
	else
		return (FALSE);
}

void	ListInsertFront(List *list, ListData data)
{
	Node	*newNode = (Node *) malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = list->head->next;
	list->head->next = newNode;
	if (list->numberOfData == 0)
		list->tail = newNode;
	list->numberOfData++;
}

void	ListInsertRear(List *list, ListData data)
{
	Node	*newNode = (Node *) malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = NULL;
	list->tail->next = newNode;
	list->tail = newNode;
	list->numberOfData++;
}

ListData	ListRemove(List *list)
{
	Node		*nodeToRemove = list->current;
	ListData	dataToRemove = nodeToRemove->data;

	if (list->current == list->tail)
		list->tail = list->before;
	list->before->next = list->current->next;
	list->current = list->before;
	free(nodeToRemove);
	list->numberOfData--;
	return (dataToRemove);
}

ListData	ListGetData(List *list)
{
	return (list->current->data);
}

int	ListFirst(List *list, ListData *data)
{
	if (list->head->next == NULL)
		return (FALSE);
	list->current = list->head->next;
	list->before = list->head;
	*data = list->current->data;
	return (TRUE);
}

int	ListNext(List *list, ListData *data)
{
	if (list->current->next == NULL)
		return (FALSE);
	list->before = list->current;
	list->current = list->current->next;
	*data = list->current->data;
	return (TRUE);
}

void	ListDestroy(List *list)
{
	ListData	data;

	ListFirst(list, &data);
	if (list->current == NULL)
		return ;
	ListRemove(list);
	list->numberOfData--;
	while (ListNext(list, &data) == TRUE)
	{
		ListRemove(list);
		list->numberOfData--;
	}
}
