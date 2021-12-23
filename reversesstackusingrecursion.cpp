#include<iostream>
#include<stdlib.h>
using namespace std;
struct stack 
{
    int top;
    int size;
    int *arr;
};
int isfull(struct stack *sp)
{
    if(sp->top==sp->size-1)
    {
        return 1;
    }
    return 0;
}
int isempty(struct stack *sp)
{
    if(sp->top==-1)
    {
        return 1;
    }
    return 0;
}
int stacktop(struct stack*sp)
{
    return sp->arr[sp->top];
}
int pop(struct stack *sp)
{
    int a=-1;
    if(isempty(sp))
    {
        cout<<"stack is emmpty"<<endl;
        return a;
    }
    
   a= sp->arr[sp->top];
   sp->top--;
   return a;
}
void push(struct stack *sp,int val)
{
    if(isfull(sp))
    {
        cout<<"stack is full"<<endl;
    }
    else{
    sp->top++;
    sp->arr[sp->top]=val;
    }
}
void createstack(struct stack *sp,int *arr,int size)
{
    for(int i=0;i<size;i++)
    {
        push(sp,arr[i]);
    }
}
void insertatbottom(struct stack *sp,int temp)
{
    if(isempty(sp))
    {
        push(sp,temp);
        return;
    }
        int top=stacktop(sp);
        pop(sp);
        insertatbottom(sp,temp);
        push(sp,top);

}
void reversestack(struct stack*sp)
{
    if(isempty(sp))
    {
        return ;
    }
    int temp=stacktop(sp);
    pop(sp);
    reversestack(sp);
    insertatbottom(sp,temp);
}
void traversal(struct stack *sp)
{
    for(int i=0;i<=sp->top;i++)
    {
        cout<<sp->arr[i]<<" ";
    }
}

int main()
{
    struct stack sp;
    sp.size=20;
    sp.arr=(int *)malloc(sp.size*sizeof(int));
    sp.top=-1;
    int arr[]={1,2,3,4,5};
     int size=sizeof(arr)/sizeof(arr[0]);
    createstack(&sp,arr,size);
    reversestack(&sp);
    traversal(&sp);
    
    return 0;
    

}