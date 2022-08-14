class Calculator
{
/* 멤버 변수를 선언함 */
private:
	float m_num1;
	float m_num2;
	float m_result;

/* 멤버 메소드를 선언함 */
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
