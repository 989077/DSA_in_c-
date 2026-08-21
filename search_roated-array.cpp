#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& A, int target) {
        if (A.empty()) return -1;
        
        int st = 0, end = A.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (A[mid] == target) {
                return mid;
            }

            // Check if left half is sorted
            if (A[st] <= A[mid]) {
                if (A[st] <= target && target < A[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } 
            // Otherwise, right half is sorted
            else {
                if (A[mid] < target && target <= A[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = sol.search(nums, target);
    cout << "Index of target: " << result << endl; // Output: 4

    return 0;
}
