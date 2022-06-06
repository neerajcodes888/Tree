#include<iostream>
using namespace std;
struct bst
{
   int data;
   bst *left;
   bst *right;
};
	bst *getnode(int data)
{
    bst *temp=new bst;
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
bst *insert(bst *root,int data)
{
    if(root==NULL)
    {
        root=getnode(data);
    }
    else if(data < root->data)
    {
        root = insert(root->left,data);
    }
    else {
        root = insert(root->right,data);
    }
}
bool search(bst *root,int key)
{
    if(root==NULL)
    return false;
    else if(key < root->data )
    {
        search(root->left,key);
    }
    else if(key > root->data)
    {
       search(root->right,key);
    }
    else if(root->data==key){
        return true;
    }
}
/*void inorder(bst*root)
{
   while(root->data!=NULL)
   {
       inorder(root->left);
        cout<<root->data;
        inorder(root->right);
   }
    

}*/
int main()
{
    bst *node=NULL;
    node= insert(node,12);
    node= insert(node,17);
    node= insert(node,19);
    int k;
    cout<<"Enter key:";
    cin>>k;
if(search(node,k)){
    cout<<k<<" found in the tree";
}
else{
    cout<<k<<" not found in the tree";
}
    //inorder(node);
    return 0;
}