#include<iostream>
#include<unordered_map>
using namespace std;
struct Node{
	int val;
	Node* next;
	Node* random;
	
	Node(int _val){
		val = _val;
		next = NULL;
		random = nullptr;
	}
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldToCopy;
        oldToCopy[NULL] = NULL;

        Node* cur = head;
        while (cur != NULL) {
            Node* copy = new Node(cur->val);
            oldToCopy[cur] = copy;
            cur = cur->next;
        }

        cur = head;
        while (cur != NULL) {
            Node* copy = oldToCopy[cur];
            copy->next = oldToCopy[cur->next];
            copy->random = oldToCopy[cur->random];
            cur = cur->next;
        }

        return oldToCopy[head];
    }
};
void printList(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        int randomVal = cur->random ? cur->random->val : -1;
        cout << "[Val: " << cur->val << ", Random: " << (randomVal == -1 ? "NULL" : to_string(randomVal)) << "] -> ";
        cur = cur->next;
    }
    cout << "NULL\n";
}
int main(){
	Node* node1 = new  Node(1);
	Node* node2 = new  Node(2);
	Node* node3 = new  Node(3);
	
	node1 ->next = node2;
	node2 ->next = node3;
	
	node1 ->random = node3;
	node2 ->random = node1;
	node3 ->random = nullptr;
	
	Solution sol;
	Node* copiedHead = sol.copyRandomList(node1);
	
	cout<<"original list";
	printList(node1);
	
	cout<<"copied list";
	printList(copiedHead);
	
	return 0;
}


