#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;
int larRecArea(vector<int>& height){
	
		
		int n = height.size();
		
		vector<int> left(n,0);
		vector<int> right(n,0);
		stack<int>s;
		
		for(int i=n-1; i>=0; i--){
			while(!s.empty()  and height[s.top()] >= height[i]){
				s.pop();
			}
			right[i] = s.empty() ? n : s.top();
			s.push(i);
		}
		while(!s.empty()){
			s.pop();
		}
//		left smaller
    for(int i=0; i<n; i++){
    	while(s.size() > 0 && height[s.top()] >= height[i]){
    		s.pop();
		} 
		left[i] = s.empty() ? -1 : s.top();
		s.push(i);
	}
		int ans=0;
		for(int i=0; i<n; i++){
			int width = right[i] - left[i] -1;
			int currArea = height[i] * width;
			ans = max(ans, currArea);
		}
		return ans;
	}

int main(){
	vector<int> height = {2,1,5,6,2,3};
	cout<<"largest rectangle area: -"<<larRecArea(height);
	cout<<endl;
	return 0;
	
}
