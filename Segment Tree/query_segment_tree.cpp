#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

void build_tree(int *arr, int as, int ae, int *tree, int index)
{
	if(as ==ae)
	{
		tree[index] =arr[as];
		return;
	}
	
	int mid = (as+ae)/2;
	build_tree(arr, as, mid, tree, 2*index);
	build_tree(arr, mid+1, ae, tree, 2*index+1);
	
	tree[index] =min(tree[2*index], tree[2*index +1]);
}

int query_min(int *tree, int ss, int se, int qs, int qe, int index)
{
	//Complete Overlap
	if(qs<= ss && qe>= se)
		return tree[index];
	
	//No Overlap
	if(qe<ss || qs> se)
		return INT_MAX;
	
	int mid =(ss+se)/2;
	int lval= query_min(tree, ss, mid, qs, qe, 2*index);
	int rval =query_min(tree, mid+1, se, qs, qe, 2*index +1);
	int minm = min(lval, rval);
	return minm;
}

int main()
{
	int arr[] = {2, -5, 7, 9, 1, 3, 10, 14};
	
	int n = sizeof(arr)/sizeof(int);
	
	//Question answer
	// If int *tree = new int[4*n+1] the array will be dynamically allocated in heap section
	//Default value is uninitialized.
	int tree[4*n +1];
	build_tree(arr, 0, n-1, tree, 1);
	//print segment tree
	for(int i=1; i<=15; i++)
		cout<<tree[i]<<" ";
		
	//QUERYING
	cout<<"\nQuerying \n";
	cout<<query_min(tree, 0, n-1, 1, 4, 1);
	
	
}
