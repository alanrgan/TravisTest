#include "queue.h"

queue_t *queue_create(copy_constructor_t cconstructor, destructor_t destructor) {
	queue_t *q = malloc(sizeof(queue_t));
	q->size = 0;
	q->cconstructor = cconstructor;
	q->destructor = destructor;
	q->head = NULL;
	q->tail = NULL;
	return q;
}

void queue_push(queue_t *queue, void *data) {
	void *data_copy = queue->cconstructor(data);
	queue_elem_t *next_elem = malloc(sizeof(queue_elem_t));
	next_elem->data = data_copy;
	next_elem->next = NULL;
	if(queue->head == NULL) {
		queue->head = next_elem;
		queue->tail = queue->head;
	} else {
		queue->tail->next = next_elem;
		queue->tail = queue->tail->next;
	}
	queue->size++;
}

void *queue_pull(queue_t *queue) {
	if(!queue->head) return NULL;
	queue_elem_t *temp = queue->head;
	queue->head = queue->head->next;
	queue->size--;
	return temp->data;
}