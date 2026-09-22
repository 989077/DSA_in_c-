#include<iostream>
using namespace std;

struct Node{
	public:
		int val;
		Node* prev;
		Node* next;
		Node* child;
		
		Node(int _val){
			val = _val;
			next = NULL;
			child = NULL;
			prev = NULL;
		}
};

class Solution{
	public:
		Node* flatten(Node* head){
			if(head == NULL){
				return head;
			}
			Node* curr = head;
			
			while(curr != NULL){
				if(curr->child != NULL){
					
				Node* next = curr->next;
				curr->next = flatten(curr->child);
				
				curr->next->prev = curr;
				curr->child = NULL;
				
				//find tail
				while(curr->next != NULL){
					curr = curr->next;
				}
				
				//attach tail with n ext ptr;
				if(next != NULL){
					curr->next = next;
					next->prev = curr; 
				}
				}
				curr = curr->next;
				
			}
			return head;
				
		}
};

void printList(Node* head){
	Node* curr = head;
	while(curr != nullptr){
		cout<<curr->val <<" ";
		curr = curr->next;
	}
	cout<<"\n";
}
int main(){
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->prev = head;
	
	head->next->next = new Node(3);
	head->next->next->prev = head->next;
	
	Node* childHead = new Node(4);
	childHead->next = new Node(5);
	childHead->next->prev = childHead;
	
	head->next->child = childHead;
	
	Solution Sol;
	Node* flattetenHead = Sol.flatten(head);
	
	cout<<"flatteneHead list output:\n";
	printList(flattetenHead);
	
	return 0;
}
