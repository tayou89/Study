#include "DFSGraph.h"
#include "ArrayBaseStack.h"
#include <stdlib.h>
#include <string.h>

static int	VisitVertex(Graph *graph, int visitVertex);
static int	RecordVisit(Stack *stack, int *visitFlag, int visitVertex, int nextVertex);

void	GraphInit(Graph *graph, int numberOfVertex)
{
	int	i;

	graph->numberOfVertex = numberOfVertex;
	graph->numberOfEdge = 0;
	graph->listArray = (List *) malloc(sizeof(List) * numberOfVertex);
	for (i = 0; i < numberOfVertex; i++)
		ListInit(&(graph->listArray[i]));
	graph->visitInfoArray = (int *) malloc(sizeof(int) * numberOfVertex);
	memset(graph->visitInfoArray, 0, sizeof(int) * numberOfVertex);
}

void	GraphDestroy(Graph *graph)
{
	int	i;

	for (i = 0; i < graph->numberOfVertex; i++)
	{
		ListDestroy(&(graph->listArray[i]));
		free(graph->listArray[i].head);
	}
	free(graph->listArray);
	free(graph->visitInfoArray);
}

void	AddEdge(Graph *graph, int fromVertex, int toVertex)
{
	ListInsertRear(&(graph->listArray[fromVertex]), toVertex);
	ListInsertRear(&(graph->listArray[toVertex]), fromVertex);
	graph->numberOfEdge++;
}

void	PrintGraphEdgeInfo(Graph *graph)
{
	List		*list;
	ListData	data;
	int			i;

	for (i = 0; i < graph->numberOfVertex; i++)
	{
		printf("graph->listArray[%c]", i + 65);
		list = &(graph->listArray[i]);
		if (ListFirst(list, &data) == FALSE)
			continue ;
		printf(" -> %c", data + 65);
		while (ListNext(list, &data) == TRUE)
			printf(" -> %c", data + 65);
		printf("\n");
	}
}

void	DFSPrintGraphVertex(Graph *graph, int startVertex)
{
	int		visitVertex = startVertex;
	int		nextVertex;
	int		visitFlag;
	Stack	stack;

	StackInit(&stack);
	VisitVertex(graph, visitVertex);
	StackPush(&stack, visitVertex);
	while (ListFirst(&(graph->listArray[visitVertex]), &nextVertex) == TRUE)
	{
		visitFlag = FALSE;
		if (VisitVertex(graph, nextVertex) == TRUE)
			visitVertex = RecordVisit(&stack, &visitFlag, visitVertex, nextVertex);
		else
		{
			while (ListNext(&(graph->listArray[visitVertex]), &nextVertex) == TRUE)
			{
				if (VisitVertex(graph, nextVertex) == TRUE)
				{
					visitVertex = RecordVisit(&stack, &visitFlag, visitVertex, nextVertex);
					break ;
				}
			}
		}
		if (visitFlag == FALSE)
		{
			if (StackIsEmpty(&stack) == TRUE)
				break ;
			else
				visitVertex = StackPop(&stack);
		}
	}
	printf("\n");
	memset(graph->visitInfoArray, 0, sizeof(int) * graph->numberOfVertex);
}

static int	VisitVertex(Graph *graph, int visitVertex)
{
	if (graph->visitInfoArray[visitVertex] == 1)
		return (FALSE);
	graph->visitInfoArray[visitVertex] = 1;
	printf("%c ", visitVertex + 65);
	return (TRUE);
}

static int RecordVisit(Stack *stack, int *visitFlag, int visitVertex, int nextVertex)
{
	StackPush(stack, visitVertex);
	*visitFlag = TRUE;
	return (nextVertex);
}
