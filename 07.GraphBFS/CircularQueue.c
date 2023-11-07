#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>

static int	GetNextIndex(int index);

void	QueueInit(Queue *queue)
{
	queue->front = 0;
	queue->rear = 0;
}

int	QueueIsEmpty(Queue *queue)
{
	if (queue->front == queue->rear)
		return (TRUE);
	else
		return (FALSE);
}

static int	GetNextIndex(int index)
{
	if (index == ARRAY_MAX - 1)
		return (0);
	else
		return (index + 1);
}

void	EnQueue(Queue *queue, QueueData data)
{
	queue->rear = GetNextIndex(queue->rear);
	if (queue->rear == queue->front)
	{
		printf("Error: EnQueue: Queue memory is full.\n");
		exit(1);
	}
	queue->queueArray[queue->rear] = data;
}

QueueData	DeQueue(Queue *queue)
{
	if (QueueIsEmpty(queue) == TRUE)
	{
		printf("Error: DeQueue: Queue memory is empty.\n");
		exit(1);
	}
	queue->front = GetNextIndex(queue->front);
	return (queue->queueArray[queue->front]);
}

QueueData	QueuePeek(Queue *queue)
{
	if (QueueIsEmpty(queue) == TRUE)
	{
		printf("Error: QueuePeek: Queue memory is empty.\n");
		exit(1);
	}
	return (queue->queueArray[GetNextIndex(queue->front)]);
}
