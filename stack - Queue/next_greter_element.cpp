#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
	stack<int> s;
	
	vector<int> ele = {10, 23, 15, 0, 9,4};
	vector<int> ans(ele.size(), 0);
	
	for(int i = ele.size()-1; i >=0; i--){
		while(s.size() > 0 and s.top() <= ele[i]){
			s.pop();
		}
		if(s.empty()){
			ans[i] = -1;
		}else{
			ans[i] = s.top();
		}
		s.push(ele[i]);
	}
	for(int val:ans){
		cout<< val<<" ";
	}
	cout<<endl;
	return 0;
}
