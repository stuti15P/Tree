#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node *left, *right;
	int height;
};

//Function to find height of a tree.
/*
int find_height(Node *node)
{
	if(node ==NULL) return 0;
	else
		return max(root->left->height ,root->right->height) +1;
}

//Function to find balance factor of a Node.
int find_bal_factor(Node *node)
{
	if(node ==NULL) return 0;
	else
		return (node->left) - find_height(node->right);
}
*/
Node * rotate_right(Node *c)
{
	Node *b =c->left;
	Node *T3 =b->right;
	//ROTATE node c to left :-
	b->right =c;
	c->left  =T3;
	return b;
}
Node * rotate_left(Node *c)
{
    Node *b =c->right;
    Node *T2 =b->left;
    //Rotate node c to right:-
    b->left =c;
    c->right =T2;
    return b;
}

Node *insert_node(Node *root, int data)
{
	if(root ==NULL)
	{
		root =new Node();
		root->data =data;
		root->left =root->right =NULL;
		root->height = 1;
		return root;
	}
	else if(data< root->data)
	{
		root->left =insert_node(root->left, data);
	}
	else
		root->right =insert_node(root->right, data);
	//I feel not needed: ht calculation-
	int lh, rh;
	if(root->left!=NULL)
		lh =root->left->height;
	else 
		lh =0;
	if(root->right!=NULL)
		rh =root->right->height;
	else 
		rh =0;
	root->height =max(lh ,rh) +1;
	//int bf =find_bal_factor(root);
	int bf =lh -rh;
	cout<<"node->data is:"<<root->data<<"  bf is:"<<bf<<endl;
	//LL case
	if(bf>1 && data< root->left->data)
	{
		return rotate_right(root);
	}
	else if(bf<-1 && data> root->right->data)
	{
	    return rotate_left(root);
	}
	else if(bf>1 &&data> root->right->data)
	{
	    rotate_left(root->left);
	    return rotate_right(root);
	}
	else if(bf<-1 && data< root->right->data)
	{
	    rotate_right(root->right);
	    return rotate_left(root);
	}
	
	return root;
}

void preOrder_traversal(Node *node)
{
	if(node ==NULL) return;
	else
	{
		cout<<node->data<<" ";
		preOrder_traversal(node->left);
		preOrder_traversal(node->right);
	}
	
}

int main()
{
	Node *root =NULL;
	root =insert_node(root, 10);
	root =insert_node(root, 7);
	root =insert_node(root, 5);
	root =insert_node(root, 15);
	root =insert_node(root, 20);
	preOrder_traversal(root);
	
	return 0;
}
	
		
