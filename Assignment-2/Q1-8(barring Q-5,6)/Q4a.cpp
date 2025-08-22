/* String Related Programs 
(a) Write a program to concatenate one string to another string. */

#include<iostream>
#include<string.h>
using namespace std;

int main(){
    char word1[100], word2[100];

    cout<<"Enter first word:";
    cin.getline(word1,100);

    cout<<"Enter second word:";
    cin.getline(word2,100);

    strcat(word1,word2);

    cout<<"Your concatenated string is:"<< word1 <<endl;
}