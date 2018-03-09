CFLAGS= -g

ringbuf:ringbuf.o test.o
	gcc -o $@ $^

clean:
	rm -f *.o

c:clean
