#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
void getpermu(vector<int>& nums, int idx, vector<vector<int>> &ans){
    if(idx == nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=idx; i < nums.size(); i++){
        swap(nums[idx], nums[i]);
        getpermu(nums, idx+1, ans);
        swap(nums[idx], nums[i]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getpermu(nums, 0 ,ans);
        return ans;
    }
};
int main(){
	Solution helper;
	vector<vector<int>> ans;
	vector<int> nums = {1,2,3};
	vector<vector<int>> result = helper.permute(nums);
    cout<<" total permutation -"<<result.size()<<endl;
    
    for(const auto& perm : result){
    	cout<<"[";
    	for(int val : perm){
    		cout<< val<<"]";
		}
	}

	return 0;
}
