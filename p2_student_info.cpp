// Answer 1: printInfo(string, int) runs because char 'B' is promoted to int.
// The character code for 'B' is 66, so the output shows 66.
// Answer 2: Functions cannot be overloaded by return type alone. Having both
// void printInfo(char) and int printInfo(char) causes a redefinition/ambiguity error.
// Answer 3: printInfo(string, int) and printInfo(int, string) differ by parameter order.

#include <iostream>
#include <string>
using namespace std;

void printInfo(string name) {
    cout << "Name: " << name << endl;
}

void printInfo(string name, int rollNo) {
    cout << "Name: " << name << " | Roll No: " << rollNo << endl;
}

void printInfo(int rollNo, string name) {
    cout << "Roll No: " << rollNo << " | Name: " << name << endl;
}

void printInfo(string name, double cgpa) {
    cout << "Name: " << name << " | CGPA: " << cgpa << endl;
}

void printInfo(char grade) {
    cout << "Grade: " << grade << endl;
}

int main() {
    printInfo("Ali");
    printInfo("Ali", 12);
    printInfo(12, "Ali");
    printInfo("Ali", 3.5);
    printInfo('A');
    printInfo("Sara", 'B');
    return 0;
}
