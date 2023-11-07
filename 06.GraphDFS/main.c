#include "DFSGraph.h"

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

	DFSPrintGraphVertex(&graph, D);
	DFSPrintGraphVertex(&graph, A);
	DFSPrintGraphVertex(&graph, B);
	DFSPrintGraphVertex(&graph, C);
	DFSPrintGraphVertex(&graph, G);
	return (0);
}
