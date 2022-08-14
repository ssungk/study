typedef unsigned short S16;
enum MONTH{JAN=1,FEB,MAR,APR,MAY,JUN,JUL,AUG,SET,OCT,NOV,DEC};
bool IsLeapYear(int nYear);
struct DATETIME
{
	S16 year;
	S16 month;
	S16 day;
	S16 hour;
	S16 min;
	S16 sec;
};

class datetime
{
private:
	DATETIME m_stdatetime;
public:
	datetime();
	datetime(S16 year,S16 month,S16 day,S16 hour,S16 min,S16 sec);
	datetime(DATETIME& datetime);
	datetime(datetime& datetime);
	static int count;
	const static int arysize = 10;
	static datetime* ary[arysize];
	
	~datetime();
	void printdate();
	void printtime();
	void printdatetime();
	void printalldatetime();
	void setcurrenttime();
	void adddays(int nday);
	void subdays(int nday);
	int gettotalday();

};