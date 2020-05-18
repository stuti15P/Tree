#include <iostream>
using namespace std;

//structure to denote bst.
struct Node
{
    int data;
    struct Node *left, *right;
};

//Building tree by inserting node to its appropriate position.

void Insert_node(Node** root , int data)
{
    if(*root ==NULL)
    {
        
        *root = new Node();
        (*root)->data =data;
        (*root)->left =(*root)->right =NULL;
    }
    
    else if(data<= (*root)->data)
    {
        Insert_node(&((*root)->left), data);
    }
    else
        Insert_node(&((*root)->right), data);        
    
}
//Varios travesal of the tree.
void PreOrder(Node *root)
{
    if(root ==NULL) return;
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(Node *root)
{
    if(root ==NULL) return;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

void PostOrder(Node *root)
{
    if(root ==NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}

int main() {
	// your code goes here
	
	Node *root1 =NULL;
	
	Insert_node(&root1, 10);

	Insert_node(&root1, 5);
	Insert_node(&root1, 7);
	Insert_node(&root1, 20);
	Insert_node(&root1, 30);
	Insert_node(&root1, 6);
	
	
	//Prerder traversal
	cout<<"Preorder Traversal\n";
	PreOrder(root1);
	cout<<"\nPostOrder Traversal\n";
	PostOrder(root1);
	return 0;
}
