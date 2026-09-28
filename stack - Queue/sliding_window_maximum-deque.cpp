#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int main(){
	vector<int> nums = {2,1,-1,4,5,2,8,4,2};
	int k=3;
	deque<int> dq;
	vector<int> res;
//	1st window
     //1st window
        for(int i =0; i<k; i++){
            while(dq.size()>0 && nums[dq.back()] <= nums[i]){

                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(int i=k; i<nums.size(); i++){
            res.push_back(nums[dq.front()]);

            while(dq.size() >0 && dq.front() <= i-k){
                dq.pop_front();
            }
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            
        }
        
        res.push_back(nums[dq.front()]);
        for(int val:res){
        	cout<<val<<" ";
		}
		cout<<endl;
		return 0;
	
}
