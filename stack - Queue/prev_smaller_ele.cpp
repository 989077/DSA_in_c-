#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
	vector<int> arr = {3,1,2,4,5,6};
	vector<int> ans(arr.size(),-1);
	stack<int> s;
	for(int i =0; i<arr.size(); i++){
		while(s.size() > 0 && s.top() >= arr[i]){
			s.pop();
		}
		if(s.empty()){
			ans[i] = -1;
		}
		else{
			ans[i] = s.top();
		}
		s.push(arr[i]);
	}
	for(int val : ans)
		{
			cout<<val<<" ";
		}
		cout<<endl;
	return 0;
}
