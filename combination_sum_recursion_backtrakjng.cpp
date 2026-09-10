#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void combsum(vector<int> &arr, int idx, int target, vector<vector<int>> &ans, vector<int> &combine) {
        // Base case 1: Hit target
        if (target == 0) {
            ans.push_back(combine);
            return;
        }

        // Base case 2: Overshot target or ran out of candidates
        if (idx == arr.size() || target < 0) {
            return;
        }

        // --- CHOICE 1: Include arr[idx] (stay at same idx for reuse) ---
        combine.push_back(arr[idx]);
        combsum(arr, idx, target - arr[idx], ans, combine);
        
        // BACKTRACK
        combine.pop_back();

        // --- CHOICE 2: Exclude arr[idx] (advance to idx + 1) ---
        combsum(arr, idx + 1, target, ans, combine);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        combsum(arr, 0, target, ans, combine);
        return ans;
    }
};
int main(){
	Solution helper;
	vector<int> arr = {1,4,3,5};
	int target = 7;
	
	vector<vector<int>>result = helper.combinationSum(arr, target);
	for(const auto &comb :result){
		cout<<"[";
		for(int num : comb) cout<<num<<" ";
		cout<<" ]\n";
	}
	return 0;
}
