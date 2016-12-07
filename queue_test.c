#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

void *char_copy_constructor(void *c) { return c; }
void char_destructor(void *c) { free(c); }

int main() {
	queue_t *charq = queue_create(char_copy_constructor, char_destructor);
	for(int i = 0; i < 26; i++) {
		char *c = malloc(sizeof(char));
		*c = (char)(97+i);
		queue_push(charq, c);
	}

	for(int i = 0; i < 27; i++) {
		char *c = (char *)queue_pull(charq);
		if(!c && i != 26) {
			printf("pull result is NULL at iteration %d\n", i);
			exit(1);
		} else if(i == 26 && c != NULL) {
			exit(1);	
		} 

		if(c && *c != (97+i)) {
			exit(1);
		}
	}
	return 0;
}