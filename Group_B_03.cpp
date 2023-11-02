/*
Write a function template selection Sort. Write a program that inputs, sorts and outputs 
an integer array and a float array.
*/

#include <iostream>
using namespace std;

template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

template <typename T>
void printArray(const T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int intSize = 5;
    const int floatSize = 6;

    int intArray[intSize] = {5, 2, 9, 1, 5};
    float floatArray[floatSize] = {3.14, 1.23, 2.71, 0.88, 5.55, 4.0};

    cout << "Original Integer Array: ";
    printArray(intArray, intSize);
    selectionSort(intArray, intSize);
    cout << "Sorted Integer Array: ";
    printArray(intArray, intSize);

    cout << "Original Float Array: ";
    printArray(floatArray, floatSize);
    selectionSort(floatArray, floatSize);
    cout << "Sorted Float Array: ";
    printArray(floatArray, floatSize);

    return 0;
}
/*Created by jayesh pandey*/
