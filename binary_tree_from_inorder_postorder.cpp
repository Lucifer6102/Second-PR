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
int preIndex;
int search(int in[],int s,int e,int n)
{
    int i;
    for(i=s;i<=e;i++)
    {
        if(in[i]==n)
        return i;
    }
}
node* buildTree(int in[],int post[],int s,int e)
{
    if(s>e)
    return NULL;
    
    
    node*t=new node(post[preIndex--]);
    if(s==e)
    return t;
    
    int ind=search(in,s,e,t->data);
    t->right=buildTree(in,post,ind+1,e);
    t->left=buildTree(in,post,s,ind-1);

    return t;
}

node *buildTree(int in[], int post[], int n) {
    preIndex=n-1;
    node* root = buildTree(in, post, 0, n - 1);  
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
	int in[7]={1,2,3,4,5,6,7};
	int post[7]={1,2,5,7,6,4,3};
	node* root1=buildTree(in,post,7);
	inorder(root1);

	return 0;
}