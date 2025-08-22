/*Q1) Develop a Menu driven program to demonstrate the following operations of Arrays 
——MENU——- 
1.CREATE 
2. DISPLAY 
3. INSERT 
4. DELETE 
5. LINEAR SEARCH 
6. EXIT*/

#include<iostream>
using namespace std;

int arr[100];
int n,i;

void createarray(){
   cout<<"Enter no. of elements(should not be zero):"<<endl;
   cin>>n;
   cout<<"Enter the elements:\n"<<endl;
   for(i=0;i<n;i++){
    cin>>arr[i];
   }
   cout<<"Your Array has been created"<<endl;
}

void displayarray(){
    cout<<"Your created array is as follows:"<<endl;
    for(i=0;i<n;i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}

void insertelement(){
    int position, element;
    cout<<"Enter the position where you want to insert your element:";
    cin>> position;
    cout<< "Enter value of element:";
    cin>> element;
    for(int i=n;i>=position;i--){
        arr[i]=arr[i-1];
    }
    arr[position-1] =element;
    n++;
    cout<< "Element inserted\n";
}

void deleteelement(){
    int position;
    cout <<"Enter the position of the element you want to delete:";
    cin>>position;
    for(int i=position-1;i<n-1;i++) {
        arr[i]=arr[i+1];
    }
    n--;
    cout<<"Element deleted\n";
}

void linearsearch(){
    int value,found=0;
    cout<<"Enter value to search:";
    cin>>value;
    for(int i=0;i<n;i++){
        if(arr[i]==value){
            cout<<"Element found at position"<<" "<<i+1<<"\n";
            found=1;
        }
    }
    if(found!=1){
        cout << "Element was not found\n";
    }
}

int main(){
    int choice;
    do{
        cout << "\n MENU \n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: createarray(); break;
        case 2: displayarray(); break;
        case 3: insertelement(); break;
        case 4: deleteelement(); break;
        case 5: linearsearch(); break;
        case 6: cout << "Exiting program...\n"; break;
        default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

