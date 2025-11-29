/* Program name: date.h
 * Author: Sahar Musleh
 * Date last updated: 11/26/2025
 * Purpose: Header file for Date class with validation, leap year logic, and operator overloading.
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
    int month;  // Month (1-12)
    int day;    // Day (depends on month and leap year)
    int year;   // Year (> 0)

    // Helper functions for validation
    bool isValidDate(int m, int d, int y) const;
    int daysInMonth(int m, int y) const;

public:
    // Constructor
    Date(int m = 1, int d = 1, int y = 2000);

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
    Date operator+(int days) const;                  // Add days to date
    friend Date operator+(int days, const Date& date); // Add days (int + Date)

    Date operator-(int days) const;                  // Subtract days from date
    friend Date operator-(int days, const Date& date); // Subtract days (int - Date)

    // Increment/Decrement
    Date& operator++();
    Date operator++(int);
    Date& operator--(); 
    Date operator--(int); 

    // Comparison
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator>=(const Date& other) const;

    // Stream Operators
    friend std::ostream& operator<<(std::ostream& out, const Date& date);
    friend std::istream& operator>>(std::istream& in, Date& date);
};

#endif