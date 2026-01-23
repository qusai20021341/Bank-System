#pragma once
#include "clsDate.h"
#include <iostream>
using namespace std;
class clsPeriod
{
public:

    clsDate StartDate;
    clsDate EndDate;

    clsPeriod(clsDate StartDate, clsDate EndDate)
    {
        this->StartDate = StartDate;
        this->EndDate = EndDate;

    }

    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {

        return !(clsDate::IsDate1BeforDate2(Period1.EndDate, Period2.StartDate) || clsDate::IsDate1BeforDate2(Period2.EndDate, Period1.StartDate));
    }

    static int PeriodLengthInDays(clsPeriod Period)
    {
        return clsDate::DaysDifference(Period.StartDate, Period.EndDate);
    }

    static bool IsDateWithinPeriod(clsDate Date, clsPeriod Period)
    {
        return !(clsDate::IsDate1BeforDate2(Date, Period.StartDate) || clsDate::IsDate1AfterDate2(Date, Period.EndDate));
    }


    bool IsOverLapWith(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }

    void Print()
    {
        cout << "Period Start: ";
        StartDate.Print();


        cout << "Period End: ";
        EndDate.Print();


    }

};




