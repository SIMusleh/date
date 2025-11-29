/* Program name: main.cpp
 * Author: Sahar Ismail Musleh
 * Date last updated: 11/26/2025
 * Purpose: Test the Date class functionality.
 */

#include "date.h"
#include <iostream>
using namespace std;

int main() {
    Date d1(2, 29, 2024); // Leap year
    cout << "Initial: " << d1 << endl;
    d1++;
    cout << "After increment: " << d1 << endl;

    Date d2 = d1 + 40;
    cout << "After adding 40 days: " << d2 << endl;

    Date d3;
    cout << "Enter a date (month day year): ";
    cin >> d3;
    cout << "You entered: " << d3 << endl;

    return 0;
}
