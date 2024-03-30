#ifndef GRAPH_KRUSCAL_H
# define GRAPH_KRUSCAL_H

# include "LinkedList.h"
# include "priority_queue.h"
# include "GraphEdge.h"

enum	{A, B, C, D, E, F, G, H, I, J};

typedef struct Graph
{
	int		numberOfVertex;
	int		numberOfEdge;
	List	*listArray;
	int		*visitInfoArray;
	PQueue	pQueue;
}	Graph;

void	GraphInit(Graph *graph, int numberOfVertex);
void	GraphDestroy(Graph *graph);
void	AddEdge(Graph *graph, int fromVertex, int toVertex, int weight);
void	PrintGraphEdgeInfo(Graph *graph);
void	DFSPrintGraphVertex(Graph *graph, int startVertex);

void	MakeMinimumCostSpanningTree(Graph *graph);
void	RemoveEdge(Graph *graph, Edge edge);
void	RemoveOneWayEdge(Graph *graph, int fromVertex, int toVertex);
int		AreEdgeVerticesConnected(Graph *graph, int vertex1, int vertex2);
void	RecoverEdge(Graph *graph, Edge edge);
void	PrintGraphEdgeWeightInfo(Graph *graph);

#endif
