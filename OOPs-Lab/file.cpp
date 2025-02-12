/*Write a C++ program to create a le called File1.txt and print its contents in the
reverse order to the File2.txt.
*/
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main(){
    char content[1000];
    char str[1000];
    fstream file1("file1.txt", ios::out);
    cout<<"enter text:";

    //write content to file1
    cin.getline(content,1000);
    file1<<content;
    file1.close();

    //read from file1
    file1.open("file1.txt",ios::in);
    file1.getline(str,1000);
    file1.close();

    //reverse and write to file2
    int length=strlen(str);
    fstream  file2("file2.txt",ios::out);
    for(int i=length-1;i>=0;i--) {
        file2<<str[i];
    }
    file2.close();
    cout<<"reversed content saved to file2.txt";
    return 0;
}