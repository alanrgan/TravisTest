#pragma once
#include <stdlib.h>

typedef void *(*copy_constructor_t)(void *);
typedef void (*destructor_t)(void *);

typedef struct queue_elem_t {
	void *data;
	struct queue_elem_t *next;
} queue_elem_t;

typedef struct {
	//queue_elem_t *arr;
	size_t size;
	copy_constructor_t cconstructor;
	destructor_t destructor;
	queue_elem_t *head, *tail;
} queue_t;

queue_t *queue_create(copy_constructor_t, destructor_t);
void queue_push(queue_t *, void *);
void *queue_pull(queue_t *);