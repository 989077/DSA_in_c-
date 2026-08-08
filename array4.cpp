#include<iostream>
using namespace std;
main(){
	int nums[] = { 23 -1, 0 , -2, 17};
	int size = 5;
	
	int smallest = INT_MAX;
	for(int i=0; i< size; i++){
		if(nums[i] < smallest){
			smallest = nums[i];
		}
	}
	cout <<'smallest='<< smallest<<endl;
	return 0;
}
