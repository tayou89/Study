#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stdbool.h>

# include "binary_tree.h"

typedef struct Node
{
	void		*data;
	struct Node	*next;
}	Node;

typedef struct Stack
{
	Node	*head;
}	Stack;

void	stack_init(Stack *stack);
bool	is_empty(const Stack *stack);
void	push(Stack *stack, void *data);
void	*pop_up(Stack *stack);
void	*peek(const Stack *stack);

#endif
