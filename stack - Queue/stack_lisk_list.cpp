#include<iostream>
#include<vector>
#include<list>
using namespace std;

class stack{
	list<int> ll;
	
	public:
		void push(int val){
			ll.push_front(val);
			
		}
		void pop(){
			ll.pop_front();
		}
		int top(){
			return ll.front();
		}
		
		bool empty(){
			return ll.size() == 0;
		}
};
int main(){
	stack s;
	
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	while(!s.empty()){
		cout<<s.top() <<" ";
		s.pop();
	}
	return 0;
}
