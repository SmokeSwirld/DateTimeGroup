#pragma once
#include "Libery.h"


class Time
{
private:

	unsigned int hours;
	unsigned int minutes;
	unsigned int seconds;

public:
	Time()
	{
		SYSTEMTIME st;
		GetSystemTime(&st);
		hours = st.wHour;
		minutes = st.wMinute;
		seconds = st.wSecond;
	}

	Time(int hours, int minutes, int seconds)
	{
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
	}
	int Gethours() const
	{
		return hours;
	}
	void Sethours(int hours)
	{
		this->hours = hours;
	}
	int Getminutes() const
	{
		return minutes;
	}
	void Setminutes(int minutes)
	{
		this->minutes = minutes;
	}
	int Getseconds() const
	{
		return seconds;
	}
	void Setseconds(int seconds)
	{
		this->seconds = seconds;
	}
	Time operator + (int andseconds)
	{
		Time result;

		result.seconds = seconds + andseconds;
		if (result.seconds > 1000)
		{
			int razn = result.seconds / 1000;
			result.seconds -= 1000 * razn;
			result.minutes+= razn;
			if (result.minutes > 59)
			{
				int razn2 = result.minutes / 59;
				result.minutes = result.minutes - razn2*59;
				result.hours+= razn2;
			}
		}

		return result;
	}
	bool operator >(const Time& right)
	{
		int result;

		result = (Getseconds()  + Getminutes() * 59 + Gethours()*1000*59) - right.Getseconds()  - right.Getminutes() * 59 - right.Gethours() * 1000 * 59;
		if (result > 0)
		{
			return true;
		}
		else return false;
	}
	bool operator <(const Time& right)
	{
		int result;

		result = (Getseconds() + Getminutes() * 59 + Gethours() * 1000 * 59) - right.Getseconds() - right.Getminutes() * 59 - right.Gethours() * 1000 * 59;
		if (result < 0)
		{
			return true;
		}
		else return false;
	}
	bool operator ==(const Time& right)
	{
		int result;

		result = (Getseconds() + Getminutes() * 59 + Gethours() * 1000 * 59) - right.Getseconds() - right.Getminutes() * 59 - right.Gethours() * 1000 * 59;
		if (result == 0)
		{
			return true;
		}
		else return false;
	}
	bool operator !=(const Time& right)
	{
		int result;

		result = (Getseconds() + Getminutes() * 59 + Gethours() * 1000 * 59) - right.Getseconds() - right.Getminutes() * 59 - right.Gethours() * 1000 * 59;
		if (result != 0)
		{
			return true;
		}
		else return false;
	}
	
	
	void PrintTime() const
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 14);
		cout << "Hours : " << hours << " Minutes : " << minutes << " Seconds : " << seconds;
		cout << "\n";
		cout << (char)1;
		cout << "\n";
		SetConsoleTextAttribute(h, 7);
	}


};