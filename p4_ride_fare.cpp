// Part C:
// fare(10, 40);
// Error: call of overloaded 'fare(int, int)' is ambiguous
// Reason: The second argument int can be converted to double for fare(double, double)
// or to char for fare(double, char); neither conversion is preferred.
// Fix 1: fare(10, 40.0); // explicitly use a double rate
// Fix 2: fare(10, 'B');  // explicitly use a vehicle character
// Note: The exact wording of the compiler error can vary by compiler.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

double fare(double km, double ratePerKm = 40.0);
double fare(double km, double ratePerKm, bool peakHour);
double fare(double km, char vehicle);
double fare(double km, char vehicle, int promoPercent);

int main() {
    cout << "fare(10) = " << fare(10) << endl;
    cout << "fare(10, 30.0) = " << fare(10, 30.0) << endl;
    cout << "fare(10, 30.0, true) = " << fare(10, 30.0, true) << endl;
    cout << "fare(8, 'B') = " << fare(8, 'B') << endl;
    cout << "fare(8, 'C') = " << fare(8, 'C') << endl;
    cout << "fare(8, 'C', 10) = " << fare(8, 'C', 10) << endl;

    // ---- Part B: write your code below this line ----
    int rideCount;
    cout << "How many rides? ";
    cin >> rideCount;

    if (rideCount < 0) {
        cerr << "Number of rides cannot be negative." << endl;
        return 1;
    }

    ofstream outFile("rides.txt");
    if (!outFile) {
        cerr << "Could not open rides.txt for writing." << endl;
        return 1;
    }

    double total = 0.0;
    for (int i = 1; i <= rideCount; i++) {
        char vehicle;
        double km;
        int promo;
        cout << "Ride " << i << " vehicle (B/R/C), km, promo %: ";
        cin >> vehicle >> km >> promo;

        double amount;
        if (promo == 0)
            amount = fare(km, vehicle);
        else
            amount = fare(km, vehicle, promo);

        outFile << "Ride " << i << " (" << vehicle << "), " << km
                << " km -> Rs. " << amount << endl;
        total += amount;
    }
    outFile << "Total collected: Rs. " << total << endl;
    outFile.close();

    return 0;
}

double fare(double km, double ratePerKm) {
    return 100 + km * ratePerKm;
}

double fare(double km, double ratePerKm, bool peakHour) {
    double amount = fare(km, ratePerKm);
    if (peakHour) amount *= 1.20;
    return amount;
}

double fare(double km, char vehicle) {
    double rate;
    switch (vehicle) {
        case 'B': rate = 25.0; break;
        case 'R': rate = 35.0; break;
        case 'C': rate = 50.0; break;
        default: return 0.0;
    }
    return fare(km, rate);
}

double fare(double km, char vehicle, int promoPercent) {
    double amount = fare(km, vehicle);
    return amount - amount * promoPercent / 100.0;
}
