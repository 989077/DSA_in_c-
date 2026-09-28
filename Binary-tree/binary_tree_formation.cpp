#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class node{
	public:
	int data;
	node* left;
	node* right;
	
	node(int val){
		data = val;
		left = nullptr;
		right = nullptr;
	}
	
	 static node*  biuldtree(vector<int> preorder){
		
			static int idx = -1;
			idx++;
		
		if(preorder[idx] == -1){
			return NULL;
		}
		
		node* root = new node(preorder[idx]);
		root->left = biuldtree(preorder);
		root->right = biuldtree(preorder);
		return root;
	}
	
};
int main(){
	vector<int> preorder ={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
	
	node* root = node::biuldtree(preorder);
	cout<< root->data <<endl;
	return 0;
	
}
