#include <stdlib.h>

#include "queue.h"

int main() {
	queue_t *charq = queue_create(10);
	for(int i = 0; i < 26; i++) {
		char *c = malloc(sizeof(char));
		*c = (char)(97+i);
		queue_push(charq, c);
	}

	for(int i = 0; i < 26; i++) {
		if(*(char *)queue_pull(charq) != (97+i)) {
			exit(1);
		}
	}
	return 0;
}