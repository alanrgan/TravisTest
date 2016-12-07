OBJS_DIR = .objs

CC = gcc
WARNINGS = -Wall -Wextra -Werror -Wno-error=unused-parameter
CFLAGS_RELEASE = -O2 $(WARNINGS) -g -std=c99 -c -MMD -MP -D_GNU_SOURCE -I.

LD = gcc

OBJS_FILES=queue_test.o queue.o

.PHONY: all
all: release

.PHONY: release
release: test
	./queue_test

-include $(OBJS_DIR)/*.d

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@mkdir -p $(basename $@)
	$(CC) $(CFLAGS_RELEASE) $< -o $@

test: $(OBJS_FILES:%.o=$(OBJS_DIR)/%.o)#queue_test.o queue.o
	$(LD) $^ -o queue_test

.PHONY: clean
clean:
	-rm -rf .objs queue_test

#queue.o: queue.c queue.h
#	$(CC) $(CFLAGS_RELEASE) queue.c