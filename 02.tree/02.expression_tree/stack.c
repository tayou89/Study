#include "stack.h"

void	stack_init(Stack *stack)
{
	stack->head = NULL;
}

bool	is_empty(const Stack *stack)
{
	if (stack->head == NULL)
		return (true);
	else
		return (false);
}

void	push(Stack *stack, void *data)
{
	Node	*new_node = (Node *) malloc(sizeof(Node));

	new_node->data = data;
	new_node->next = NULL;
	if (stack->head == NULL)
		stack->head = new_node;
	else
	{
		new_node->next = stack->head;
		stack->head = new_node;
	}
}

void	*pop_up(Stack *stack)
{
	Node	*pop_up_node;
	void *	copy_data;

	pop_up_node = stack->head;
	stack->head = pop_up_node->next;
	copy_data = pop_up_node->data;
	free(pop_up_node);
	return (copy_data);
}

void	*peek(const Stack *stack)
{
	return (stack->head->data);
}
