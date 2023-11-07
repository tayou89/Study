#include "BFSGraph.h"

int	main(void)
{
	Graph	graph;

	GraphInit(&graph, 7);

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, C);
	AddEdge(&graph, B, C);
	AddEdge(&graph, D, C);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);

	PrintGraphEdgeInfo(&graph);

	BFSPrintGraphVertex(&graph, A);
	BFSPrintGraphVertex(&graph, C);
	BFSPrintGraphVertex(&graph, E);
	BFSPrintGraphVertex(&graph, G);
	return (0);
}
