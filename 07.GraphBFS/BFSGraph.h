#ifndef DFS_GRAPH_H
# define DFS_GRAPH_H

# include "LinkedList.h"

enum	{A, B, C, D, E, F, G, H, I, J};

typedef struct Graph
{
	int		numberOfVertex;
	int		numberOfEdge;
	List	*listArray;
	int		*visitInfoArray;
}	Graph;

void	GraphInit(Graph *graph, int numberOfVertex);
void	GraphDestroy(Graph *graph);
void	AddEdge(Graph *graph, int fromVertex, int toVertex);
void	PrintGraphEdgeInfo(Graph *graph);
void	BFSPrintGraphVertex(Graph *graph, int startVertex);

#endif
