/*
Write a function template selection Sort. Write a program that inputs, sorts and outputs 
an integer array and a float array.
*/

#include <iostream>
using namespace std;

int n;

template <class T>
void slection(T num[]) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (num[i] > num[j]) {
                swap(num[i], num[j]);
            }
        }
    }
    cout<<"Swap value are: "<<endl;
    for (int i = 0; i<n; i++) {
        cout<<num[i]<<" ";
    }
}

int main() {
    cout << "Enter number of elements in the array: ";
    cin >> n;

    int a[n];
    float b[n];
    int num;

    cout << "1. In integer 2.In float" << endl;
    cin >> num;

    if (num == 1) {
        cout << "Enter value of integer: " << endl;
        for (int i = 0; i < n; i++) {
            
            cin >> a[i];
        }
        slection(a);
    } else if (num == 2) {
        cout << "Enter value for float: " << endl;
        for (int i = 0; i < n; i++) {
            
            cin >> b[i];
        }
        slection(b);
    } else {
        return 0;
    }

    return 0;
}

/*Created by jayesh pandey*/
