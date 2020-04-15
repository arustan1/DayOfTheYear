//============================================================================
// Name        : DayOfYear.cpp
// Authors     : Alicia Rustan, Syed Rehman, Lincoln Belken              << Add your name here
// Version     : 1.1
// Date        : 04/15/2020
// Contact     : arr006@gmail.com, smrehman@dmacc.edu, lbelken@damcc.edu           << Add your contact info here
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
    void setDay(int);
    int getDay() const;
    void setMonth(string);
    string determineMonth(int);
    string getMonth() const;
    int dayFormat(int);
    void display();
    //Default Constuctor
    DayOfYear(){
        day = 1;
        month = " ";
    };
    //Non-default Constuctor
    DayOfYear(int){
        setMonth(determineMonth(day));
        setDay(dayFormat(day));
    };
};


void DayOfYear::setDay(int d){
    day = d;
}

int DayOfYear::getDay() const{
    return day;
}

void DayOfYear::setMonth(string m){
    month = m;
}

string DayOfYear::determineMonth(int day){
    array<int, 12> monthNum{ 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
    array<string, 12> monthName{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    for (int i = 0; i < static_cast<int>(monthNum.size()); i++){
        if(day <= monthNum[i]){
            return monthName[i];
        }else if (day > monthNum[11]){
            return "ERROR - DAY VALUE NOT VALID";
        }
    }
}

//Getter for month member.
string DayOfYear::getMonth() const {
    return month;
}

//converts the 365 day format into that of the monthly format (ex. 59 -> 28)
int DayOfYear::dayFormat(int day){
    int daysPast = 0;
    array<int, 12> monthNum{ 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
    for(int index = 0; index < static_cast<int>(monthNum.size()); index++){
        if(day <= monthNum[index]){
            day = day - daysPast;
            return day;
        }else {
            daysPast = monthNum[index];
        }
    }
}
//Displays the Month and day of the Month
void DayOfYear::display(){
    cout << month << " " << day << endl;
}

int main(){
    int input;
    DayOfYear year;
    cout << "What day would you like to find (1-365)" << endl;
    cin >> input;
    cout << input << endl;
    year.setMonth(year.determineMonth(input));
    year.setDay(year.dayFormat(input));
    year.display();
}
