#include<iostream>
using namespace std;

class Student {
    public:
    int usn;
    string name;
    int age;
    void readData();
};

class UGStudent : public Student {
    public:
    int semester, stipend;
    float fees;
    void readData();
};

class PGStudent : public Student {
    public:
    int semester, stipend;
    float fees;
    void readData();
};

void Student::readData() {
    cout << "Enter USN, Name, Age: ";
    cin >> usn >> name >> age;
}

void UGStudent::readData() {
    Student::readData();
    cout << "Enter UG semester, stipend, fees: ";
    cin >> semester >> stipend >> fees;
}

void PGStudent::readData() {
    Student::readData();
    cout << "Enter PG semester, stipend, fees: ";
    cin >> semester >> stipend >> fees;
}

int main()
{
    UGStudent ug[20];
    PGStudent pg[20];
    int n, m;
    float average;

    cout << "\nEnter the no. of entries in the UGStudent class: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        ug[i].readData();

    for (int sem = 1; sem <= 8; sem++)
    {
        float sum = 0;
        int found = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            if (ug[i].semester == sem)
            {
                sum += ug[i].age;
                found = 1;
                count++;
            }
        }
        if (found == 1)
        {
            average = sum / count;
            cout << "\nAverage age of semester " << sem << " for UG students is " << average;
        }
    }

    cout << "\nEnter the no. of entries in the PGStudent class: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        pg[i].readData();

    for (int sem = 1; sem <= 8; sem++)
    {
        float sum = 0;
        int found = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            if (pg[i].semester == sem)
            {
                sum += pg[i].age;
                found = 1;
                count++;
            }
        }
        if (found == 1)
        {
            average = sum / count;
            cout << "\nAverage age of semester " << sem << " for PG students is " << average;
        }
    }

    return 0;
}
