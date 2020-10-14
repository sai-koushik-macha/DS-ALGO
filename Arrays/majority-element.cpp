// Problem statement
// Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
#include <iostream>
using namespace std;

int more_algorithm(int arr[],int n){
    int major=0;
    int count=1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[major]){
            count++;
        }
        else
            count--;
        
        if(count==0){
            count=1;
            major=i;
        }
    }
    count=0;
    // cout<<arr[major]<<endl;
    for(int i=0;i<n;i++){
        if(arr[i]==arr[major]){
            count++;
        }
        else{
            count--;
        }
    }
    if(count>0)
    return arr[major];
    else
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cout<<more_algorithm(arr,n)<<endl;
	return 0;
}