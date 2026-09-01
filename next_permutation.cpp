#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 void nextPermutation(vector<int>& A) {
        //find the pivot
        int pivot = -1, n = A.size();
        for(int i = n-2; i>= 0; i--){
            if(A[i] < A[i+1]){
                pivot = i;
                break;
            }
        }
        if(pivot == -1){
            reverse(A.begin(), A.end()); // in place changes
            return;
        }
        // next larger element
        for(int i = n-1; i>pivot; i--){
            if(A[i] > A[pivot]){
                swap(A[i], A[pivot]);
                break;
            }
        }
        //strep 3. reverse (piv+1 t0 n-1)
        int i = pivot+1, j=n-1;
        while(i<=j){
            swap(A[i++], A[j--]);
        }
    }

	

int main(){
	
	vector<int> A = {1,2,3,0,4,6};
	
	nextPermutation(A);
	
	for(int i=0; i<A.size(); i++){
		cout<<A[i]<<" ";
		
	}
	cout<<endl;
	return 0;
}
