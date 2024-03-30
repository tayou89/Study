#ifndef CIRCULAR_QUEUE_H
# define CIRCULAR_QUEUE_H

# define ARRAY_MAX	100

# define TRUE		1
# define FALSE		0

typedef int	QueueData;

typedef struct	CircularQueue
{
	int			front;
	int			rear;
	QueueData	queueArray[ARRAY_MAX];
}	CircularQueue;

typedef CircularQueue	Queue;

void		QueueInit(Queue *queue);
int			QueueIsEmpty(Queue *queue);
void		EnQueue(Queue *queue, QueueData data);
QueueData	DeQueue(Queue *queue);
QueueData	QueuePeek(Queue *queue);	

#endif
