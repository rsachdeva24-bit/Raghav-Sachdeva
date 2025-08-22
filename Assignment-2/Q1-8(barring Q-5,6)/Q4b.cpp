/*String Related Programs 
(b) Write a program to reverse a string.*/

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char word[100];
    cout << "Write your word: ";
    cin.getline(word, 100);

    int length = strlen(word);

    cout << "Reversed Word: ";
    for (int i = length-1; i>=0; i--) {
        cout << word[i];
    }
    cout << endl;

    return 0;
}
