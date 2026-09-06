#include<iostream>
#include<vector>
using namespace std;
bool issorted(vector<int> arr, int n){
 if(n ==1 || n==0){
 	return true;
 }
		return arr[n-1] >= arr[n-2] && issorted(arr, n-1);
	}
	
int main(){
	vector<int> arr = { 1,3,4,5,8,};
	cout<<issorted(arr, arr.size())<<endl;;
	return false;
}
