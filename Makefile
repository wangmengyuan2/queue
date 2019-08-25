all: main

srcs = $(wildcard *.c)
objects = $(patsubst %.c, %.o, $(srcs))

main: $(objects) 
	gcc -o main $(objects)


.PHONY:clean

# rm -f
clean:
	$(RM)  *.o main
