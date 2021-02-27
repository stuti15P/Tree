/*Program to convert a Binary search tree into sorted double linked list without
using extra space (except recursion stack space)
*/
#include <iostream>
using namespace std;

struct node 
{
    int data;
    struct node *left ,*right;
};
void insert_node(node **root, int data)
{
    if(*root ==NULL)
    {
        *root =new node();
        (*root)->data =data;
        (*root)->left = (*root)->right =NULL;
    }
    
    else if(data<=(*root)->data)
        insert_node(&((*root)->left), data);
    else
        insert_node(&((*root)->right), data);
}

//PreOrder Traversal
void InOrder_traversal(struct node *root)
{
    if(root ==NULL)  return;
    InOrder_traversal(root->left);
    cout<<root->data<<" ";
    InOrder_traversal(root->right);
    
}

void convert_bst_to_dll(struct node *root, node **headLinkedList, node **prev)
{
    if(root ==NULL)
        return;
    convert_bst_to_dll(root->left,  headLinkedList, prev);
    if(*prev ==NULL)
    {
        *headLinkedList =root;
        *prev =root;
    }
    else
    {
        root->left =*prev;
        (*prev)->right =root;
        *prev =root;
    }
    convert_bst_to_dll(root->right, headLinkedList, prev);
    
}
void print_list(struct node *root)
{
    while(root !=NULL)
    {
        cout<<root->data<<"->";
        root =root->right;
    }
    cout<<"NULL";
}
int main() {
	// your code goes here
	struct node *root= NULL;
	struct node *headLinkedList = NULL;
	struct node *prev =NULL;
	insert_node(&root, 10);
	insert_node(&root, 6);
	insert_node(&root, 9);
	insert_node(&root, 5);
	insert_node(&root, 15);
	insert_node(&root, 23);
	
	InOrder_traversal(root);
	convert_bst_to_dll(root, &headLinkedList, &prev);
	cout<<endl;
	print_list(headLinkedList);
	
	return 0;
}
