/*String Anagrams  
Given two strings str1 and str2, determine if they form an anagram pair.  
Note: Two strings are considered anagrams if one string can be rearranged to form the other 
string.*/

#include <iostream>
using namespace std;

void bubbleSort(string &str) {
    int n = str.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

bool Anagram(string str1, string str2) {
    if (str1.length() != str2.length()){
        cout<<"Both strings are unequal in length."<<endl;
    }

    bubbleSort(str1);
    bubbleSort(str2);

    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i]){
            return false;
        }
        else if(str1[i]==str2[i]){
            return true;
        }
    }
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
    if(Anagram(str1, str2)){
        cout<<"Strings are anagram"<<endl;
    }
    else{
        cout<<"Strings are not anagram"<<endl;
    }
    return 0;
}
