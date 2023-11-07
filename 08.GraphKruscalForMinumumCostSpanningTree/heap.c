#include "heap.h"

void	heap_init(Heap *heap, Function function)
{
	heap->function = function;
	heap->numberOfData = 0;
}

int	heap_is_empty(const Heap *heap)
{
	if (heap->numberOfData == 0)
		return (TRUE);
	else
		return (FALSE);
}

int	get_parent_index(int index)
{
	return (index / 2);
}

int	get_left_child_index(int index)
{
	return (index * 2);
}

int	get_right_child_index(int index)
{
	return (get_left_child_index(index) + 1);
}

int	get_higher_child_index(Heap *heap, int parent_index)
{
	if (get_left_child_index(parent_index) > heap->numberOfData)
		return (0);
	else if (get_left_child_index(parent_index) == heap->numberOfData)
		return (get_left_child_index(parent_index));
	else
	{
		if (heap->function(heap->heapArray[get_left_child_index(parent_index)], 
			heap->heapArray[get_right_child_index(parent_index)]) > 0)
			return (get_left_child_index(parent_index));
		else
			return (get_right_child_index(parent_index));
	}
}

void	heap_insert(Heap *heap, HeapData data)
{
	int			index = heap->numberOfData + 1;

	while (index != 1 && 
			(heap->function(data, heap->heapArray[get_parent_index(index)]) > 0))
	{
		heap->heapArray[index] = heap->heapArray[get_parent_index(index)];
		index = get_parent_index(index);
	}
	heap->heapArray[index] = data;
	heap->numberOfData++;
}

HeapData	heap_delete(Heap *heap)
{
	HeapData	backup = heap->heapArray[1];
	HeapData	last_data = heap->heapArray[heap->numberOfData];
	int			parent_index = 1;
	int			child_index;

	child_index = get_higher_child_index(heap, parent_index);
	while (child_index != 0 &&
			heap->function(last_data, heap->heapArray[child_index]) < 0)
	{
		heap->heapArray[parent_index] = heap->heapArray[child_index];
		parent_index = child_index;
		child_index = get_higher_child_index(heap, parent_index);
	}
	heap->heapArray[parent_index] = last_data;
	heap->numberOfData--;
	return (backup);
}
