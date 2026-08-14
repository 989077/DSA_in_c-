#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Brute Force Approach: O(N^2) Time, O(1) Space
    int majorityElementBrute(vector<int>& nums) {
        int n = nums.size();
        
        for (int val : nums) {
            int freq = 0;
            for (int el : nums) {
                if (el == val) {
                    freq++;
                }
            }
            if (freq > n / 2) {
                return val;
            }
        }
        return -1;
    }

    // Optimal Approach: Moore's Voting Algorithm - O(N) Time, O(1) Space
    int majorityElementOptimal(vector<int>& nums) {
        int freq = 0;
        int ans = 0;

        // Step 1: Find candidate
        for (int val : nums) {
            if (freq == 0) {
                ans = val;
            }
            if (val == ans) {
                freq++;
            } else {
                freq--;
            }
        }

        // Step 2: Verify candidate (Optional if problem guarantees majority element exists)
        int count = 0;
        for (int val : nums) {
            if (val == ans) {
                count++;
            }
        }

        return (count > nums.size() / 2) ? ans : -1;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 1};
    Solution sol;

    cout << "Brute Force Result: " << sol.majorityElementBrute(nums) << endl;
    cout << "Optimal (Moore's) Result: " << sol.majorityElementOptimal(nums) << endl;

    return 0;
}
