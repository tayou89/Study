#ifndef ARRAY_BASE_STACK_H
# define ARRAY_BASE_STACK_H

# include <stdio.h>

# define TRUE		1
# define FALSE		0

# define STACK_MAX	100

typedef int	StackData;

typedef struct ArrayBaseStack
{
	StackData	stackArray[STACK_MAX];
	int			topIndex;
}	Stack;

void		StackInit(Stack *stack);
int			StackIsEmpty(Stack *stack);

void		StackPush(Stack *stack, StackData data);
StackData	StackPop(Stack *stack);
StackData	StackPeek(Stack *stack);

#endif
