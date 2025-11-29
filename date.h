/* Program name: date.h
 * Author: Sahar Musleh
 * Date last updated: 11/29/2025
 * Purpose: Header file for date class with validation, leap year logic, and operator overloading.
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>

class date {
private:
    int month;  // Month (1-12)
    int day;    // Day (depengs on month and leap year)
    int year;   // Year (> 0)

    bool isValidDate(int m, int d, int y) const;
    int daysInMonth(int m, int y) const;

public:
    // Constructor
    date(int m = 1, int d = 1, int y = 2000);

    // Getters
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    // Setters
    void setMonth(int m);
    void setDay(int d);
    void setYear(int y);

    // Leap Year check
    bool isLeapYear(int y) const;

    // Arithmetic Operators
    date operator+(int days) const;                     // Add days to date
    friend date operator+(int days, const date& dt);    // Add days (int + date)

    date operator-(int days) const;                     // Subtract days from date
    friend date operator-(int days, const date& dt);    // Subtract days (int -date)

    // Increment/Decrement
    date& operator++();    // Pre-increment
    date operator++(int);  // Post-increment
    date& operator--();    // Pre-decrement
    date operator--(int);  // Post-decrement

    // Comparison
    bool operator==(const date& other) const;
    bool operator!=(const date& other) const;
    bool operator<(const date& other) const;
    bool operator<=(const date& other) const;
    bool operator>(const date& other) const;
    bool operator>=(const date& other) const;

    // Stream Operators
    friend std::ostream& operator<<(std::ostream& out, const date& dt);
    friend std::istream& operator>>(std::istream& in, date& dt);
};

#endif