class Calculator
{
/* ��� ������ ������ */
private:
	float m_num1;
	float m_num2;
	float m_result;

/* ��� �޼ҵ带 ������ */
public:
	Calculator(void);	
	void add		(float num1, float num2);
	void substract	(float num1, float num2);
	void multiply	(float num1, float num2);
	void divide		(float num1, float num2);
	bool operValidator	(char oper);
	bool divValidator	(float num2, char oper);
	void operation		(float num1, float num2, char oper);
	void printResult (void);

};
