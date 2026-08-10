#include<iostream>
using namespace std;
int main(){

int n =10;
    //spaces : n-i-1
for(int i=0; i<n; i++){
	
	for(int j=0; j <n-i-1; j++){
		cout<<" ";
}
	//num1: i+1
	for(int j=1; j<= i+1; j++){
		cout<<j;
	
	}
	//nums2
	for(int  j=i; j>0; j--){
		cout<<j;
	}
	cout<<endl;
}

}
