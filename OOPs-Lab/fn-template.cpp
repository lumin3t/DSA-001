/*. Write a C++ program to find the following using Function Template
a) Successor value of any input of type integer, float, char and double.
b) Sum of all the elements of an array of integers or floats or doubles.*/
#include<iostream>
using namespace std;

template <class T>
T successor(T value) {
    return value + 1;
}
template <class X>
X sumArray(X arr[], int size) {
    X sum = 0;  
    for(int i=0; i<size; i++) {
        sum += arr[i];
    }
    return sum;
}
int main() {
    cout << "Successor of 10: " << successor(10) << endl;
    cout << "Successor of 2.5: " << successor(2.5) << endl;
    cout << "Successor of 'a': " << successor('a') << endl;
    int arr1[3] = {1, 2, 3};
    float arr2[3] = {1.1, 2.2, 3.3};
    double arr3[3] = {1.5, 2.5, 3.5};
    cout << "Sum of int array: " << sumArray(arr1, 3) << endl;
    cout << "Sum of float array: " << sumArray(arr2, 3) << endl;
    cout << "Sum of double array: " << sumArray(arr3, 3) << endl;
    return 0;
}