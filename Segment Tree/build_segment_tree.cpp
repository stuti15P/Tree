#include<iostream>
#include<algorithm>

using namespace std;

void build_tree(int *arr, int ss, int se, int *tree, int index)
{
	if(ss ==se)
	{
		tree[index] =arr[ss];
		return;
	}
	
	int mid = (ss+se)/2;
	build_tree(arr, ss, mid, tree, 2*index);
	build_tree(arr, mid+1, se, tree, 2*index+1);
	cout<<"index  tree[2*index]  tree[2*index+1] \n";
	cout<<index<<" "<<tree[2*index]<<" "<<tree[2*index+1]<<endl;
	tree[index] = min(tree[2*index], tree[2*index +1]);
}


int main()
{
	int arr[] = {2, 5, 7, 4, 3, 1, 9, 11, 20, -6};
	
	int n = sizeof(arr)/ sizeof(int);
	int tree[4*n+1];
	build_tree(arr, 0, n-1, tree, 1);
	
	//print tree
	cout<<"Segment tree is :\n";
	for(int i=1; i<=25; i++)
		cout<<tree[i]<<"  ";
	
}
