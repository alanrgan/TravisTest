#pragma once
#include <stdlib.h>

typedef struct {
	void *arr;
	size_t capacity;
} queue_t;

queue_t *queue_create(size_t);
void queue_push(queue_t *, void *);
void *queue_pull(queue_t *);