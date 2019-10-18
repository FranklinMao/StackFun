//
// Created by Franklin Mao on 10/2/2019.
// Driver for EquationChecker

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack_arr.h"

typedef struct exp {
    char equation[MAX_ELEMENTS];
} exp;


int main(int argc, char *argv[]) {

    FILE *fptr;
    fptr = fopen("exp.dat", "r");
    if (fptr == NULL) {
        printf("OOPS!\n");
        exit(-12);
    }
    Stack312 s;
    makeStack(&s);
    char equation[MAX_ELEMENTS];
    while(fgets(equation, MAX_ELEMENTS, fptr)) {


        //push(equation[0], &s);
        for(int i = 0; i < strlen(equation); i++) {

            if(equation[i] == '(')
                push(equation[i], &s);
            if(equation[i] == '[')
                push(equation[i], &s);
            if(equation[i] == '<')
                push(equation[i], &s);

            if(equation[i] == ')') {
                if (s.elements[s.top] == '(') {
                    pop(&s);
                }
                else {
                    push(equation[i], &s);
                }
            }
            if(equation[i] == ']') {
                if (s.elements[s.top] == '[') {
                    pop(&s);
                }
                else {
                    push(equation[i], &s);
                }
            }
            if(equation[i] == '>') {
                if (s.elements[s.top] == '<') {
                    pop(&s);
                }
                else {
                    push(equation[i], &s);
                }
            }

        }
        int newLine = 0;
        for(int i = 0; i< strlen(equation); i++) {
            if(equation[i] == '\n')
                newLine = i;
        }
        printf("%d", newLine);
        equation[strlen(equation)-2] = 0;

        printf("%s", equation);
  //      char *p = strchr(equation, '')
        if(isEmpty(s)) {

            printf(" === valid expression\n");
        }
        else if(!isEmpty(s)) {
            char missingChar;
            char remainChar = pop(&s);
            if(remainChar == '(')
                missingChar = ')';
            if(remainChar == ')')
                missingChar = '(';
            if(remainChar == '[')
                missingChar = ']';
            if(remainChar == ']')
                missingChar = '[';
            if(remainChar == '<')
                missingChar = '>';
            if(remainChar == '>')
                missingChar = '<';
            printf(" === missing %c\n", missingChar);
        }
    }
    fclose(fptr);
}
