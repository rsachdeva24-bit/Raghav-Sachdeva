/*Write a program to count the total number of distinct elements in an array of length n.*/
#include<iostream>
using namespace std;
int main(){
    int n, arr[100], count=0;
    cout<<"Enter the no. of elements in your array:";
    cin>>n;
    cout<<"Enter the elements of your array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
            if(arr[i] != arr[i+1]){
                count++;
            }
        }

    cout<<"The no. of distinct elements in your array are:"<<count+1<<endl;


}