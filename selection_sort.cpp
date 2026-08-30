#include<iostream>
#include<vector>
//create a funtion
void selectionSort(int arr[], int n){
	for(int i =0; i < n-1; n++){
		int smallestIdx = i;
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[smallestIdx]){
				smallestIdx = j;
			}
		}
		swap(arr[i], arr[smallestIdxS]);
	}
};
int main(){
	int n =5;
	int arr[] = {4, 1, 5, 0,4};
	selectionSort(arr, n);
	printArray(arr, n);
	return 0;
	
}
