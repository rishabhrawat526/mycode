#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
void push(struct stack *sp,int val)
{
    sp->top++;
    sp->arr[sp->top]=val;
}
int pop(struct stack *sp)
{
    int val=sp->arr[sp->top];
    sp->top--;
    return val;
}
int perform(int op1,int op2,char ch)
{
    int ans;
    if( ch =='+')
    ans=op2 +op1;
    else if( ch =='-')
     ans=op2 -op1;
    else if( ch =='*')
     ans=op2 *op1;
    else if( ch =='/')
     ans=op2 / op1;

    return ans;
}
int topofstack(struct stack *sp)
{
    return sp->arr[sp->top];
}
int postfixeval(char *p)
{
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=20;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));
   int i=0;
    while(p[i]!='\0')
    {
        if(isdigit(p[i]))
        {
            push(sp,p[i]-48);
        }
        else{
          int op1=pop(sp);
          int op2=pop(sp);
            int ans=perform(op1,op2,p[i]);
            push(sp,ans);
        }
        i++;
    }
    return topofstack(sp);


}

int main()
{
    char * postfix="432*+5-";
    
    int ans=postfixeval(postfix);
    printf("%d",ans);
    return 0;

}
