#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack* ptr)
{
    if (ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
};

int isFull(struct stack* ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
};

int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
};

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
};

int stackBottom(struct stack* sp){
    return sp->arr[0];
};

int peek(struct stack* sp, int i){
    int arrayInd = sp->top -i + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
    }
};


int main() {
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int*)malloc(s->size* sizeof(int));
 
    // Check if stack is empty
    if(isEmpty(s)){
        printf("The stack is empty");
    }
    else{
        printf("The stack is not empty");
    }

    printf("Before pushing, Full: %d\n", isFull(s));    
    push(s,45);
    push(s,4);
    push(s,5);
    push(s,49);
    push(s,7);
    push(s,55);
    printf("Before pushing, Empty: %d\n", isEmpty(s));
   
    printf("Popped %d from the stack\n", pop(s));
    printf("Popped %d from the stack\n", pop(s));
    
    for (int j = 1; j <= s->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(s, j));
    }

    printf("The top most value of this stack is %d\n", stackTop(s));
    printf("The bottom most value of this stack is %d\n", stackBottom(s));

    return 0;

    
}
//Noriah Mudassir - B20102132