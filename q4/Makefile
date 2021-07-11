V=@

.PHONY: all clean
all: queue

clean:
	$(V) rm -f *.o queue

queue.o:
	$(V) gcc -Wall -std=c11 -c queue.c -g -O0

queue: queue.o
	$(V) gcc -Wall -o queue queue.o -lpthread
