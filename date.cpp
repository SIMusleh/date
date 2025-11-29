/* Program name: date.cpp
 * Author: Sahar Musleh
 * Date last updated: 11/29/2025
 * Purpose: Implements date class with validation, leap year logic, and operator overloading.
 */

#include "date.h"
#include <iomanip>
#include <iostream>

// Helper: Days in month
int date::daysInMonth(int m, int y) const {
    if (m == 2) return isLeapYear(y) ? 29 : 28;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

// Helper: Validate date
bool date::isValidDate(int m, int d, int y) const {
    if (y < 0 || m < 1 || m > 12) return false;
    if (d < 1 || d > daysInMonth(m, y)) return false;
    return true;
}

// Constructor
date::date(int m, int d, int y) {
    if (isValidDate(m, d, y)) {
        month = m; day = d; year = y;
    } else {
        std::cerr << "Invalid date. Setting to 2000-01-01.\n";
        month = 1; day = 1; year = 2000;
    }
}

// Getters
int date::getMonth() const { return month; }
int date::getDay() const { return day; }
int date::getYear() const { return year; }

// Setters
void date::setMonth(int m) {
    if (isValidDate(m, day, year)) month = m;
    else std::cerr << "Invalid month.\n";
}
void date::setDay(int d) {
    if (isValidDate(month, d, year)) day = d;
    else std::cerr << "Invalid day.\n";
}
void date::setYear(int y) {
    if (isValidDate(month, day, y)) year = y;
    else std::cerr << "Invalid year.\n";
}

// Leap Year
bool date::isLeapYear(int y) const {
    if (y % 4 != 0) return false;
    if (y % 100 != 0) return true;
    return (y % 400 == 0);
}

// Add/Subtract days
date date::operator+(int days) const {
    date temp = *this;
    temp.day += days;
    while (temp.day > temp.daysInMonth(temp.month, temp.year)) {
        temp.day -= temp.daysInMonth(temp.month, temp.year);
        temp.month++;
        if (temp.month > 12) { temp.month = 1; temp.year++; }
    }
    return temp;
}
date operator+(int days, const date& dt) { return dt + days; }

date date::operator-(int days) const {
    date temp = *this;
    temp.day -= days;
    while (temp.day < 1) {
        temp.month--;
        if (temp.month < 1) { temp.month = 12; temp.year--; }
        temp.day += temp.daysInMonth(temp.month, temp.year);
    }
    return temp;
}
date operator-(int days, const date& dt) { return dt - days; }

// Increment/Decrement
date& date::operator++() { *this = *this + 1; return *this; }
date date::operator++(int) { date old = *this; ++(*this); return old; }
date& date::operator--() { *this = *this - 1; return *this; }
date date::operator--(int) { date old = *this; --(*this); return old; }

// Comparison
bool date::operator==(const date& other) const {
    return year == other.year && month == other.month && day == other.day;
}
bool date::operator!=(const date& other) const { return !(*this == other); }
bool date::operator<(const date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}
bool date::operator<=(const date& other) const { return *this < other || *this == other; }
bool date::operator>(const date& other) const { return !(*this <= other); }
bool date::operator>=(const date& other) const { return !(*this < other); }

// Stream Operators
std::ostream& operator<<(std::ostream& out, const date& dt) {
    out << dt.year << "-"
        << std::setw(2) << std::setfill('0') << dt.month << "-"
        << std::setw(2) << std::setfill('0') << dt.day;
    return out;
}

std::istream& operator>>(std::istream& in, date& dt) {
    int m, d, y;
    in >> m >> d >> y;
    if (dt.isValidDate(m, d, y)) {
        dt.month = m;
        dt.day = d;
        dt.year = y;
    } else {
        std::cerr << "Invalid input date.\n";
        dt.month = 1; dt.day = 1; dt.year = 2000;
    }
    return in;
}