/*Write a C++ program to create a base class Student, from this inherit a new
class called Exams, containing Marks1, Marks2 and Marks3 as its data members.
Also create another class called Sports having Sports_grade as its data member.
Now, create yet another class but a derived class of Exams and Sports classes and
call it as Awards. Use appropriate member functions in all classes. You can use the
Regno, Name, Semester and Branch as the members of the base class.*/

#include<iostream>
using namespace std;
class Student {
    public:
    int Regno;
    char Name[20];
    int Semester;
    char Branch[3];
    void getStudData() {
        cout << "Enter Regno, Name, Semester, Branch: ";
        cin >> Regno >> Name >> Semester >> Branch;
    }
};
class Exams : public virtual Student {
    public:
    int Marks1, Marks2, Marks3;
    void getExamsData() {
        cout << "Enter Marks1, Marks2, Marks3: ";
        cin >> Marks1 >> Marks2 >> Marks3;
    }
};
class Sports : public virtual Student {
    public:
    int Sports_grade;
    void getSportsData() {
        cout << "Enter Sports Grade: ";
        cin >> Sports_grade;
    }
};
class Awards : public Exams, public Sports {
    public:
    void display() {
        cout << "Name: "<< Student::Name << endl;
        cout << "Regno: "<< Student::Regno << endl;
        cout << "Branch: "<< Student::Branch << endl;
        cout << "Exam semester: " << Exams::Semester << endl;
        cout << "Marks1: " << Marks1 << endl;
        cout << "Marks2: " << Marks2 << endl;
        cout << "Marks3: " << Marks3 << endl;
        cout << "Sports Semester: " << Sports::Semester << endl;
        cout << "Sports Grade: " << Sports_grade << endl;
    }
};
int main () {
    Awards a;
    a.getStudData();
    a.getExamsData();
    a.getSportsData();
    a.display();
    return 0;
}