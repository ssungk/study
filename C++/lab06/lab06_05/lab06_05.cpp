#include <iostream>
using namespace std;

bool IsLeapYear( int nYear );

void main()
{
	enum MONTHS{JANUARY=1,FEBRUARY=2,MARCH=3,APRIL=4,MAY=5,JUNE=6,JULY=7,AUGUST=8,SETEMBER=9,OCTOBER=10,NOVEMBER=11,DECEMBER=12};

	int nyear,nmonth,ndates;
	cout<< "input year : ";
	cin >> nyear;
	cout << "input month : ";
	cin >> nmonth;

	switch(nmonth)
	{
		case 1:
			ndates = 31;
			break;
		case 2:
			if(IsLeapYear(nyear))
			{
				ndates = 29;
			}
			else
			{
				ndates = 28;
			}
			break;
		case 3:
			ndates = 31;
			break;
		case 4:
			ndates = 30;
			break;
		case 5:
			ndates = 31;
			break;
		case 6:
			ndates = 30;
			break;
		case 7:
			ndates = 31;
			break;
		case 8:
			ndates = 31;
			break;
		case 9:
			ndates = 30;
			break;
		case 10:
			ndates = 31;
			break;
		case 11:
			ndates = 30;
			break;
		case 12:
			ndates = 31;
			break;
		
	}

	cout << nyear <<"년의 " << nmonth << "월달의 일수는 " << ndates << "일입니다." << endl;

	return;
}

bool IsLeapYear( int nYear )
{ 
	if(((nYear%4)==0)&&((nYear%100)!=0)||((nYear%400)==0))
	{
		return true ;
	}
	return false ; 
}