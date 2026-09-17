#include<iostream>
#include<list>
using namespace std;

struct node{
	int data;
	node* next;
	
	node(int val){
		data = val;
		next = nullptr;
	}
};
class Solution{
	public:
	node* reverseList(node* head){
		node* prev = nullptr;
		node* curr = head;
		node* next = nullptr;
		
		while(curr != nullptr){
			next = curr->next;
			curr->next = prev;
			
			prev = curr;
			curr = next;
		}
		return prev;
	}
	void printList(node* head){
		node* temp = head;
		while(temp != nullptr){
			cout<<temp->data<<"->";
			temp = temp->next;
		}
		cout<<"nullptr"<<endl;
	}
};
int main(){
  node* head = new node(1);
  head->next = new node(4);
  head->next->next = new node(5);
  head->next->next->next = new node(6);
  head->next->next->next->next = new node(7);
  
  
  
  Solution sol;
  cout<<" org-";
  sol.printList(head);
  
  node* result = sol.reverseList(head);
  cout<<"rev - ";
  sol.printList(result);
 
  
  return 0;
  
}
