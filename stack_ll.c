//
// Created by Franklin Mao on 10/1/2019.
// implementation for stack_ll.h

#include <stdlib.h>
#include "stack_ll.h"

void makeStack(Stack312 *s) {
    s->top=NULL;
}

bool isFull(Stack312 s) {
    return false;
}

bool isEmpty(Stack312 s) {
    return (s.top == NULL);
}

void push(StackEntry e, Stack312 *s) {
    StackNode *temp = (StackNode*) malloc(sizeof(StackNode));
    temp->pixel = e;
    temp->next = s->top;
    s->top = temp;
}

StackEntry pop(Stack312 *s) {
    StackNode *tempPointer;
    while(isEmpty(*s)) {
    }
    tempPointer = s->top;
    StackEntry pixel = tempPointer->pixel;
    s->top = s->top->next;
    free(tempPointer);
    return pixel;
}