#include "GraphKruscal.h"
#include "ArrayBaseStack.h"
#include <stdlib.h>
#include <string.h>

static int	VisitVertex(Graph *graph, int visitVertex);
static int	RecordVisit(Stack *stack, int *visitFlag, int visitVertex, int nextVertex);
int			PQWeightCompare(Edge edge1, Edge edge2);

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
	pQueue_init(&(graph->pQueue), PQWeightCompare);
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

void	AddEdge(Graph *graph, int fromVertex, int toVertex, int weight)
{
	Edge	edge = {fromVertex, toVertex, weight};

	ListInsertRear(&(graph->listArray[fromVertex]), toVertex);
	ListInsertRear(&(graph->listArray[toVertex]), fromVertex);
	graph->numberOfEdge++;
	enPQueue(&(graph->pQueue), edge);
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
//	StackPush(&stack, visitVertex);
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

int	PQWeightCompare(Edge edge1, Edge edge2)
{
	return (edge1.weight - edge2.weight);
}

void	MakeMinimumCostSpanningTree(Graph *graph)
{
	Edge	edge;
	Edge	recoveredEdge[30];
	int		index = 0;
	int		i;

	while (graph->numberOfEdge + 1 > graph->numberOfVertex)
	{
		edge = dePQueue(&(graph->pQueue));
		RemoveEdge(graph, edge);
		if (AreEdgeVerticesConnected(graph, edge.vertex1, edge.vertex2) == FALSE)
		{
			RecoverEdge(graph, edge);
			recoveredEdge[index++] = edge;
		}
	}
	for (i = 0; i < index ; i++)
		enPQueue(&(graph->pQueue), recoveredEdge[i]);
}

void	RemoveEdge(Graph *graph, Edge edge)
{
	RemoveOneWayEdge(graph, edge.vertex1, edge.vertex2);
	RemoveOneWayEdge(graph, edge.vertex2, edge.vertex1);
	graph->numberOfEdge--;
}

void	RemoveOneWayEdge(Graph *graph, int fromVertex, int toVertex)
{
	int	vertex;

	if (ListFirst(&(graph->listArray[fromVertex]), &vertex) == TRUE)
	{
		if (vertex == toVertex)
		{
			ListRemove(&(graph->listArray[fromVertex]));
			return ;
		}
		while (ListNext(&(graph->listArray[fromVertex]), &vertex) == TRUE)
		{
			ListRemove(&(graph->listArray[fromVertex]));
			return ;
		}
	}
}

int	AreEdgeVerticesConnected(Graph *graph, int vertex1, int vertex2)
{
	int		visitVertex = vertex1;
	int		nextVertex;
	int		visitFlag;
	Stack	stack;

	StackInit(&stack);
	VisitVertex(graph, visitVertex);
	while (ListFirst(&(graph->listArray[visitVertex]), &nextVertex) == TRUE)
	{
		visitFlag = FALSE;
		if (nextVertex == vertex2)
		{
			memset(graph->visitInfoArray, 0, sizeof(int) * graph->numberOfVertex);
			return (TRUE);
		}
		if (VisitVertex(graph, nextVertex) == TRUE)
		{
			StackPush(&stack, visitVertex);
			visitFlag = TRUE;
			visitVertex = nextVertex;
		}
		else
		{
			while (ListNext(&(graph->listArray[visitVertex]), &nextVertex) == TRUE)
			{
				if (nextVertex == vertex2)
				{
					memset(graph->visitInfoArray, 0, sizeof(int) * graph->numberOfVertex);
					return (TRUE);
				}
				if (VisitVertex(graph, nextVertex) == TRUE)
				{
					StackPush(&stack, visitVertex);
					visitFlag = TRUE;
					visitVertex = nextVertex;
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
	memset(graph->visitInfoArray, 0, sizeof(int) * graph->numberOfVertex);
	return (FALSE);
}

void	RecoverEdge(Graph *graph, Edge edge)
{
	ListInsertRear(&(graph->listArray[edge.vertex1]), edge.vertex2);
	ListInsertRear(&(graph->listArray[edge.vertex2]), edge.vertex1);
	graph->numberOfEdge++;
}

void	PrintGraphEdgeWeightInfo(Graph *graph)
{
	PQueue	copyPQueue = graph->pQueue;
	Edge	edge;

	while (pQueue_is_empty(&copyPQueue) == FALSE)
	{
		edge = dePQueue(&copyPQueue);
		printf("(%c - %c) Weight: %d\n", edge.vertex1 + 65, edge.vertex2 + 65, edge.weight);
	}
}
