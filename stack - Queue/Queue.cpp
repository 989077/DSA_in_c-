#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class node{
	public:
	int data;
	node* next;

	node(int val){
		 data = val;
		 next = NULL;
	}
};

class Queue{
	node* head;
	node* tail;
	
	public:
		Queue(){
			head = tail = NULL;
		}
		
		void push(int data){
			//insert data at tail
			node* newnode = new node(data);
			
			if(emty()){ 
				head = tail = newnode;
			}else{
				tail->next = newnode;
				tail = newnode;
			}
			
		}
		void pop(){
			if(emty()){
				cout<<" LL iscempty. "<<endl;
				return;
			}else{
				node* temp = head;
				head = head->next;
				delete temp;
			}
			
			
		}
		int front(){
			if(emty()){
				cout<<"LL is empty\n";
				return -1;
			}
			return head->data;
			
		}
		bool emty(){
			return head == NULL;
		}
};
int main(){
	Queue Q;
	Q.push(1);
	Q.push(2);
	Q.push(4);
	Q.push(6);
	Q.push(8); 
	while(!Q.emty()){
		cout<<Q.front() <<" ";
		Q.pop();
	}
	return 0;
}
