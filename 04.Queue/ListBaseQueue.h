#ifndef LISTBASEQUEUE_H
# define LISTBASEQUEUE_H

# define TRUE	1
# define FALSE	0

typedef int	Data;

typedef struct Node
{
	Data		data;
	struct Node	*next;
}	Node;

typedef struct Queue
{
	Node	*front;
	Node	*rear;
}	Queue;

void	queue_init(Queue *queue);
int		queue_is_empty(const Queue *quque);

void	enqueue(Queue *queue, Data data);
Data	dequeue(Queue *queue);
Data	queue_peek(const Queue *queue);

#endif
