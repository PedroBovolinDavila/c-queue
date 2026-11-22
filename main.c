#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
	int val;
	struct Node* next;
} Node;

typedef struct {
	Node* start;
	Node* end;
} Queue;

void show(const Queue queue);
int enqueue(Queue* queue, int val);
int dequeue(Queue* queue, int* val);
int front(const Queue* queue, int* val);
int back(const Queue* queue, int* val);
int size(const Queue* queue);
int contains(const Queue* queue, const int val);
void clear(Queue* queue);

int main() {
	Queue queue = { NULL, NULL };
	int val;

	printf("Fila:\n");
	show(queue);

	enqueue(&queue, 10);
	enqueue(&queue, 20);
	enqueue(&queue, 30);
	enqueue(&queue, 40);

	printf("\nApos insercoes:\n");
	show(queue);

	if (dequeue(&queue, &val))
		printf("\nRemovido: %d\n", val);

	show(queue);

	while (dequeue(&queue, &val)) {
		printf("Removido: %d\n", val);
	}

	printf("\nFila apos todas as remocoes:\n");
	show(queue);

	if (!dequeue(&queue, &val))
		printf("\nNao foi possivel remover: fila vazia!\n");

	enqueue(&queue, 100);

	printf("\nApos inserir novamente:\n");
	show(queue);

	return 0;
}

void show(const Queue queue) {
	const Node* aux = queue.start;

	while (aux != NULL) {
		printf("%d -> ", aux->val);
		aux = aux->next;
	}

	puts("NULL");
}

int enqueue(Queue* queue, int val) {
	if (queue == NULL) return 0;

	Node* node = malloc(sizeof(Node));
	if (node == NULL) return 0;

	node->val = val;
	node->next = NULL;

	if (queue->end == NULL) {
		queue->end = queue->start = node;
	} else {
		queue->end->next = node;
		queue->end = node;
	}

	return 1;
}

int dequeue(Queue* queue, int* val) {
	if (queue == NULL || val == NULL) return 0;

	Node* node = queue->start;
	if (node == NULL) return 0;

	*val = node->val;
	queue->start = node->next;
	
	if (queue->start == NULL) queue->end = NULL;

	free(node);
	node = NULL;

	return 1;
}

int front(const Queue* queue, int* val) {
	if (queue == NULL || val == NULL || queue->start == NULL)
		return 0;

	*val = queue->start->val;
	return 1;
}

int back(const Queue* queue, int* val) {
	if (queue == NULL || val == NULL || queue->start == NULL)
		return 0;

	*val = queue->end->val;
	return 1;
}

int size(const Queue* queue) {
	if (queue == NULL) return -1;
	int size = 0;

	for (const Node* aux = queue->start; aux != NULL; aux = aux->next)
		size++;

	return size;
}

// Sequential Search
int contains(const Queue* queue, const int val) {
	if (queue == NULL) return 0;

	for (const Node* aux = queue->start; aux != NULL; aux = aux->next) {
		if (aux->val == val) return 1;
	}

	return 0;
}

void clear(Queue* queue) {
	if (queue == NULL) return;

	Node* aux = queue->start;

	while (aux != NULL) {
		Node* next = aux->next;

		free(aux);
		aux = next;
	}

	queue->end = queue->start = NULL;
}
