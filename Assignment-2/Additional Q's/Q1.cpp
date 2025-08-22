/*Find two numbers in an array whose difference equals K. Given an array arr[] and a positive 
integer k, the task is to count all pairs (i, j) such that i < j and absolute value of (arr[i] - arr[j]) 
is equal to k*/
#include<iostream>
using namespace std;
int main(){
    int arr[100],k,n,count=0;
    cout<<"Enter the no. of elements in your array:";
    cin>>n;
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the value of difference k:";
    cin>>k;

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] - arr[j] == k || arr[i] - arr[j] == -k){
                count++;
            }
        }
    }

    cout<<"There are "<<count<<" pair(s)"<<endl;

    return 0;

}