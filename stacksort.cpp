#include<iostream>
#include<stdlib.h>



using namespace std;
struct stack 
{
    int *arr;
    int top;
    int size;
};
void descending(struct stack *sp)
{
    int temp;
   for(int i=0;i<=sp->top;i++)
   {
       for(int j=i+1;j<=sp->top;j++)
       {
           if(sp->arr[i]<sp->arr[j])
           {
              temp= sp->arr[i];
              sp->arr[i]=sp->arr[j];
              sp->arr[j]=temp;
           }
       }
   }
    
}
void traversal(struct stack *sp)
{
    for(int i=0;i<=sp->top;i++)
    {
        cout<<sp->arr[i]<<" ";
    }
}
int isempty(struct stack *sp)
{
    if(sp->top==-1)
    return 1;

    return 0;
}
int isfull(struct stack *sp)
{
    if(sp->top==sp->size-1)
    return 1;

    return 0;
}
void push(struct stack *sp,int val)
{
    if(isfull(sp))
    cout<<"stackfull is full"<<endl;
    else{
    sp->top=sp->top+1;
    sp->arr[sp->top]=val;
    }

}
int pop(struct stack *sp)
{
    int a=-1;
    if(isempty(sp))
    {
        cout<<"stack is empty\n";
        return a;
        
    }
    else{
        a=sp->arr[sp->top];
        sp->top=sp->top-1;
        return a;
    }
}
int main()
{
    struct stack sp;
    sp.size=10;
    sp.top=-1;
    sp.arr=(int *)malloc(sp.size*sizeof(int));
    push(&sp,10);
    push(&sp,11);
    push(&sp,12);
    push(&sp,13);
    push(&sp,14);
    push(&sp,15);
    cout<<"before sorting"<<endl;
    traversal(&sp);
    cout<<endl<<"after sorting"<<endl;
    descending(&sp);
    traversal(&sp);
    return 0;
}