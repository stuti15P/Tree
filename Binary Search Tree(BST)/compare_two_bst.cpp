#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

void insert_node(struct Node **root, int data)
{
	if(*root ==NULL)
	{
		*root =new Node();
		(*root)->data =data;
		(*root)->left =(*root)->right =NULL;
	}
	else if(data<= (*root)->data)
	{
		insert_node(&((*root)->left), data);
	}
	else
		insert_node(&((*root)->right), data);
}

int compare_bst(struct Node *root1, Node *root2)
{
	if(root1== NULL&& root2 ==NULL) 
		return 1;
	else if(root1 != NULL && root2 ==NULL)
		return 0;
	else if(root1 ==NULL && root2 !=NULL)
		return 0;
	else if(root1->data ==root2->data && compare_bst(root1->left, root2->left)
		&&compare_bst(root1->right, root2->right))
		return 1;
	else 
		return 0;
}


int main()
{
	struct Node *root1=NULL, *root2= NULL;
	insert_node(&root1, 10);
	insert_node(&root1, 20);
	insert_node(&root1, 5);
	insert_node(&root1, 7);
	
	insert_node(&root2, 5);
	insert_node(&root2, 10);
	insert_node(&root2, 20);
	insert_node(&root2, 7);
	
	if(compare_bst(root1, root2))
		cout<<"Both BST are same\n";
	else 
		cout<<"BOTH BST are not same\n";
	return 0;
	
}
