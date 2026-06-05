#ifndef DATEHELPER_H
#define DATEHELPER_H
#include <string>
#include <ctime>
#include <sstream>
#include <iostream>
using namespace std;

class DateHelper {
public:
    static bool isValidDate(string date) {
        if (date.length() != 10) return false;
        if (date[2] != '/' || date[5] != '/') return false;

        for (int i = 0; i < 10; i++) {
            if (i != 2 && i != 5 && !isdigit(date[i])) return false;
        }

        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        int year = stoi(date.substr(6, 4));

        if (month < 1 || month > 12) return false;
        if (day < 1 || day > 31) return false;
        if (year < 2024) return false;

        return true;
    }

    static bool isOverdue(string dueDate) {
        time_t now = time(0);
        tm* timeinfo = localtime(&now);
        int currentMonth = timeinfo->tm_mon + 1;
        int currentDay = timeinfo->tm_mday;
        int currentYear = timeinfo->tm_year + 1900;

        int dueMonth = stoi(dueDate.substr(0, 2));
        int dueDay = stoi(dueDate.substr(3, 2));
        int dueYear = stoi(dueDate.substr(6, 4));

        if (dueYear < currentYear) return true;
        if (dueYear > currentYear) return false;
        if (dueMonth < currentMonth) return true;
        if (dueMonth > currentMonth) return false;
        return dueDay < currentDay;
    }

    static int daysUntilDue(string dueDate) {
        time_t now = time(0);
        tm* timeinfo = localtime(&now);
        int currentMonth = timeinfo->tm_mon + 1;
        int currentDay = timeinfo->tm_mday;
        int currentYear = timeinfo->tm_year + 1900;

        int dueMonth = stoi(dueDate.substr(0, 2));
        int dueDay = stoi(dueDate.substr(3, 2));
        int dueYear = stoi(dueDate.substr(6, 4));

        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if ((dueYear % 4 == 0 && dueYear % 100 != 0) || (dueYear % 400 == 0)) {
            daysInMonth[2] = 29;
        }

        int days = 0;
        if (dueYear == currentYear) {
            if (dueMonth == currentMonth) {
                days = dueDay - currentDay;
            } else if (dueMonth > currentMonth) {
                for (int i = currentMonth; i < dueMonth; i++) {
                    days += daysInMonth[i];
                }
                days += dueDay - currentDay;
            }
        }
        return days;
    }

    static string getCurrentDate() {
        time_t now = time(0);
        tm* timeinfo = localtime(&now);
        int month = timeinfo->tm_mon + 1;
        int day = timeinfo->tm_mday;
        int year = timeinfo->tm_year + 1900;

        stringstream ss;
        if (month < 10) ss << "0";
        ss << month << "/";
        if (day < 10) ss << "0";
        ss << day << "/" << year;
        return ss.str();
    }
};

#endif