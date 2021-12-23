#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node * next;
};

void traversal(struct node * ptr)
{
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

int dequeue(struct node* &f,struct node *&r)
{
    int a=-1;
    if(f->next==NULL)
    {
        cout<<"queue empty";
    }
    else{
        a=f->data;
        f=f->next;
        return a;
    }
    return a;
}

void enqueue(struct node* &f,struct node* &r,int val)
{
    struct node* n=(struct node*)malloc(sizeof(struct node));
    if(n==NULL)
    {
        cout<<"queue is full";

    }
    else{
        n->data=val;
        n->next=NULL;
        if(f==NULL)
        {
            f=r=n;
        }
        else
        {
            r->next=n;
            r=n;
        }
    }


    
}
int main()
{
    struct node *f=NULL;
    struct node *r=NULL;
    enqueue(f,r,10);
    enqueue(f,r,11);
    enqueue(f,r,12);
    enqueue(f,r,13);
    enqueue(f,r,14);
 
    dequeue(f,r);
    dequeue(f,r);
     traversal(f);
    return 0;
}