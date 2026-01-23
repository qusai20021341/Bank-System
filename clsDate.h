#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

class clsDate
{
private:
    short _Year;
    short _Month;
    short _Day;

    static void DaysName()
    {
        cout << "Mon  Tue  Wed  Thu  Fri  Sat  Sun" << endl;
    }

public:

    clsDate()
    {
        time_t t = time(0);
        tm now;
        localtime_s(&now, &t);

        _Year = now.tm_year + 1900;
        _Month = now.tm_mon + 1;
        _Day = now.tm_mday;
    }

    clsDate(short Day, short Month, short Year)
    {
        _Year = Year;
        _Month = Month;
        _Day = Day;
    }

    void Print() 
    {
        cout << _Day << "/" << _Month << "/" << _Year << endl;
    }
     string GetStringDate() 
    {
        return to_string(_Day) +"/"+to_string(_Month)+ "/" + to_string(_Year) ;
    }
    static bool IsLeapYear(short Year)
    {
        return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
    }

    bool IsLeapYear() const
    {
        return IsLeapYear(_Year);
    }

    static short DaysOfYear(short Year)
    {
        return IsLeapYear(Year) ? 366 : 365;
    }

    short DaysOfYear() const
    {
        return DaysOfYear(_Year);
    }

    static short DaysOfMonth(short Month, short Year)
    {
        if (Month < 1 || Month > 12)
            return 0;

        if (Month == 2)
            return IsLeapYear(Year) ? 29 : 28;

        if (Month == 1 || Month == 3 || Month == 5 || Month == 7 ||
            Month == 8 || Month == 10 || Month == 12)
            return 31;

        return 30;
    }

    short DaysOfMonth() const
    {
        return DaysOfMonth(_Month, _Year);
    }

    static short DayOrder(int Day, int Month, int Year)
    {
        int a = (14 - Month) / 12;
        int y = Year - a;
        int m = Month + 12 * a - 2;

        return (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    }
    static short DayOrder(clsDate Date)
    {
        int a = (14 - Date._Month) / 12;
        int y = Date._Year - a;
        int m = Date._Month + 12 * a - 2;

        return (Date._Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    }

    short DayOrder()
    {
        return DayOrder(_Day, _Month, _Year);
    }

    static string DayByOrder(int DayOrder)
    {
        string Days[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
        return Days[DayOrder];
    }

    string DayByOrder()
    {
        return DayByOrder(DayOrder());
    }

    static string MonthName(short Month)
    {
        string Names[12] =
        { "Jan","Feb","Mar","Apr","May","Jun",
          "Jul","Aug","Sep","Oct","Nov","Dec" };

        return Names[Month - 1];
    }

    string MonthName()
    {
        return MonthName(_Month);
    }

    static void MonthCalender(int Month, int Year)
    {
        cout << "\n----------- " << MonthName(Month) << " " << Year << " -----------\n";
        DaysName();

        short NumberOfDays = DaysOfMonth(Month, Year);
        int FirstDayOrder = DayOrder(1, Month, Year);

        int Day = 1;

        for (int i = 0; i < NumberOfDays + FirstDayOrder; i++)
        {
            if (i < FirstDayOrder)
            {
                cout << setw(4) << " ";
            }
            else
            {
                cout << setw(4) << Day;
                Day++;

                if ((i + 1) % 7 == 0)
                    cout << endl;
            }
        }

        cout << "\n----------------------------------------\n";
    }

    void MonthCalender()
    {
        MonthCalender(_Month, _Year);
    }

    static void YearCalender(short Year)
    {
        cout << "\n=============== Calendar " << Year << " ===============\n";

        for (int month = 1; month <= 12; month++)
        {
            MonthCalender(month, Year);
            cout << "\n";
        }
    }

    void YearCalender()
    {
        YearCalender(_Year);
    }

    static bool IsDate1BeforDate2(clsDate D1, clsDate D2)
    {
        if (D1._Year != D2._Year)
            return D1._Year < D2._Year;

        if (D1._Month != D2._Month)
            return D1._Month < D2._Month;

        return D1._Day < D2._Day;
    }

    bool IsDate1BeforDate2(clsDate D2)
    {
        return IsDate1BeforDate2(*this, D2);
    }

    static bool IsDate1EqualToDate2(clsDate D1, clsDate D2)
    {
        return (D1._Year == D2._Year &&
            D1._Month == D2._Month &&
            D1._Day == D2._Day);
    }

    bool IsDate1EqualToDate2(clsDate D2)
    {
        return IsDate1EqualToDate2(*this, D2);
    }

    static void IncreaseDateByOneDay(clsDate& D)
    {
        if (D._Day == DaysOfMonth(D._Month, D._Year))
        {
            D._Day = 1;
            if (D._Month == 12)
            {
                D._Month = 1;
                D._Year++;
            }
            else
            {
                D._Month++;
            }
        }
        else
        {
            D._Day++;
        }
    }

    void IncreaseDateByOneDay()
    {
        IncreaseDateByOneDay(*this);
    }

    static int DaysDifference(clsDate D1, clsDate D2)
    {
        int counter = 0;

        while (IsDate1BeforDate2(D1, D2))
        {
            counter++;
            IncreaseDateByOneDay(D1);
        }

        return counter;
    }

    int DaysDifference(clsDate D2)
    {
        return DaysDifference(*this, D2);
    }
    static int AgeInDays(clsDate BirthDate)
    {
        clsDate Today;
        return DaysDifference(BirthDate, Today);
    }
    static int DaysDifferenceWithNegativeResult(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
    {
        if (IsDate1EqualToDate2(Date1, Date2))
        {
            return 0;
        }
        int Days = 0;
        if (IsDate1BeforDate2(Date1, Date2)) {
            while (IsDate1BeforDate2(Date1, Date2))
            {
                Days++;
                IncreaseDateByOneDay(Date1);
            }
            return IncludeEndDay ? ++Days : Days;
        }
        else {
            while (IsDate1BeforDate2(Date2, Date1))
            {
                Days++;
                IncreaseDateByOneDay(Date2);
            }
            return IncludeEndDay ? ++Days * -1 : Days * -1;
        }

    }
    static void IncreaseDateByXDays(int Days, clsDate& Date)
    {
        for (int i = 0; i < Days; i++)
        {
            IncreaseDateByOneDay(Date);
        }
    }
    static void IncreaseDateByOneWeek(clsDate& Date)
    {
        IncreaseDateByXDays(7, Date);
    }
    static void IncreaseDateByXWeeks(int weeks, clsDate& Date)
    {
        for (int i = 0; i < weeks; i++)
        {
            IncreaseDateByOneWeek(Date);
        }
    }
    static void IncreaseDateByOneMonth(clsDate& Date)
    {
        if (Date._Month == 12)
        {
            Date._Month = 1;
            Date._Year++;
        }
        else {
            Date._Month++;
        }
        if (Date._Day > DaysOfMonth(Date._Month, Date._Year))
        {
            Date._Day = DaysOfMonth(Date._Month, Date._Year);
        }
    }
    static void IncreaseDateByXMonths(int Months, clsDate& Date)
    {
        for (int i = 0; i < Months; i++)
        {
            IncreaseDateByOneMonth(Date);
        }
    }
    static void IncreaseDateByOneYear(clsDate& Date)
    {
        Date._Year++;
    }
    static void IncreaseDateByXYears(int Years, clsDate& Date)
    {
        for (int i = 0; i < Years; i++)
        {
            IncreaseDateByOneYear(Date);
        }
    }
    static void IncreaseDateByXYearsFaster(int Years, clsDate& Date)
    {
        Date._Year += Years;
    }
    static void IncreaseDateByOneDecade(clsDate& Date)
    {
        Date._Year += 10;
    }
    static void IncreaseDateByXDecades(int Decades, clsDate& Date)
    {
        for (int i = 0; i < Decades; i++)
        {
            IncreaseDateByOneDecade(Date);
        }
    }
    static void IncreaseDateByXDecadesFaster(int Decades, clsDate& Date)
    {
        Date._Year += Decades * 10;
    }
    static void IncreaseDateByOneCentury(clsDate& Date)
    {
        Date._Year += 100;
    }
    static void IncreaseDateByOneMillennium(clsDate& Date)
    {
        Date._Year += 1000;
    }
    static void DecreaseDateByOneDay(clsDate& Date)
    {
        if (Date._Day == 1)
        {
            if (Date._Month == 1)
            {
                Date._Month = 12;
                Date._Year--;
                Date._Day = 31;
            }
            else {
                Date._Month--;
                Date._Day = DaysOfMonth(Date._Month, Date._Year);

            }
        }
        else {
            Date._Day--;
        }
    }
    static void DecreaseDateByXDays(int Days, clsDate& Date)
    {
        for (int i = 0; i < Days; i++)
        {
            DecreaseDateByOneDay(Date);
        }
    }
    static void DecreaseDateByOneWeek(clsDate& Date)
    {
        DecreaseDateByXDays(7, Date);
    }
    static void DecreaseDateByXWeeks(int Weeks, clsDate& Date)
    {
        for (int i = 0; i < Weeks; i++)
        {
            DecreaseDateByOneWeek(Date);
        }
    }
    static void DecreaseDateByOneMonth(clsDate& Date)
    {
        if (Date._Month == 1)
        {

            if (Date._Day == DaysOfMonth(Date._Month, Date._Year))
            {

                Date._Day = 31;
            }
            Date._Month = 12;
            Date._Year--;
        }
        else {
            if (Date._Day == DaysOfMonth(Date._Month, Date._Year))
            {
                Date._Day = DaysOfMonth(Date._Month - 1, Date._Year);
            }
            Date._Month--;
        }
    }
    static void DecreaseDateByXMonths(int Months, clsDate& Date)
    {
        for (int i = 0; i < Months; i++)
        {
            DecreaseDateByOneMonth(Date);
        }
    }
    static void DecreaseDateByOneYear(clsDate& Date)
    {
        Date._Year--;
    }
    static void DecreaseDateByXYears(int Years, clsDate& Date)
    {
        for (int i = 0; i < Years; i++)
        {
            DecreaseDateByOneYear(Date);
        }
    }
    static void DecreaseDateByXYearFaster(int Years, clsDate& Date)
    {
        Date._Year -= Years;
    }
    static void DecreaseDateByOneDecade(clsDate& Date)
    {
        DecreaseDateByXYearFaster(10, Date);
    }
    static void DecreaseDateByXDecades(int Decades, clsDate& Date)
    {
        for (int i = 0; i < Decades; i++)
        {
            DecreaseDateByOneDecade(Date);
        }
    }
    static void DecreaseDateByXDecadesFaster(int Decades, clsDate& Date)
    {
        Date._Year -= Decades * 10;
    }
    static void DecreaseDateByOneCentury(clsDate& Date)
    {
        Date._Year -= 100;
    }
    static void DecreaseDateByOneMillennium(clsDate& Date)
    {
        Date._Year -= 1000;
    }
    static bool IsEndOfWeek(clsDate Date)
    {
        return (DayOrder(Date) == 6);
    }
    static bool IsWeekEnd(clsDate Date)
    {
        return (DayOrder(Date) == 5 || DayOrder(Date) == 6);
    }
    static bool IsBusinessDay(clsDate Date)
    {
        return (!IsWeekEnd(Date));
    }
    static short DaysUntilTheEndOfTheWeek(clsDate Date)
    {
        return 6 - DayOrder(Date);
    }
    static short DaysUntilTheEndOfTheMonth(clsDate Date)
    {
        return (DaysOfMonth(Date._Month, Date._Year) - Date._Day);
    }
    static short DaysUntilTheEndOfTheYear(clsDate Date)
    {
        short TotalDays = 0;
        TotalDays += DaysUntilTheEndOfTheMonth(Date);
        if (Date._Month == 12)
        {
            return 31 - Date._Day;
        }
        else {
            for (int i = Date._Month + 1; i <= 12; i++)
            {
                TotalDays += DaysOfMonth(i, Date._Year);
            }
            return TotalDays;
        }

    }
    static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
    {
        int Days = 0;
        while (IsDate1BeforDate2(DateFrom, DateTo))
        {
            if (!IsWeekEnd(DateFrom))
            {
                Days++;
            }
            IncreaseDateByOneDay(DateFrom);
        }
        return Days;
    }
    static clsDate CalculateVacationReturnDate(clsDate Date, short NumberOfDays)
    {
        while (NumberOfDays > 0)
        {

            if (IsBusinessDay(Date))
            {
                NumberOfDays--;
            }

            IncreaseDateByOneDay(Date);

        }

        return Date;
    }
    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return (!IsDate1BeforDate2(Date1, Date2) && !IsDate1EqualToDate2(Date1, Date2));
    }
    static short CompareDates(clsDate Date1, clsDate Date2)
    {
        return IsDate1BeforDate2(Date1, Date2) ? -1 : IsDate1EqualToDate2(Date1, Date2) ? 0 : 1;
    }
    static bool IsValidDate(clsDate Date)
    {
        return (Date._Month > 12 || Date._Month < 1) ? false : (Date._Day <= DaysOfMonth(Date._Month, Date._Year) && Date._Day > 0) ? true : false;
    }
    string GetCurrentTimeString()
    {
        time_t now = time(nullptr);
        tm localTime{};
        localtime_s(&localTime, &now); 

        stringstream ss;
        ss << setw(2) << setfill('0') << localTime.tm_hour << ":"
            << setw(2) << setfill('0') << localTime.tm_min << ":"
            << setw(2) << setfill('0') << localTime.tm_sec;

        return ss.str();
    }

    static string GetSystemDateTimeString()
    {
        time_t now = time(0);
        tm localTime{};
        localtime_s(&localTime, &now); // Visual Studio

        return to_string(localTime.tm_mday) + "/" +
            to_string(localTime.tm_mon + 1) + "/" +
            to_string(localTime.tm_year + 1900) + " - " +
            to_string(localTime.tm_hour) + ":" +
            to_string(localTime.tm_min) + ":" +
            to_string(localTime.tm_sec);
    }




};
