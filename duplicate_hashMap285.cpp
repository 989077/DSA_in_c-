#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast= nums[0];
         
       do {
        slow = nums[slow];
        fast = nums[nums[fast]];


       }while(slow != fast);

       slow = nums[0];

       while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
       }
       return slow;
    }
};
int main(){
	Solution sol;
	vector<int> nums = {1,3,4,2,2};
	int result = sol.findDuplicate(nums);
	cout<<"duplicate:-"<<result<<" ";
	
	cout<<endl;
	return 0;
}
