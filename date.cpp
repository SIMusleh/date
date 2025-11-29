/* Program name: date.cpp
 * Author: Sahar Musleh
 * Date last updated: 11/26/2025
 * Purpose: Implements Date class with validation, leap year logic, and operator overloading.
 */

#include "date.h"
#include <iomanip>
#include <stdexcept>

// Helper: Days in month
int Date::daysInMonth(int m, int y) const {
    if (m == 2) return isLeapYear(y) ? 29 : 28;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

// Helper: Validate date
bool Date::isValidDate(int m, int d, int y) const {
    if (y < 0 || m < 1 || m > 12) return false;
    if (d < 1 || d > daysInMonth(m, y)) return false;
    return true;
}

// Constructor
Date::Date(int m, int d, int y) {
    if (isValidDate(m, d, y)) {
        month = m; day = d; year = y;
    } else {
        std::cerr << "Invalid date. Setting to 2000-01-01.\n";
        month = 1; day = 1; year = 2000;
    }
}

// Getters
int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }

// Setters
void Date::setMonth(int m) {
    if (isValidDate(m, day, year)) month = m;
    else std::cerr << "Invalid month.\n";
}
void Date::setDay(int d) {
    if (isValidDate(month, d, year)) day = d;
    else std::cerr << "Invalid day.\n";
}
void Date::setYear(int y) {
    if (isValidDate(month, day, y)) year = y;
    else std::cerr << "Invalid year.\n";
}

// Leap Year
bool Date::isLeapYear(int y) const {
    if (y % 4 != 0) return false;
    if (y % 100 != 0) return true;
    return (y % 400 == 0);
}

// Add/Subtract days
Date Date::operator+(int days) const {
    Date temp = *this;
    temp.day += days;
    while (temp.day > temp.daysInMonth(temp.month, temp.year)) {
        temp.day -= temp.daysInMonth(temp.month, temp.year);
        temp.month++;
        if (temp.month > 12) { temp.month = 1; temp.year++; }
    }
    return temp;
}
Date operator+(int days, const Date& date) { return date + days; }

Date Date::operator-(int days) const {
    Date temp = *this;
    temp.day -= days;
    while (temp.day < 1) {
        temp.month--;
        if (temp.month < 1) { temp.month = 12; temp.year--; }
        temp.day += temp.daysInMonth(temp.month, temp.year);
    }
    return temp;
}
Date operator-(int days, const Date& date) { return date - days; }

// Increment/Decrement
Date& Date::operator++() { *this = *this + 1; return *this; }
Date Date::operator++(int) { Date old = *this; ++(*this); return old; }
Date& Date::operator--() { *this = *this - 1; return *this; }
Date Date::operator--(int) { Date old = *this; --(*this); return old; }

// Comparison
bool Date::operator==(const Date& other) const {
    return year == other.year && month == other.month && day == other.day;
}
bool Date::operator!=(const Date& other) const { return !(*this == other); }
bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}
bool Date::operator<=(const Date& other) const { return *this < other || *this == other; }
bool Date::operator>(const Date& other) const { return !(*this <= other); }
bool Date::operator>=(const Date& other) const { return !(*this < other); }

// Stream Operators
std::ostream& operator<<(std::ostream& out, const Date& date) {
    out << date.year << "-"
        << std::setw(2) << std::setfill('0') << date.month << "-"
        << std::setw(2) << std::setfill('0') << date.day;
    return out;
}
std::istream& operator>>(std::istream& in, Date& date) {
    int m, d, y;
    in >> m >> d >> y;
    if (date.isValidDate(m, d, y)) {
       .day = d; date.year = y;
    } else {
        std::cerr << "Invalid input date.\n";
        date.month = 1; date.day = 1; date.year = 2000;
    }
    return in;
}
