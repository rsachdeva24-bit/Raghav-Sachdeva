/*String Related Programs 
(c) Write a program to delete all the vowels from the string.*/
#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char word[100],newword[100];
    cout << "Write your word:";
    cin.getline(word,100);
    int j=0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i]!='a' && word[i]!='e' && word[i]!='i' && word[i]!='o' && word[i]!='u') {
            newword[j++] = word[i];
        }
    }
    newword[j] = '\0';

    cout << "String after removing vowels: " << newword << endl;

    return 0;
}
