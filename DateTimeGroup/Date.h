#include "Libery.h"


class Date
{
private:

	unsigned int day;
	unsigned int month;
	unsigned int year;

public:
	Date()
	{
		SYSTEMTIME st;
		GetSystemTime(&st);
		day = st.wDay;
		month = st.wMonth;
		year = st.wYear;
	}
	
	Date(int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	void DayOfWeek() 
	{
		SYSTEMTIME st;
		GetSystemTime(&st);
		if (st.wDayOfWeek == 0) cout << " Sunday \n";
		else if (st.wDayOfWeek == 1) cout << " Monday\n";
		else if (st.wDayOfWeek == 2) cout << " Tuesday\n";
		else if (st.wDayOfWeek == 3) cout << " Wednesday\n";
		else if (st.wDayOfWeek == 4) cout << " Thursday\n";
		else if (st.wDayOfWeek == 5) cout << " 	Friday\n";
		else if (st.wDayOfWeek == 6) cout << " Saturday\n";
		
	}
	int Getday() const
	{
		return day;
	}
	void Setday(int day)
	{
		this->day = day;
	}
	int Getmonth() const
	{
		return month;
	}
	void Setmonth(int month)
	{
		this->month = month;
	}
	int Getyear() const
	{
		return year;
	}
	void Setyear(int year)
	{
		this->year = year;
	}


	int operator - (const Date&  right)
	{
		int result;

		result = (Getyear() * 365 + Getmonth() * 31 + Getday()) - right.Getyear() * 365 - right.Getmonth() * 31 - right.Getday();
		
		if (result < 0) result *= (-1);

		return result;
	}
	Date operator + ( int days)
	{
		Date result;

		result.day = day + days;
		if (result.day > 31)
		{
			result.day -= 31;
			result.month++;
			if (result.month > 12)
			{
				result.month = 1;
				result.year++;
			}
		}

		return result;
	}

	int operator ++(const int i)
	{
		day++;
		if (day > 31)
		{
			day -= 31;
			month++;
			if (month > 12)
			{
				month = 1;
				year++;
			}
		}
		return 0;
	}
	int operator --(const int i)
	{
		day--;
		if (day < 1)
		{
			day = 31;
			month--;
			if (month < 1)
			{
				month = 12;
				year--;
			}
		}
		return 0;
	}
	bool operator >(const Date& right)
	{
		int result;

		result = (Getyear() * 365 + Getmonth() * 31 + Getday()) - right.Getyear() * 365 - right.Getmonth() * 31 - right.Getday();
		if (result > 0)
		{
			return true;
		}
		else return false;
	}
	bool operator <(const Date& right)
	{
		int result;

		result = (Getyear() * 365 + Getmonth() * 31 + Getday()) - right.Getyear() * 365 - right.Getmonth() * 31 - right.Getday();
		if (result < 0)
		{
			return true;
		}
		else return false;
	}
	bool operator ==(const Date& right)
	{
		int result;

		result = (Getyear() * 365 + Getmonth() * 31 + Getday()) - right.Getyear() * 365 - right.Getmonth() * 31 - right.Getday();
		if (result == 0)
		{
			return true;
		}
		else return false;
	}
	bool operator !=(const Date& right)
	{
		int result;

		result = (Getyear() * 365 + Getmonth() * 31 + Getday()) - right.Getyear() * 365 - right.Getmonth() * 31 - right.Getday();
		if (result == 0)
		{
			return true;
		}
		else return false;
	}
	 
	void PrintDate() const
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 14);
		cout << "Day : " << day << " Month : " << month << " Year : " << year;
		cout << "\n";
		cout << (char)1;
		cout << "\n";
		SetConsoleTextAttribute(h, 7);
	}

};
