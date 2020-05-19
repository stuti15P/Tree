#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

//Building Binary tree
Node* insert_node(Node *root, int data) {
    
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	
	else if(data <= root->data)
		root->left = insert_node(root->left,data);
	else 
		root->right = insert_node(root->right,data);
	return root;
}

//INORDER TRAVERSAL OF A BINARY TREE.
void Inorder_traversal(Node *root) {
	if(root==NULL) return;

	Inorder_traversal(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder_traversal(root->right);      // Visit right subtree
}
//PREORDER TRAVERSAL OF A BINARY TREE.
void Preorder_traversal(struct Node *root) {
	
	if(root == NULL) return;

	printf("%d ",root->data); // Print data
	Preorder_traversal(root->left);     // Visit left subtree
	Preorder_traversal(root->right);    // Visit right subtree
}

void convert_bst_to_dll(Node *node, Node* &headLinkedList, Node* &prev)
{

	if(node ==NULL) return;
	
	convert_bst_to_dll(node->left ,headLinkedList, prev);
	if(prev ==NULL)
	{
		headLinkedList =node;
		prev =node;
	}
	else
	{
		node->left =prev;
		prev->right =node;
		prev =node;
	}
	convert_bst_to_dll(node->right ,headLinkedList, prev);

}

void print_Dll(Node *node)
{
    
	while(node!= NULL)
	{
		cout<<node->data <<"-> ";
		node =node->right;
	}
	cout<<"NULL";
}
int main() {
	// your code goes here
	Node* root = NULL;
	root = insert_node(root, 5); 
	root = insert_node(root,3);
	root = insert_node(root, 7); 
	root = insert_node(root, 1); 
	root = insert_node(root, 9); 
	root = insert_node(root, 2);

/*

				      5
			      /   \
			     3      7
			    /        \
         1           9
			    \
		        2
	
*/

	cout<<"Inorder traversal"<<endl;
	Inorder_traversal(root);
	cout<<"\n";
	cout<<"Preorder traversal "<<endl;
	Preorder_traversal(root);
	cout<<endl;
	
	struct Node *prev =NULL;
    struct Node *headLinkedList =NULL;
	
	convert_bst_to_dll(root, headLinkedList, prev);
	print_Dll(headLinkedList );

	
	return 0;
}	
