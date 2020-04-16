//============================================================================
// Name        : DayOfYear.cpp
// Authors     : Alicia Rustan, Syed Rehman, Lincoln Belken              << Add your name here
// Version     : 1.11
// Date        : 04/15/2020
// Contact     : arr006@gmail.com, smrehman@dmacc.edu, lbelken@damcc.edu           << Add your contact info here
// Description : This program completes the mini group project for C++ CIS161.
// Contributions:
// Alicia Rustan: Created GitHub repo and basic class construction
// Syed Rehman: Created month determination code, added bounds checking, defined setters, defined constructors, and some random simplification changes
//============================================================================

#include <iostream>
#include <array>
#include <string>

using namespace std;

// DayOfYear class declaration
class DayOfYear
{
private:
    int day;
    string month;
public:
    void setDay(int);
    int getDay() const;
    void setMonth(string);
    string determineMonth(int);
    string getMonth() const;
    int dayFormat(int);
    void print();
    //Default Constuctor
    DayOfYear() {
        day = 1;
        month = " ";
    };
    //Non-default Constuctor
    DayOfYear(int d) {
        setDay(d);
        setMonth(determineMonth(d));
    };
};


void DayOfYear::setDay(int d) {
    day = d;
}

int DayOfYear::getDay() const {
    return day;
}

void DayOfYear::setMonth(string m) {
    month = m;
}

//Determines month from day value
string DayOfYear::determineMonth(int day) {
    array<int, 12> monthNum{ 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
    array<string, 12> monthName{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    //Ensure inputted data will be within bounds
    if (day < 1 || day > monthNum[monthNum.size() - 1])
    {
        day = 1;
        return "ERROR - Day incorrect or out of bounds.";
    }

    //Returns corresponding array value from monthName[] once matching value in monthNum[] is reached
    for (int i = 0; i < static_cast<int>(monthNum.size()); i++)
    {
        if (day <= monthNum[i])
        {
            return monthName[i];
        }
    }
}

//Getter for month member.
string DayOfYear::getMonth() const {
    return month;
}

//converts the 365 day format into that of the monthly format (ex. 59 -> 28)
int DayOfYear::dayFormat(int day) {
    int daysPast = 0;
    array<int, 12> monthNum{ 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

    //Ensure inputted data will be within bounds, returns 0 if data is out of bounds
    if (day < 1 || day > monthNum[monthNum.size() - 1])
    {
        day = 1;
        return 0;
    }

    //Returns calculated day of month value
    for (int index = 0; index < static_cast<int>(monthNum.size()); index++) {
        if (day <= monthNum[index]) {
            return day <= monthNum[0] ? day : day - monthNum[index - 1];
        }
    }

    return 0;
}

//Displays the Month and day of the Month
void DayOfYear::print() {
    cout << month << " " << dayFormat(day) << endl;
}

//Main/driver
int main() {
    int input;
    DayOfYear year;
    string run = "y";

    //Run loop determined by user input
    while (run != "n") {
        cout << "What day would you like to find (1-365)" << endl;
        cin >> input;
        cout << "You entered: " << input << endl;
        year = DayOfYear(input);
        year.print();
        cout << "Run again? y/n: ";
        cin >> run;
    }
}

/* TEST DATA:
What day would you like to find (1-365)
365
You entered: 365
December 31
Run again? y/n: y
What day would you like to find (1-365)
200
You entered: 200
July 19
Run again? y/n: y
What day would you like to find (1-365)
0
You entered: 0
ERROR - Day incorrect or out of bounds. 0
Run again? y/n: y
What day would you like to find (1-365)
366
You entered: 366
ERROR - Day incorrect or out of bounds. 0
Run again? y/n: y
What day would you like to find (1-365)
31
You entered: 31
January 31
Run again? y/n: n
*/