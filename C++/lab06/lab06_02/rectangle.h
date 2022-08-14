class rectangle
{
private:
	int m_nwidth;
	int m_nheight;
public:
	rectangle();
	rectangle(int nwidth,int nheight);
	void store(int nwidth,int nheight);
	void printarea();
};