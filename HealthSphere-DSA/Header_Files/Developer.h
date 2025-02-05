#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
void Color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void rColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); 
}
void displayDeveloperDetails() 
{
    system("CLS");
    Color(3);
    cout<<"\n-------------------------------------------------Developer Details------------------------------------------------------\n";
    rColor();
    Color(14);
    cout<<"1. Meerab Zahra\n";
    rColor();
    cout<<"\t-Role:Developer\n";
    cout<<"\t-Expertise: C++, Data Structures, Algorithms,User Interface Development\n";
    cout<<"\t-E-mail: meerabzahra49@gmail.com\n";   
    rColor();
    Color(14);
    cout<<"2. Adeen Asif\n";
    rColor();
    cout<<"\t-Role:Developer\n";
    cout<<"\t-Expertise: C++, Data Structures, Algorithms, System Design\n";
    cout<<"\t-E-mail: adeenasif07@gmail.com\n";
}
