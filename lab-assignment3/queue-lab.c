// name: Di-En Sung
// email: sung.di@northeastern.edu.tw

#include <stdio.h>
#define N 8 //Max. capacity of Queue

static int rear=-1;
static int front=-1;
/*----To check if the queue is empty-------*/
int isempty()
{   
    if(rear==-1)
        return 1;
    else
        return 0;
}

/*-----To check if the queue is full----------*/
int isfull()
{
    if(rear==N-1)
        return 1;
    return 0;
 
}

/*---- To see the data at the front of the queue---*/
int peek(int *arr)
{
    if(isempty()){
        printf("Queue is empty.\n");
        return -1;
    }
    return arr[0];
}

/*---To insert the elements into the queue------*/
void enqueue(int data, int *arr)
{
    //insert your code here
    if (isfull(*arr)){
        printf("Queue is full.\n");
    }
    else{
        arr[rear+1] = data;
        rear ++;
    }
}

/*----Function to remove the elements from the queue----*/
int dequeue(int *arr)
{   
    //insert your code here
    if (isempty(*arr)){
        printf("Queue is empty.\n");
    }
    int deq = arr[front+1];
    if (rear == 0){
        rear --;
        return deq;
    }
    else{
        for(int i = 1; i<rear+1; i++){
            arr[i-1] = arr[i];
        }
    }
    rear --;
    return deq;
}

/*---Function to display the elements of the queue-------*/
void display(int *arr)
{
    int i;
    if(isempty())
    {
        printf("Queue is empty\n");
        return;
    }
    else {
        
        for(i=front+1; i<=rear; i++)
        {
            printf("%d ",arr[i]);
        }

    }
    printf("\n");
}

/*-----Main program-----*/
int main()
    {
    int arr[N];  //array in which queue will live

    /* insert 8 items */
    display(arr);
    enqueue(1,arr);
    enqueue(2,arr);
    display(arr);
    enqueue(3,arr);
    enqueue(4,arr);
    enqueue(5,arr);
    enqueue(6,arr);
    enqueue(7,arr);
    enqueue(8,arr);
    display(arr);
    enqueue(9,arr);

    for(int i=0;i<N-1;i++){
        printf("dequeued element is: %d\n",dequeue(arr));
        //printf("%d, %d\n", rear, front);
    }

    printf("The element at the front of the queue is: %d\n",peek(arr));
    display(arr);
    return 0;
}