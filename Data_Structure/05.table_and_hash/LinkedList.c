#include "LinkedList.h"

void	ListInit(List *list)
{
	list->head = (Node *) malloc(sizeof(Node));
	list->head->next = NULL;
	list->before = NULL;
	list->current = list->head;
	list->tail = list->head;;
	list->numberOfData = 0;
}

void	ListInsert(List *list, ListData data)
{
	Node	*newNode = (Node *) malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = NULL;
	list->tail->next = newNode;
	list->numberOfData++;
}

Node	*ListCurrent(List *list)
{
	return (list->current);
}

Node	*ListNext(List *list)
{
	list->current = list->current->next;
	return (list->current);
}

ListData	ListGetData(List *list)
{
	return (list->current->data);
}

ListData	ListRemove(List *list)
{
	Node		*NodeToRemove = ListCurrent(list);
	ListData	backup = NodeToRemove->data;

	list->before->next = list->current->next;
	list->current = list->before;
	free(NodeToRemove);
	list->numberOfData--;
	return (backup);
}

Node	*ListFirst(List *list)
{
	list->current = list->head->next;
	list->before = list->head;
	return (list->current);
}
