#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

int main() {
	queue_t *charq = queue_create(10);
	for(int i = 0; i < 26; i++) {
		char *c = malloc(sizeof(char));
		*c = (char)(97+i);
		queue_push(charq, c);
	}

	for(int i = 0; i < 26; i++) {
		char *c = (char *)queue_pull(charq);
		if(!c) {
			printf("pull result is NULL\n");
			exit(1);
		}
		if(*c != (97+i)) {
			exit(1);
		}
	}
	return 0;
}