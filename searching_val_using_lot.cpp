#include<iostream>
#include<queue>

using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};

void levelordertraversal(struct node* root,int val)
{
    if(root==NULL)
    return;

    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* current=q.front();
        if(current->data==val)
        {
        cout<<"found"<<endl;
        return ;
        }
        if(current->left!=NULL) q.push(current->left);
        if(current->right!=NULL)q.push(current->right);
        q.pop();
    }
}

struct node* createbinary(int val)
{
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int main(){
    struct node* root= createbinary(10);
    root->left=createbinary(15);
    root->right=createbinary(20);
    root->left->left=createbinary(25);
    root->left->right=createbinary(30);
    root->right->left=createbinary(35);
    root->right->right=createbinary(40);
    levelordertraversal(root,40);
    return 0;
}