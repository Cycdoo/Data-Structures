#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

void Traversal(struct node* ptr){
    while (ptr!=NULL){
        printf("\n Element:%d", ptr->data);
        ptr=ptr->next;
    }
};

struct node* InsertHead(struct node* head, int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
};

struct node* InsertBetween (struct node* head, int data, int index){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    int i=0;
        while (i!=index-1){
            p=p->next;
            i++;
        }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
};

struct node* InsertTail(struct node* head, int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    ptr->data=data;
        while (p->next!=NULL){
            p=p->next;
        }
    p->next=ptr;
    ptr->next=NULL;
    return head;
};

struct node* DeleteFirst(struct node* head){
    struct node* ptr=head;
    head=head->next;
    free(ptr);
    return head;
};

struct node* DeleteAtIndex(struct node* head, int index){
    struct node* p = head;
    struct node* q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
};

struct node* DeleteAtTail(struct node* head){
    struct node* p = head;
    struct node* q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

int main(){
    struct node* head;
    struct node* second;
    struct node* third;

    //memory allocation
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    //linking the nodes
    head->data=7;
    head->next=second;

    second->data=-34;
    second->next=third;

    //terminating the LL
    third->data=4;
    third->next=NULL;

    //Call the traversal function
    Traversal(head);

    //add new head 
    head = InsertHead(head,56);
    Traversal(head);

    //add new node at index
    head=InsertBetween(head,89,2);
    Traversal(head);

    //add new node at end
    head=InsertTail(head,99);
    Traversal(head);

    //deletion of head
    printf("\nBefore Deletion:");
    Traversal(head);
    head = DeleteFirst(head);
    printf("\nAfterDeletion:");
    Traversal(head);

    
    //deletion at Index
    printf("\nBefore Deletion:");
    Traversal(head);
    head = DeleteAtIndex(head,3);
    printf("\nAfterDeletion:");
    Traversal(head);

    //deletion of Tail
    printf("\nBefore Deletion:");
    Traversal(head);
    head = DeleteAtTail(head);
    printf("\nAfterDeletion:");
    Traversal(head);

return 0;
}


//Noriah Mudassir B20102132