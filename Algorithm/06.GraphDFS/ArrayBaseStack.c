#include "ArrayBaseStack.h"

void	StackInit(Stack *stack)
{
	stack->topIndex = -1;
}

int	StackIsEmpty(Stack *stack)
{
	if (stack->topIndex == -1)
		return (TRUE);
	else
		return (FALSE);
}

void	StackPush(Stack *stack, StackData data)
{
	int	indexToPush = stack->topIndex + 1;

	if (indexToPush >= STACK_MAX)
	{
		printf("Error: push.\nStack memory is already full.\n");
		return ;
	}
	stack->stackArray[indexToPush] = data;
	stack->topIndex++;
}

StackData	StackPop(Stack *stack)
{
	StackData	dataToPop = stack->stackArray[stack->topIndex];

	stack->topIndex--;
	return (dataToPop);
}

StackData	StackPeek(Stack *stack)
{
	return (stack->stackArray[stack->topIndex]);
}
