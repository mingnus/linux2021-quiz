.PHONY: all clean
all: proxy

clean:
	@rm *.o proxy

proxy.o: proxy.c
	@gcc -c proxy.c -g -O0

proxy: proxy.o
	@gcc -o proxy proxy.o
