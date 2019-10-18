# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

StackFun: stack_ll.o floodfill.o
	c99 -o StackFun stack_ll.o floodfill.o

stack_ll.o: stack_ll.c
	c99 -c stack_ll.c

floodfill.o: floodfill.c
	c99 -c floodfill.c
