#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int> arr,int tar,int start ,int end){
	if(start <= end){
		
		int mid = start + (end - start)/2 ;
		
		if(arr[mid] == tar){
			return mid;
		}
			if(arr[mid] <= tar){
				return binarySearch(arr, tar, mid +1, end);
			}
					return binarySearch(arr, start, mid -1, tar);
				}
			
		
	else -1;	
}
	

int main (){
	vector<int> arr = {1,3, 4,6,7,7,8,9};
	int tar = 4;
	int start = 0;
	int end = arr.size() -1;
	int result = binarySearch(arr, tar, start, end);
	
	cout<<"output:-"<<result <<endl;
	return 0;
}
