#include<iostream>
using namespace std;

class D2;

class D1 {
    private:
    int meters, centimeters;
    public:
    void getData() {
        cout << "Enter meters and centimeters: ";
        cin >> meters >> centimeters;
    }
    friend void add(D1 d1, D2 d2);
};

class D2 {
    private:
    int feet, inches;
    public:
    void getData() {
        cout << "Enter feet and inches: ";
        cin >> feet >> inches;
    }
    friend void add(D1 d1, D2 d2);
};

void add(D1 d1, D2 d2) {
    double d1_inches = d1.meters * 39.37 + d1.centimeters * 0.3937;
    int total_inches = static_cast<int>(d1_inches + d2.inches + d2.feet * 12);
    int final_feet = total_inches / 12;
    int final_inches = total_inches % 12;

    cout << "Final answer: " << final_feet << " feet " << final_inches << " inches" << endl;
}

int main() {
    D1 d1;
    D2 d2;
    d1.getData();
    d2.getData();
    add(d1, d2);
    return 0;
}
