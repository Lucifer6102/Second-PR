#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
int build(node *root)
{
    if(root==NULL)
    return 0;
    
    if(root->left==NULL && root->right==NULL)
    {
        int g=root->data;
        root->data=0;
        return g;
    }
    
    int a=build(root->left);
    int b=build(root->right);
    int d=root->data;
    int c=a+b;
    root->data=c;
    return (d+c);
}
void toSumTree(node *root)
{
    int x=build(root);
}
void inorder(node* root)
{
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    node *root=new node(3);
    root->left=new node(2);
    root->right=new node(5);
    root->left->left=new node(1);
    root->right->left=new node(4);
    root->right->right=new node(6);
    root->right->right->right=new node(7);
    inorder(root);
    cout<<"\n";
    toSumTree(root);
    inorder(root);
    return 0;
}