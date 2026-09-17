#include<iostream>
#include<vector>
#include<list>
using namespace std;

struct node{
	int data;
	node*  next;
	
	node(int val){
		data = val;
		next = nullptr;
		
	}
};
class linklist{
	public:
		node* head;
		linklist(){
			head = nullptr;
		}
		
		void push_front(int val){
			node* newnode = new node(val);
			newnode->next = head;
			head = newnode;
		}
		void printLL(){
			node* temp = head;
			while(temp != nullptr){
				cout<<temp->data<<"->";
				temp = temp-> next;
			}
			cout<<"null";
		}
};

int main(){
	linklist l;
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	l.push_front(4);
	l.printLL();

	return 0;
}
