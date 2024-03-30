#include "GraphKruscal.h"
#include <stdio.h>

int	main(void)
{
	Graph	graph;

	GraphInit(&graph, 7);

	AddEdge(&graph, A, B, 3);
	AddEdge(&graph, A, C, 13);
	AddEdge(&graph, B, C, 5);
	AddEdge(&graph, D, C, 8);
	AddEdge(&graph, D, E, 20);
	AddEdge(&graph, E, F, 10);
	AddEdge(&graph, E, G, 6);

	PrintGraphEdgeInfo(&graph);
	PrintGraphEdgeWeightInfo(&graph);
	printf("\n");

	MakeMinimumCostSpanningTree(&graph);
	PrintGraphEdgeInfo(&graph);
	PrintGraphEdgeWeightInfo(&graph);
	return (0);
}
