/*Write a C++ program to create a le called File1.txt and print its contents in the
reverse order to the File2.txt.
*/
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std; 
int main () {
    char content[1000];
    char str[1000];
    fstream fout("file1.txt", ios::out);
    cout<<"Enter txt: ";
    cin.getline(content, 1000);
    fout << content;
    fout.close();

    fstream fin("file1.txt", ios::in);
    fin.getline(str, 1000);
    fin.close();

    fstream fout2("file2.txt", ios::out);
    int len = strlen(str);
    for(int i = len - 1; i >= 0; i--) {
        fout2 << str[i];
    }
    fout2.close();
    cout<<"Reversed content saved in file2";
    return 0;
}