/*Sort an array of 0s, 1s and 2s - Dutch National Flag Problem 
Given an array arr[] consisting of only 0s, 1s, and 2s. The objective is to sort the array, i.e., 
put all 0s first, then all 1s and all 2s in last*/

#include<iostream>
using namespace std;
int main(){
    int n,arr[100];
    cout<<"Enter no. of elements in your array:";
    cin>>n;
    cout<<"Enter the elements in your array(enter only 0s,1s and 2s):"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    cout<<"Your sorted array stands as follows:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}