#include <iostream>
#include <stdlib.h>
using namespace std;
class DATE {
    int day, month, year, leap;

public:
    DATE(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
        leap = (y % 4 == 0);

        if ((m == 2 && d > (leap ? 29 : 28)) || d > daysInMonth(m, leap) || m > 12) {
            cout << "Invalid date!" << endl;
            exit(0);
        }
    }

    int operator-(const DATE& d2);
    DATE operator+(int n);
    friend ostream& operator<<(ostream& out, const DATE& d);

private:
    static int daysInMonth(int m, int isLeap) {
        int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeap) days[2] = 29;
        return days[m];
    }
};

int DATE::operator-(const DATE& d2) {
    if (year < d2.year || (year == d2.year && month < d2.month) ||
        (year == d2.year && month == d2.month && day < d2.day)) {
        cout << "Error: Second date is later than first date." << endl;
        exit(0);
    }

    int totalDays = 0;
    DATE temp = d2;

    while (temp.year < year || temp.month < month || temp.day < day) {
        temp.day++;
        if (temp.day > daysInMonth(temp.month, temp.leap)) {
            temp.day = 1;
            temp.month++;
            if (temp.month > 12) {
                temp.month = 1;
                temp.year++;
                temp.leap = (temp.year % 4 == 0);
            }
        }
        totalDays++;
    }
    return totalDays;
}

DATE DATE::operator+(int n) {
    DATE newDate(day, month, year);
    while (n--) {
        newDate.day++;
        if (newDate.day > daysInMonth(newDate.month, newDate.leap)) {
            newDate.day = 1;
            newDate.month++;
            if (newDate.month > 12) {
                newDate.month = 1;
                newDate.year++;
                newDate.leap = (newDate.year % 4 == 0);
            }
        }
    }
    return newDate;
}

ostream& operator<<(ostream& out, const DATE& d) {
    out << d.day << "/" << d.month << "/" << d.year;
    return out;
}

int main() {


    int d, m, y, daysToAdd;

    // Accept first date
    cout << "Enter first date (DD MM YYYY): ";
    cin >> d >> m >> y;
    DATE d1(d, m, y);

    // Accept second (earlier) date
    cout << "Enter second (earlier) date (DD MM YYYY): ";
    cin >> d >> m >> y;
    DATE d2(d, m, y);

    // Calculate difference
    int diff = d1 - d2;
    cout << "Difference: " << diff << " days" << endl;

    // Add days to first date
    cout << "Enter days to add to first date: ";
    cin >> daysToAdd;
    d1 = d1 + daysToAdd;
    cout << "New date: " << d1 << endl;
    return 0;
}