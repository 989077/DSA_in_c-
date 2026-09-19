#include<iostream>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head ;
        ListNode* fast = head;
        
        bool iscycle = false;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                iscycle = true;//cycle detected
                break;
            }
        }
        
        return false; //no cycle found

    }
};
int main(){
	Solution sol;
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	
	bool  mid = sol.hasCycle(head);
	cout<<mid<<" ";
	
	return 0;
	
}
