
class set
{
private:
	int* pset;
	int ncount;
public:
	set();
	set(set& s);
	~set();
	bool add(int);
	bool remove(int);
	int getcount();
	void print();
	bool ismember(int);
	set operator = (const set& s);
	set operator + (const set& s);
	set operator - (const set& s);
	set operator * (const set& s);
	friend void operator += (set& a,set& s);
	friend void operator -= (set& a,set& s);
	friend void operator *= (set& a,set& s);
	friend void evendelete(set& s);
};
