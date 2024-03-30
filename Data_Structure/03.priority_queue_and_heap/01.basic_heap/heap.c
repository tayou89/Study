#include "heap.h"

void	heap_init(Heap *heap)
{
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
		if (heap->elementArray[get_left_child_index(parent_index)].priority
			<= heap->elementArray[get_right_child_index(parent_index)].priority)
			return (get_left_child_index(parent_index));
		else
			return (get_right_child_index(parent_index));
	}
}

void	heap_insert(Heap *heap, Data data, Priority priority)
{
	int		index = heap->numberOfData + 1;
	Element	new_element = {priority, data};

	while (index != 1 && (priority < heap->elementArray[get_parent_index(index)].priority))
	{
		heap->elementArray[index] = heap->elementArray[get_parent_index(index)];
		index = get_parent_index(index);
	}
	heap->elementArray[index] = new_element;
	heap->numberOfData++;
}

Data	heap_delete(Heap *heap)
{
	Data	backup = heap->elementArray[1].data;
	Element	last_element = heap->elementArray[heap->numberOfData];
	int		parent_index = 1;
	int		child_index;

	child_index = get_higher_child_index(heap, parent_index);
	while (child_index != 0 && 
			(last_element.priority > heap->elementArray[child_index].priority))
	{
		heap->elementArray[parent_index] = heap->elementArray[child_index];
		parent_index = child_index;
		child_index = get_higher_child_index(heap, parent_index);
	}
	heap->elementArray[parent_index] = last_element;
	heap->numberOfData--;
	return (backup);
}
