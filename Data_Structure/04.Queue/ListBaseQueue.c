#include "ListBaseQueue.h"

void	queue_init(Queue *queue)
{
	queue->front = NULL;
	queue->rear = NULL;
}

int	queue_is_empty(const Queue *queue)
{
	if (queue->front == NULL)
		return (TRUE);
	else
		return (FALSE);
}

void	enqueue(Queue *queue, Data data)
{
	Node	*new_node;

	new_node = (Node *) malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	if (queue_is_empty(queue) == TRUE)
	{
		queue->front = new_node;
		queue->rear = new_node;
	}
	else
	{
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
}

Data	dequeue(Queue *queue)
{
	Node	*copy;
	Data	copy_data;

	if (queue_is_empty(queue) == TRUE)
	{
		printf("queue does not exist.\n");
		exit(1);
	}
	copy = queue->front;
	copy_data = copy->data;
	queue->front = queue->front->next;
	free(copy);
	return (copy_data);
}

Data	queue_peek(const Queue *queue)
{
	if (queue_is_empty(queue) == TRUE)
	{
		printf("queue does not exist.\n");
		exit(1);
	}
	return (queue->front->data);
}
