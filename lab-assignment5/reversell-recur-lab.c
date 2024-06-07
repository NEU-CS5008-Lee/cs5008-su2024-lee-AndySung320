//enter your name and email here
// name: Di-En Sung
// email: sung.di@northeastern.edu.tw
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node_t;

typedef struct list{
    struct node* head;
}List;

/*-----creating the nodes----------*/
node_t* newNode(int num)
{
    node_t* new = (node_t*)malloc(sizeof(node_t));
    if(new == NULL){
    printf("Memory is not allocated\n");
    exit(1);
    }
    new->data = num;
    new->next = NULL;
    return new;
}
/*---creating linked list----*/
List* init_LL(){

    List* l = (List*)malloc(sizeof(List));
    if (l == NULL){
        printf("Memory is not allocated\n");
        exit(1);
    }
    l->head = NULL;
    return l;
}

/*---Insert the nodes at the begining of the list---*/
void insertFirst(List* l, int data){
    node_t* new = newNode(data);
    if (l->head == NULL){
        l->head = new;
        return;
    }
    else{
        new->next = l->head;
        l->head = new;
        return;
    }

}

/*----display the output--------*/
void display(List* l)
{
    node_t *temp;
    temp=l->head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

/*-------reversing the linked list using recursion------*/
void reverse(List* l, node_t* ptr)
{    
//insert your code here
    if(ptr == NULL) {
        return;
    }
    if (ptr->next == NULL){
        l->head = ptr;
        return;
    }

    reverse(l, ptr->next); // recursively traverse the list
    ptr->next->next = ptr; // reverse the pointer direction
    ptr->next = NULL; // and then set to null
}

/*----Free the nodes-----*/
void freenode(List* l){
  node_t *temp;
    while(l->head)
    {
        temp=l->head->next;
        free(l->head);
        l->head=temp;
    }  
    
}
/*-----Main program--------------*/
int main()
{
    List *list=init_LL();
    

    insertFirst(list,44);
    insertFirst(list,33);
    insertFirst(list,22);
    insertFirst(list,11);
    display(list);
    reverse(list,list->head);
    display(list);
    
    freenode(list);
    free(list);
    return 0;
}
