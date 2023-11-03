#include "doubly_linked_list.h"

void	initialize_list(list *list);
void	add_node(list *list, int data);
void	print_node_data(const list *list);

int	main(void)
{
	list	list;

	initialize_list(&list);
	for (int i = 0; i < 8; i++)
		add_node(&list, i);
	print_node_data(&list);
	return (0);
}

void	initialize_list(list *list)
{
	list->head = (node *) malloc(sizeof(node));
	list->tail = (node *) malloc(sizeof(node));
	list->current = list->head;
	list->head->next = list->tail;
	list->head->prev = (void *) 0;
	list->tail->prev = list->head;
	list->tail->next = (void *) 0;
	list->number_of_data = 0;
}

void	add_node(list *list, int data)
{
	node	*new_node;

	new_node = (node *) malloc(sizeof(node));
	new_node->data = data;
	new_node->next = list->tail;
	new_node->prev = list->current;
	list->current->next = new_node;
	list->tail->prev = new_node;
	list->current = new_node;
	list->number_of_data++;
}

void	print_node_data(const list *list)
{
	node	*current;
	int		i;

	current = list->head->next;
	i = 0;
	while (current->next != (void *) 0)
	{
		printf("node[%d]->data: %d\n", i, current->data);
		current = current->next;
		i++;
	}
}
