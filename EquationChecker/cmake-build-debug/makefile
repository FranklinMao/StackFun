# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

EquationChecker: stack_arr.o EquationChecker.o
	c99 -o EquationChecker stack_arr.o EquationChecker.o

stack_arr.o: stack_arr.c
	c99 -c stack_arr.c

EquationChecker.o: EquationChecker.c
	c99 -c EquationChecker.c
