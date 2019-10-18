//
// Created by Franklin Mao on 10/2/2019.
// Implementation for stack_arr.h

#include "stack_arr.h"


void makeStack(Stack312 *s){
    s->top = -1;
}

bool isFull(Stack312 s){
    return (s.top == (MAX_ELEMENTS-1));
}

bool isEmpty(Stack312 s){
    return (s.top == -1);
}

void push(StackEntry e,Stack312 *s){
    if(isFull(*s)) {
        return;
    }
    (s->top)++;
    s->elements[s->top] = e;
}

StackEntry pop(Stack312 *s){
    while(isEmpty(*s)){
    }
    StackEntry e = s->elements[s->top];
    (s->top)--;
    return e;
}