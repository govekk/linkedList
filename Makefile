CC = clang
CFLAGS = -g

SRCS = linkedlist.c main.c
HDRS = linkedlist.h value.h
OBJS = $(SRCS:.c=.o)

linkedlist: $(OBJS)
	$(CC)  $(CFLAGS) $^  -o $@

%.o : %.c $(HDRS)
	$(CC)  $(CFLAGS) -c $<  -o $@

clean:
	rm *.o
	rm linkedlist
