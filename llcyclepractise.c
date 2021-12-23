#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* fixcycle(struct node* head)
{
    struct node * slow=head;
    struct node * fast=head;
      do
     {
        slow=slow->next;
        fast=fast->next->next;
     }while(fast!=NULL || fast->next!=NULL);
     slow=head;
       
        while (fast->next!=slow->next)
        {

        
          fast=fast->next;
         slow=slow->next;
            
        }
        fast->next=NULL;
        return head;

    
}
int cyclic(struct node* head)
{
    struct node* slow=head;
    struct node* fast=head;
    while(fast!=NULL || fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
        return 1;
    }
    return 0;
}
int main()
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* secondhead=(struct node*)malloc(sizeof(struct node));
    struct node* thirdhead=(struct node*)malloc(sizeof(struct node));
    struct node* fourthhead=(struct node*)malloc(sizeof(struct node));
    struct node* fifthhead=(struct node*)malloc(sizeof(struct node));
    struct node* sixthhead=(struct node*)malloc(sizeof(struct node));
    struct node* seventhhead=(struct node*)malloc(sizeof(struct node));
    head->data=11;
    head->next=secondhead;
    secondhead->data=12;
    secondhead->next=thirdhead;
    thirdhead->data=13;
    thirdhead->next=fourthhead;
    fourthhead->data=14;
    fourthhead->next=fifthhead;
    fifthhead->data=15;
    fifthhead->next=sixthhead;
    sixthhead->data=16;
    sixthhead->next=seventhhead;
    seventhhead->data=17;
    seventhhead->next=fifthhead;
    // if(cyclic(head))
    // {
    // printf("cycle detected");
    // }
    printf("hello");
    head=fixcycle(head);
    
    if(cyclic(head))
    {
    printf("cycle detected");
    }
    return 0;

}
