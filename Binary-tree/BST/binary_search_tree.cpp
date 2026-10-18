#include<iostream>
#include<vector>
using namespace std;
class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int val){
			data = val;
			left = right = nullptr;
		}
};
Node* insert(Node* root, int val){
	if(root == nullptr){
	
		return new Node(val);
	}
	if(val <  root->data ){
		
		root->left = insert(root->left, val);
		
	}else {
		
		root->right = insert(root->right, val);
	}
	return root;
}
void inorder(Node* root) {
	if(root == nullptr){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}

Node* buildBSt(vector<int> arr){
	Node* root= nullptr;
	
	for(int val: arr){
		root = insert(root, val);
	}
	return root;
}

bool search(Node* root, int key){
	if(root == NULL){
		return false;
	}
	if(root->data == key){
		return true;
	}
	if(root->data > key){
		return search(root->left, key);
	}
	
	else{
		return search(root->right, key);
	}
}
int main(){
	
	vector<int> arr = {3,2,1,5,6,4};
	Node* root =  buildBSt(arr);
	cout<<" Inorder tensversal :-";
	
	cout<<search(root,2)<<endl;
	return 0;
	
}
