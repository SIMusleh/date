/* Program name: main.cpp
 * Author: Sahar Ismail Musleh
 * Date last updated: 11/26/2025
 * Purpose: Test the Date class functionality.
 */

#include "date.h"
#include <iostream>
using namespace std;

int main() {
    date d1(2, 29, 2024); // Leap year
    cout << "Initial date: " << d1 << endl;

    ++d1;
    cout << "After pre-increment: " << d1 << endl;

    d1++;
    cout << "After post-increment: " << d1 << endl;

    date d2 = d1 + 40;
    cout << "After adding 40 days: " << d2 << endl;

    date d3 = d2 - 50;
    cout << "After subtracting 50 days: " << d3 << endl;

    cout << "Enter a date (month day year): ";
    date d4;
    cin >> d4;
    cout << "You entered: " << d4 << endl;

    return 0;
}
