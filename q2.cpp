#include <iostream>
#include <string>
using namespace std;

int main() {
    int passengerCount;
    cout << "Enter number of passengers: ";
    cin >> passengerCount;

    string* passengerNames = new string[passengerCount];

    cout << "Enter passenger names:\n";
    for (int index = 0; index < passengerCount; ++index) {
        cin >> passengerNames[index];
    }

    cout << "\nBoarding sequence:\n";
    for (int index = passengerCount - 1; index >= 0; --index) {
        cout << passengerNames[index] << endl;
    }

    delete[] passengerNames;
    return 0;
}