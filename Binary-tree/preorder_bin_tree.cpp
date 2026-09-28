#include<iostream>
#include<vector>
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
	static void preorder(node* root){
		if(root == NULL){
			return;
		}
		cout<<root->data <<" ";
		preorder(root->left);
		preorder(root->right);
	}
};
int main(){
vector<int> preorder ={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
	
	node* root = node::biuldtree(preorder);
	
	node::preorder(root);
	cout<<endl;
	return 0;
}
