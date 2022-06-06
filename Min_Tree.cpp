#include<iostream>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *getnode(int data)
{
    node *temp=new node;
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
node *insert(node *root,int data)
{
    if(root==NULL){
        return getnode(data);
    }
     if(data <= root->data)
    {
        root->left=insert(root->left,data);
    }
    else 
    {
        root->right=insert(root->right,data);
    }
     return root;   
}
int min(node *root)
{
    node *curr=root;
    if(root==NULL){
        cout<<"No elements";
    }
    else{
    while(curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr->data;
    }
}
int max(node *root)
{
    node *curr=root;
    if(root==NULL){
        cout<<"No elements";
    }
    while(curr->right!=NULL)
    {
        curr=curr->right;
    }
    return curr->data;
}

int main()
{
    node *root=NULL;
    root=insert(root,12);
     root=insert(root,2);
     root= insert(root,22);
      root= insert(root,123);
       root= insert(root,1222);
        cout<<"Minimum value : "<<min(root);
        cout<<endl<<"Maximum value : "<<max(root);
        
}