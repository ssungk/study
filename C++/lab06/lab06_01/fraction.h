class fraction
{
private:
	int* m_pnum;
	int* m_pdenom;

public:
	fraction();
	~fraction();
	void store(int num,int denom);
	void print();
};


