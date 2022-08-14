#include <iostream>
#include <time.h>
using namespace std;
#include "datetime.h"

int datetime::count = 0;
datetime* datetime::ary[10]={0};

datetime::datetime()
{
	m_stdatetime.year = 0;
	m_stdatetime.month = 0;
	m_stdatetime.day = 0;
	m_stdatetime.hour = 0;
	m_stdatetime.min = 0;
	m_stdatetime.sec = 0;
	count++;
	ary[count]=this;

}

datetime::datetime(S16 year,S16 month,S16 day,S16 hour,S16 min,S16 sec)
{
	m_stdatetime.year = year;
	m_stdatetime.month = month;
	m_stdatetime.day = day;
	m_stdatetime.hour = hour;
	m_stdatetime.min = min;
	m_stdatetime.sec = sec;
	count++;
	ary[count]=this;
}

datetime::datetime(DATETIME& datetime)
{
	m_stdatetime.year = datetime.year;
	m_stdatetime.month = datetime.month;
	m_stdatetime.day = datetime.day;
	m_stdatetime.hour = datetime.hour;
	m_stdatetime.min = datetime.min;
	m_stdatetime.sec = datetime.sec;
	count++;
	ary[count]=this;
}

datetime::datetime(datetime& datetime)
{
	m_stdatetime.year = datetime.m_stdatetime.year;
	m_stdatetime.month = datetime.m_stdatetime.month;
	m_stdatetime.day = datetime.m_stdatetime.day;
	m_stdatetime.hour = datetime.m_stdatetime.hour;
	m_stdatetime.min = datetime.m_stdatetime.min;
	m_stdatetime.sec = datetime.m_stdatetime.sec;
	count++;
	ary[count]=this;
}

datetime::~datetime()
{
	ary[count]=NULL;
	count--;
}
void datetime::printdate()
{
	cout << m_stdatetime.year << "-" << m_stdatetime.month << "-" <<m_stdatetime.day;	
}
void datetime::printtime()
{
	cout << m_stdatetime.hour << ":" << m_stdatetime.min << ":" <<m_stdatetime.sec;
}
void datetime::printdatetime()
{
	cout << m_stdatetime.year << "-" << m_stdatetime.month << "-" <<m_stdatetime.day << " "<< m_stdatetime.hour << ":" << m_stdatetime.min << ":" <<m_stdatetime.sec;;
}

void datetime::printalldatetime()
{
	cout << "datetime °´Ã¼ÀÇ ¼ö" << count;
	int i;
	for(i=0;i<count;i++)
	{
		ary[i]->printdatetime();
	}
}
void datetime::setcurrenttime()
{
	const time_t timer = time(NULL);
	struct tm * caltime = localtime(&timer);

	m_stdatetime.year = caltime->tm_year+1900;
	m_stdatetime.month = caltime->tm_mon+1;
	m_stdatetime.day = caltime->tm_mday;
	m_stdatetime.hour = caltime->tm_hour;
	m_stdatetime.min = caltime->tm_min;
	m_stdatetime.sec = caltime->tm_sec;
}
void datetime::adddays(int nday)
{
	int d;
	switch(m_stdatetime.month)
	{
	case 1:
		d = 31;
		break;
	case 2:
		if(IsLeapYear(m_stdatetime.year))
		{
			d = 29;
		}
		else
		{
			d = 28;
		}
		break;
	case 3:
		d = 31;
		break;
	case 4:
		d = 30;
		break;
	case 5:
		d = 31;
		break;
	case 6:
		d = 30;
		break;
	case 7:
		d = 31;
		break;
	case 8:
		d = 31;
		break;
	case 9:
		d = 30;
		break;
	case 10:
		d = 31;
		break;
	case 11:
		d = 30;
		break;
	case 12:
		d = 31;
		break;
	}


	for(;nday!=0;nday--)
	{
		m_stdatetime.day++;
		if(m_stdatetime.day > d)
		{
			int d;
			switch(m_stdatetime.month)
			{
			case 1:
				d = 31;
				break;
			case 2:
				if(IsLeapYear(m_stdatetime.year))
				{
					d = 29;
				}
				else
				{
					d = 28;
				}
				break;
			case 3:
				d = 31;
				break;
			case 4:
				d = 30;
				break;
			case 5:
				d = 31;
				break;
			case 6:
				d = 30;
				break;
			case 7:
				d = 31;
				break;
			case 8:
				d = 31;
				break;
			case 9:
				d = 30;
				break;
			case 10:
				d = 31;
				break;
			case 11:
				d = 30;
				break;
			case 12:
				d = 31;
				break;
			}

			m_stdatetime.day = m_stdatetime.day - d;
			m_stdatetime.month++;
		}
		if(m_stdatetime.month > 12)
		{
			m_stdatetime.month = m_stdatetime.month - 12;
			m_stdatetime.year++;
		}
	}
	m_stdatetime.day= m_stdatetime.day + nday;
}
void datetime::subdays(int nday)
{
	for(;nday!=0;nday--)
	{
		m_stdatetime.day--;
		if(m_stdatetime.day==0)
		{
			m_stdatetime.month--;
			if(m_stdatetime.month == 0)
			{
				m_stdatetime.year--;
				m_stdatetime.month = 12;
			}
			int day;
			switch(m_stdatetime.month)
			{

			case 1:
				day = 31;
				break;
			case 2:
				if(IsLeapYear(m_stdatetime.year))
				{
					day = 29;
				}
				else
				{
					day = 28;
				}
				break;
			case 3:
				day = 31;
				break;
			case 4:
				day = 30;
				break;
			case 5:
				day = 31;
				break;
			case 6:
				day = 30;
				break;
			case 7:
				day = 31;
				break;
			case 8:
				day = 31;
				break;
			case 9:
				day = 30;
				break;
			case 10:
				day = 31;
				break;
			case 11:
				day = 30;
				break;
			case 12:
				day = 31;
				break;
			}
			m_stdatetime.day = day;
		}
	}
}
int datetime::gettotalday()
{
	int year = m_stdatetime.year;
	int month = m_stdatetime.month;
	int day = m_stdatetime.day;


	int count=0;


	for(;!((year==0) && (month==1) &&(day==1));)
	{

		day--;
		count++;

		if(day==0)
		{
			month--;
			if(month == 0)
			{
				year--;
				month = 12;
			}

			switch(month)
			{
			case 1:
				day = 31;
				break;
			case 2:
				if(IsLeapYear(year))
				{
					day = 29;
				}
				else
				{
					day = 28;
				}
				break;
			case 3:
				day = 31;
				break;
			case 4:
				day = 30;
				break;
			case 5:
				day = 31;
				break;
			case 6:
				day = 30;
				break;
			case 7:
				day = 31;
				break;
			case 8:
				day = 31;
				break;
			case 9:
				day = 30;
				break;
			case 10:
				day = 31;
				break;
			case 11:
				day = 30;
				break;
			case 12:
				day = 31;
				break;
			}

		}

	}
	return count;
}

