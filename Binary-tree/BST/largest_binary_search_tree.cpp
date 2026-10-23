#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
	Node(int val){
		val = data;
		left = right = NULL;
	}
};
class info{
	public:
	int min , max, sz;
	
	info(int mi, int ma, int size){
		min = mi;
		max = ma;
		sz = size;
	}
};
info helper(Node* root){
	if(root == NULL){
		return info(INT_MAX, INT_MIN, 0);
	}
	
	info left = helper(root->left);
	info right = helper(root->right);
	
	if(root->data >left.max && root->data < right.min){
		int currmin = min(root->data, left.min);
		int currmax = max(root->data, right.max);
		int currsize = left.sz + right.sz + 1;
		
		return info(currmin,currmax, currsize);
	}
	return info(INT_MIN, INT_MAX, max(left.sz, right.sz));
}

int largest_BST(Node* root){
	info info = helper(root);
	return info.sz;
}
int main(){
	
	Node* root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	
	root->left->left = new Node(1);
	root->left->right = new Node(8);
	root->right->right = new Node(7);
	
	cout<<"size of largets bst :-"<<largest_BST(root)<<endl;
	return 0;
}
