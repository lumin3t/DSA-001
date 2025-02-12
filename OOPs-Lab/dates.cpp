/*Write a C++ Program to create a class called DATE. Accept two valid dates in the
form of DD/MM/YYYY. Implement the following by overloading the operators –
(minus) and + (Plus). Display the results by overloading the operator << after every
operation.
a) No_of _days = D1-D2
b) D1=D1 + No_of _days
where d1 and d2 are date objects, d1>d2 and No_of_days is an integer.*/

#include<iostream>
using namespace std;
class DATE {
    int day, month, year, leap;
    public: 
    DATE(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
        leap = (y%4 == 0);
        //first condition
        if (m==2 && d>(leap ? 29: 28) || d > daysOfMonth(m, leap) || m>12 ) {
            cout<<"Invalid date!!";
        }
    }
    //functions
    /*DATE operator-(int n);
    int operator+(const DATE& d2);
    friend ostream& operator<<(ostream& out, const DATE& d2);*/
    DATE operator+(int n);
    int operator-(const DATE& d2);
    friend ostream& operator<<(ostream& out, const DATE& d2);
    private: 
    static int daysOfMonth(int m, int leap) {
        int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (leap == 1) {
            a[2] = 29;
        }
        return a[m];
    }
};

DATE DATE::operator+(int n) { //days to add
    DATE newDate(day, month, year);
    while(n--) {
        newDate.day++;
        if (newDate.day > daysOfMonth(newDate.month, leap)) {
            newDate.day = 1;
            newDate.month++;
            if (newDate.month > 12) {
                newDate.month = 1;
                newDate.year++;
                newDate.leap = (newDate.year % 4);
            }
      }
  }
  return newDate;
}  

int DATE::operator-(const DATE& d2) {
    int totalDays = 0;
    DATE temp = d2;
    while (temp.day < day || temp.month < month || temp.year < year) {
        totalDays++;
        temp.day++;
        if (temp.day > daysOfMonth(temp.month, leap)) {
            temp.day = 1;
            temp.month++;
            if (temp.month > 12) {
                temp.month = 1;
                temp.year++;
                temp.leap = (temp.year % 4);
            }
        }
    }
    return totalDays;
}

ostream& operator<<(ostream& out, const DATE& d2) { 
    out << d2.day << "/" << d2.month << "/" << d2.year;
    return out;
}
int main () {
    DATE d1(29, 2, 2020);
    DATE d2(15, 12, 2020);
    cout << "D1: " << d1 << endl;
    cout << "D2: " << d2 << endl;

    int diff = d1 - d2;
    cout << "No of days between D1 and D2: " << diff << endl;

    DATE d3 = d1 + diff;
    cout << "D1 + No of days: " << d3 << endl;

    return 0;
}