CC = gcc
# Removed -c from CFLAGS so the compiler links the executable properly
CFLAGS = -Wall

# The names of your final executable files
all: task1 task2

# Compiles the source directly into an executable 'task1'
task1: task1.c
	$(CC) $(CFLAGS) task1.c -o task1

# Compiles the source directly into an executable 'task2'
task2: task2.c
	$(CC) $(CFLAGS) task2.c -o task2

clean:
	rm -f task1 task2 *.o