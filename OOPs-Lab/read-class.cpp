/*Given that an EMPLOYEE class contains the data members like E_Number,
E_Name, Basic_salary, DA, HRA, Net_salary and the member functions like Read(),
Calculate_Net_Sal(), and Display(). Write a C++ Program to read the data of N
Employees and Compute the Net_Salary of each employee.*/
#include<iostream>
using namespace std;
class Employee {
    char e_name[20];
    int e_number;
    float basic_salary, da, hra, net_salary;
    public:
        void read();
        float calculate_net_sal();
        void display();
};
void Employee::read() { 
    cout << "\nEnter employee number, name, basic salary, DA, HRA: ";
    cin >> e_number >> e_name >> basic_salary >> da >> hra;
    cout << "\n------------------------------------------------------";
}
float Employee::calculate_net_sal() {
    net_salary = basic_salary + da + hra;
    return net_salary;
}
void Employee::display() {
    cout << "\nEmployee Number: " << e_number;
    cout << "\nEmployee Name: " << e_name;
    cout << "\nBasic Salary: " << basic_salary;
    cout << "\nDearness of Accommodation: " << da;
    cout << "\nHouse Rent Allowance: " << hra;
    cout << "\nNet Salary: " << net_salary;
    cout << "\n------------------------------------------------------";
}
int main () {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    Employee emp[n];
    for (int i=0; i<n; i++) {
        emp[i].read();
        emp[i].calculate_net_sal();
    }
    for (int i=0; i<n; i++) {
        emp[i].display();
    }
    return 0;
}