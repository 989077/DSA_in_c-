#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
class Solution {
public:
void  getpermute(vector<int> &nums, int idx, vector<vector<int>> &ans ){
    if(idx == nums.size()){
        ans.push_back(nums);
        return;
    }
        unordered_set<int> visited;

        for(int i = idx; i< nums.size(); i++){
            if(visited.count(nums[i])){
                continue;
            }
            //swap element into current position
            visited.insert(nums[i]);
            swap(nums[idx], nums[i]);

            // recurse for remaining
            getpermute(nums, idx + 1, ans);
            // backtrack
             swap(nums[idx], nums[i]);
        }
        

    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        getpermute(nums, 0, ans);
        return ans;
    }
};
int main(){
	Solution helper;
	vector<vector<int>> ans;
	vector<int> nums = {1,1,3};
	vector<vector<int>> result = helper.permuteUnique(nums);
    cout<<" total permutation -"<<result.size()<<endl;
    
    for(const auto& perm : result){
    	cout<<"[";
    	for(int val : perm){
    		cout<< val<<"]";
		}
	}

	return 0;
}
