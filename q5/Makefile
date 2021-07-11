V=@

.PHONY: all clean
all: test

clean:
	$(V) rm -f *.o test

mpool.o: mpool.c mpool.h
	$(V) gcc -c mpool.c -g -O0

mpool_test.o: mpool_test.c mpool.h
	$(V) gcc -c mpool_test.c -g -O0

test: mpool.o mpool_test.o
	$(V) gcc -o test mpool.o mpool_test.o
