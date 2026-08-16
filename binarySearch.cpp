#include<iostream>
#include<vector>
using namespace std;
 class Solution{
 	public:
 		int search( const vector<int>& arr, int tar){
 			int st=0, end = arr.size()-1;
 			while(st <= end){
 				int mid =(st + end) /2;
 				
 				if(tar > arr[mid]){
 					st = mid +1;
				 }else if(tar < arr[mid]){
				 	end = mid -1;
				 }else {
				 	return mid;
				 }
			 }
 			return -1;
		 }
 };
 int main()
 {
 	Solution sol;
 	vector<int> arr1 = {-1, 0, 3, 5, 9, 12};
 	int tar1 = 10;
 	cout<< sol.search(arr1,tar1)<<endl;
 	
 	return 0;
 }
