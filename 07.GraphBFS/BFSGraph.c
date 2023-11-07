#include "BFSGraph.h"
#include "CircularQueue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int	VisitVertex(Graph *graph, int visitVertex);

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

void	BFSPrintGraphVertex(Graph *graph, int startVertex)
{
	int		visitVertex = startVertex;
	int		nextVertex;
	Queue	queue;

	QueueInit(&queue);
	VisitVertex(graph, visitVertex);
	while (ListFirst(&(graph->listArray[visitVertex]), &nextVertex) == TRUE)
	{
		if (VisitVertex(graph, nextVertex) == TRUE)
			EnQueue(&queue, nextVertex);
		while (ListNext(&(graph->listArray[visitVertex]), &nextVertex) == TRUE)
		{
			if (VisitVertex(graph, nextVertex) == TRUE)
				EnQueue(&queue, nextVertex);
		}
		if (QueueIsEmpty(&queue) == TRUE)
			break ;
		else
			visitVertex = DeQueue(&queue);
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
