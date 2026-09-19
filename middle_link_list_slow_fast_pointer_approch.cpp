#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	
	ListNode(int val){
		this->val = val;
		this->next = nullptr;
	}
	

	
};

class solution{
	public:
	ListNode* findmid(ListNode* head){
	  ListNode* slow = head;
	  ListNode* fast = head;
	  
	  while(fast != nullptr && fast->next != nullptr){
	  	if()
	  	slow = slow->next;
	  	fast = fast->next->next;
	  }
	  return slow;
	}
};
int main(){
	solution sol;
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	
	ListNode* mid = sol.findmid(head);
	cout<<mid->val<<" ";
	
	return 0;
	
}
