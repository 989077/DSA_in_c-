#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
void getallsubsets(vector<int> &nums, vector<int> &ans,vector<vector<int>> &Allsubsets, int i){
if(i == nums.size()){
    Allsubsets.push_back(ans);
    return;
    
}
ans.push_back(nums[i]);
getallsubsets(nums, ans, Allsubsets, i+1);
ans.pop_back();

int idx = i+1;
while(idx < nums.size() && nums[idx] == nums[i]) idx++ ;
getallsubsets(nums, ans, Allsubsets, idx);

}
   vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
        vector<vector<int>> Allsubsets;
        vector<int> ans;
        
        getallsubsets(nums, ans, Allsubsets, 0);
        return Allsubsets;
    }
};
int main() {
    Solution solver;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = solver.subsetsWithDup(nums);

    cout << "uniq subsets (" << result.size() << "):\n";

    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) { // Inner loop to print vector contents
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
