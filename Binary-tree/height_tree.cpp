#include<iostream>
#include<vector>
using namespace std;
class node{
	public:
	int data;
	node* left;
	node* right;
	
	 node(int val){
		int data = val;
		left = nullptr;
		right = nullptr;
	}
	
	static node* buildtree(vector<int> preorder){
		
		static int idx= -1;
		idx++;
		
		if(preorder[idx] == -1){
			return NULL;
		}
		
		node* root = new node(preorder[idx]);
		root -> left = buildtree(preorder);
		root -> right = buildtree(preorder);
		
		return root;
	}
	 static int height(node* root){
		if(root == NULL){
			return 0;
		}
		int leftht = height(root->left);
		int rightht = height(root->right);
		
		return max(leftht, rightht) +1;
	}
	
};

	int main(){
	vector<int> preorder ={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
	
	node* root = node::buildtree(preorder);
	
	int res = node::height(root);
	cout<<"height of tree :-"<<res;
	
	cout<<endl;

	return 0;
	
}

