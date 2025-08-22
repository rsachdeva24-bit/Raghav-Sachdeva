/*Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion 
if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the number 
of inversions in an array.*/

#include<iostream>
using namespace std;
int main(){
    int n, arr[100], count=0;
    cout<<"Enter the no. of elements in your array:";
    cin>>n;
    cout<<"Enter the elements in your array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }

    cout<<"The number of inversions in this array are:"<<count<<endl;



}