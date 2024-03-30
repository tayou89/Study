#ifndef DOUBLY_LINKED_LIST_H
# define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int	data;
	struct node	*next;
	struct node *prev;
}	node;

typedef struct double_linked_list
{
	node	*head;
	node	*current;
	node	*tail;
	int		number_of_data;
}	list;

#endif
