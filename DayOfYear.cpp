//============================================================================
// Name        : DayOfYear.cpp
// Authors     : Alicia Rustan              << Add your name here
// Version     : 1.1
// Date        : 04/13/2020
// Contact     : arr006@gmail.com           << Add your contact info here
// Description :
// Contributions:
// Alicia Rustan: Created GitHub repo and basic class construction
//============================================================================
#include <iostream>

// DayOfYear class declaration
class DayOfYear
{
private:
    int day;
public:
    DayOfYear();
    DayOfYear(int);
    void setDay(int);
    int getDay() const;
};

void DayOfYear::setDay(int d)
{
    day = d;
}

int DayOfYear::getDay() const
{
    return day;
}


int main()
{

    return 0;
}
