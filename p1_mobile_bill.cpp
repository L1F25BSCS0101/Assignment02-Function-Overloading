// Answer 1: SMS must be written as 0 because C++ cannot skip a middle argument
// while supplying a later argument. Default arguments only allow trailing arguments
// to be omitted.
// Answer 2: mobileBill(60, , 1.5) causes a syntax error because the second argument
// is missing. Use mobileBill(60, 0, 1.5).

#include <iostream>
using namespace std;

double mobileBill(int minutes, int sms = 0, double dataGB = 0.0);
void printLine(char ch = '-', int n = 30);

int main() {
    printLine();
    cout << "Bill 1: " << mobileBill(100) << endl;
    cout << "Bill 2: " << mobileBill(100, 50) << endl;
    cout << "Bill 3: " << mobileBill(100, 50, 2.5) << endl;
    printLine('*', 10);
    cout << "Bill 4: " << mobileBill(60, 0, 1.5) << endl;
    printLine('=');
    return 0;
}

double mobileBill(int minutes, int sms, double dataGB) {
    return minutes * 2 + sms + dataGB * 150;
}

void printLine(char ch, int n) {
    for (int i = 0; i < n; i++) cout << ch;
    cout << endl;
}
