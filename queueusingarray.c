#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int*arr ;
    int f;
    int b;
    int size;
};

void printqueue(struct queue *q)
{
    while(q->f!=q->b)
    {
        printf("%d",q->arr[q->f]);
        q->f=q->f+1;
    }
}
int isfull(struct queue *q)
{
    if(q->b==q->size-1)
    return 1;

    return 0;
}
void enqueue(struct queue * q,int val)
{   
    if(isfull(q))
    printf("queue full");
    else
    {
        q->b=q->b+1;
        q->arr[q->b]=val;
    }
}

int isempty(struct queue *q )
{
    if(q->f==q->b)
    return 1;
    return 0; 
}

int dequeue(struct queue* q)
{
    if(isempty(q))
    printf("queue is empty");
    else{
        int a =-1;
        q->f=q->f+1;
        a=q->arr[q->f];
        return a;

    }
}
    int main()
{
    struct queue q;
    q.size=6;
    q.f=-1;
    q.b=-1;
    q.arr=(int*)malloc(q.size*sizeof(int*));
    enqueue(&q,15);
    enqueue(&q,16);
    enqueue(&q,17);
    enqueue(&q,18);
    enqueue(&q,19);
  
    printqueue(&q);
    return 0;
}