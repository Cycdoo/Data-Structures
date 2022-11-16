#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
struct node{
    int data;
    struct node* next;
};

 struct node* top = NULL;
 
void Traversal(struct node* ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; 
    }
};
 
int isEmpty(struct node* top){
    if (top==NULL){
        return 1;
    }
    else{
        return 0;
    }
};
 
int isFull(struct node* top){
    struct Node* p = (struct Node*)malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
};
 
struct node* push(struct node* top, int x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct node* n = (struct node*) malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
    return 0;
};
 
int pop(struct node** top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
    }
    else{
        struct node* n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x; 
    }
    return 0;
};

int peek(int pos){
    struct node* ptr = top;
    for (int i = 0; (i < pos-1 && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
};
 
int main(){
   

    //push operation
    top = push(top, 48);
    top = push(top, 76);
    top = push(top, 28);
    top = push(top, 56);
    top = push(top, 8);
    
    Traversal(top);

    //pop operation
    int element = pop(&top);
    printf("Popped element is %d\n", element);
    Traversal(top);

    //peek
    for (int i = 1; i <= 4; i++)
    {
        printf("Value at position %d is : %d\n", i, peek(i));
    }

    return 0;

}
//Noriah Mudassir B20102132