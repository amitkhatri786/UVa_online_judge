#include <iostream>
#include <cstdio>
using namespace std;
 
// this follows Gregorian rules
bool isLeapYear(int year)
{
    if (year%400==0) return true;
    if (year%100==0) return false;
    return (year%4==0);
}
 
int main()
{
    int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
 
    int day,month,year, daysToAdvance;
    char line[81];
    cout << "Enter date (dd, mm, yyyy): ";
    cin.getline(line, 80);
    sscanf(line, "(%i, %i, %i)", &day, &month, &year);
    cout << "Enter days to advance: ";
    cin >> daysToAdvance;
 
    for (int i=0;i<daysToAdvance;i++)
    {
        day++;
        if (day > daysPerMonth[month-1] || ( month==2 && day==29 && !isLeapYear(year) ) )
        {
            day = 1;
            month++;
            if (month==13)
            {
                month = 1;
                year++;
            }
        }
    }
 
    char output[80];
    snprintf(output, 80, "(%02i, %02i, %04i)", day, month, year);
    cout << "Result: " << output << endl;
 
    fflush(stdin);
    getchar();
    return 0;
}
