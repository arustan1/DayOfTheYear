//============================================================================
// Name        : DayOfYear.cpp
// Authors     : Alicia Rustan, Syed Rehman              << Add your name here
// Version     : 1.1
// Date        : 04/13/2020
// Contact     : arr006@gmail.com, smrehman@dmacc.edu           << Add your contact info here
// Description :
// Contributions:
// Alicia Rustan: Created GitHub repo and basic class construction
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
    DayOfYear();
    DayOfYear(int);
    void setDay(int);
    int getDay() const;
    string setMonth();
    string getMonth() const;
};

//Default Constructor
DayOfYear::DayOfYear() : day(1), month("January") {}

//Parameterized constructor. Uses setMonth() member function to convert day to a month string value.
DayOfYear::DayOfYear(int day) : day(day), month(setMonth()) {}

void DayOfYear::setDay(int d)
{
    day = d;
}

int DayOfYear::getDay() const
{
    return day;
}

//Setter mutator for month member
string DayOfYear::setMonth()
{
    array<int, 12> monthNum{ 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
    array<string, 12> monthName{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    for (int i = 0; i < static_cast<int>(monthNum.size()); i++)
    {
        if ((day <= monthNum[0] && day > 0) || (day <= monthNum[i] && day >= monthNum[i - 1]) && day <= monthNum[11])
            return monthName[i];
        else
            return "ERROR - DAY VALUE NOT VALID";
    }
}

//Getter for month member.
string DayOfYear::getMonth() const {
    return month;
}

int main()
{


    return 0;
}
