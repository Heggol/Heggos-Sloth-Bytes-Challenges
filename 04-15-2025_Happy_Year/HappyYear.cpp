#include <iostream>
#include <string>
#include <unordered_set>

bool isHappyYear(int year) {
    std::string yearStr = std::to_string(year);
    std::unordered_set<char> digits;

    for (char digit : yearStr) {
        // If a digit is duplicated, return false
        if (digits.find(digit) != digits.end()) {
            return false;
        }
        digits.insert(digit);
    }
    // If all digits are unique, return true
    return true;
}

int findNextHappyYear(int year) {
    // the year should have at least 4 digits
    if (year < 1000) {
        year = 1000;
    } 
    int nextYear = year;
    //while the next year is not a happy year, increment the year
    while (!isHappyYear(nextYear)) {
        nextYear++;
    }
    return nextYear;
}

int main() {
    int inputYear = 0;;
    // standard input for the year
    std::cout << "Find the next happy year \n ";
    std::cout << "Enter a year (between 0 and 9999):";
    std::cin >> inputYear;
    // the year cannot be negative or greater than 9999 
    // 9999 is the maximum year for the Gregorian calendar in .net (see https://learn.microsoft.com/en-us/dotnet/api/system.globalization.gregoriancalendar.maxsupporteddatetime?view=net-9.0)
    if (inputYear < 0 || inputYear > 9999) {
        std::cout << "Please enter a valid year between 0 and 9999.\n";
        return 1;
    } else {
        int happyYear =  findNextHappyYear(inputYear);
        std::cout << "The next Happy Year after year " << inputYear << " is:\n";
        std::cout << happyYear;
        std::cout << "\nPress 'Enter' to exit...\n";
        std::cin.get();
        return 0;
    }
}