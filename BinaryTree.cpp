#include<iostream>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
void preorder(node *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node *root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
node* insert(node *root,int data)
{
    if(root==NULL)
    {
        root=new node;
        root->data=data;
        root->left=root->right=NULL;
    }
    else if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
        
    }return root;
}
int main()
{

    node *root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,7);
    root=insert(root,8);
    root=insert(root,9);
    cout<<"Preorder : ";
    preorder(root);
    cout<<endl<<"Inorder : ";
    inorder(root);
    cout<<endl<<"Postorder : ";
    postorder(root);
return 0;
}