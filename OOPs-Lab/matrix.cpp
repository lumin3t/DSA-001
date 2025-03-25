#include <iostream>
using namespace std;

class Matrix {
private:
    long m[5][5];
    int row, col;

public:
    //functions
    void getData();
    bool operator==(const Matrix &);
    Matrix operator+(const Matrix &);
    Matrix operator-(const Matrix &);
    friend ostream &operator<<(ostream &, const Matrix &);
}; //what

bool Matrix::operator==(const Matrix &cm) {
    return (row == cm.row && col == cm.col);
}

void Matrix::getData() {
    cout << "Enter rows and columns: ";
    cin >> row >> col;
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> m[i][j];
        }
    }
}

Matrix Matrix::operator+(const Matrix &am) {
    Matrix temp;//new result matrix
    temp.row = row;
    temp.col = col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            temp.m[i][j] = m[i][j] + am.m[i][j];
        }
    }
    return temp;
}

Matrix Matrix::operator-(const Matrix &sm) {
    Matrix temp; //new result matrix
    temp.row = row;
    temp.col = col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            temp.m[i][j] = m[i][j] - sm.m[i][j];
        }
    }
    return temp;
}

ostream &operator<<(ostream &out, const Matrix &d) {
    for (int i = 0; i < d.row; i++) {
        for (int j = 0; j < d.col; j++) {
            out << d.m[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

int main() {
    Matrix m1, m2, m3, m4;
    m1.getData();
    m2.getData();
    if (m1 == m2) {
        m3 = m1 + m2;
        m4 = m1 - m2;
        cout << "Addition:\n" << m3;
        cout << "Subtraction:\n" << m4;
    } else {
        cout << "Matrices must have the same dimensions.\n";
    }
    return 0;
}
