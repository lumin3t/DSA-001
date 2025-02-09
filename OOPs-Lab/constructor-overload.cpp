/*Write a C++ Program to create a class as COMPLEX and implement the following by
overloading the function ADD() which returns the Complex numbers
a) ADD(C1, C2); C1 is an integer ; C2 is a Complex number.
b) ADD(C1, C2); C1 and C2 are Complex numbers.
*/
#include<iostream>
#include<cmath>  //For abs() function
using namespace std;
class COMPLEX {
    private:
    float real, imaginary;
    public:
    COMPLEX() { //Default constructor
        real = 0;
        imaginary = 0;
    }
    COMPLEX(float r, float i) { //Parameterized constructor
        real = r;
        imaginary = i;
    }
    COMPLEX(int r) { //Constructor with int parameter
        real = r;
        imaginary = 0;
    }
    COMPLEX ADD(COMPLEX C) { //Add fn for 2 complex numbers
        COMPLEX res;
        res.real = real + C.real;
        res.imaginary = imaginary + C.imaginary;
        return res;
    }
    COMPLEX ADD(int r) { //Add fn for Complex numer + int
        COMPLEX res;
        res.real = real + r;
        res.imaginary = imaginary;
        return res;
    }
    void display() { 
        if(imaginary < 0) {
            cout << real << " -i" << abs(imaginary) << endl;
        } else {
            cout << real << " +i" << abs(imaginary) << endl;
        }
    }
};
int main () {
    COMPLEX C1(1, -2);
    COMPLEX C2(3, 4);
    COMPLEX C3;
    C3 = C1.ADD(C2);
    cout << "C1 + C2 = ";
    C3.display();
    C3 = C1.ADD(5);
    cout << "C1 + 5 = ";
    C3.display();
    return 0;
}