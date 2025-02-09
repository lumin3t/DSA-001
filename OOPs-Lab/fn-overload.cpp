/*Write a C++ program to overload the function Search() to search an integer key
value and a key value of type double*/
#include<iostream>
using namespace std;
int Search(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}
int Search(double arr[], int size, double key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}
int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int int_index = Search(arr1, 5, 7);
    int double_index = Search(arr2, 5, 2.2);
    if (int_index == -1) {
        cout << "Integer key not found in array" << endl;
    } else {
        cout << "Integer key found at index " << int_index << endl;
    }
    if (double_index == -1) {
        cout << "Double key not found in array" << endl;
    } else {
        cout << "Double key found at index " << double_index << endl;
    }
    return 0;
}