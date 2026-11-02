objects = src/main.o
CFLAGS = -Wall -Wextra -g
all: mysh
mysh: $(objects)
	gcc -o mysh $(objects)
src/main.o : src/main.c 
	gcc  $(CFLAGS) -c src/main.c -o src/main.o 
.PHONY: clean 
clean:
	rm -f mysh $(objects)