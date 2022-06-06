#include<iostream>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *findmin(node *root)
{
    while(root->left!=NULL)
        root=root->left;
        return root;
    
}
node *insert(node *root,int data)
{
    if(root==NULL)
    {
        root=new node();
        root->data=data;
        root->left=root->right=NULL;
    }
    else if (data <= root->data)
    {
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}
void inorder(node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node *deletion(node *root,int data){
    if(root==NULL)
    return root;
    else if(data < root->data){
        root->left=deletion(root->left,data);
    }
    else if(data > root->data){
        root->right=deletion(root->right,data);
    }
    else{
        if(root->left==NULL&&root->right==NULL){
            delete(root);
            root=NULL;
        }
        else if(root->left==NULL){
            node *temp=root;
            root=root->right;
            delete(temp);
        }
        else if(root->right==NULL){
             node *temp=root;
            root=root->left;
            delete(temp);
        }
        else{
            node *temp=findmin(root->right);
            root->data=temp->data;
            root->right=deletion(root->right,temp->data);
        }
       
    }
     return root;
}
int main()
{
    node *root=NULL;
root=insert(root,12);
root=insert(root,121);
root=insert(root,2);
root=insert(root,1200);
root=insert(root,-2);
    cout<<"Inorder : ";
    inorder(root);
   root= deletion(root,-2);
   // deletion(root,12);
     cout<<endl<<"Inorder : ";
    inorder(root);
}