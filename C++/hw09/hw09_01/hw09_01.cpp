#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
using namespace std;

template <class TYPE, int MAXSIZE>
class Stack
{
private:
	TYPE elems[MAXSIZE];// (코드작성) MAXSIZE 길이의 TYPE형 배열을 저장할 수 있는 변수 elems
	int numElems;// (코드작성) 현재 스택에 삽입된 원소의 개수 변수 numElems
public:
	Stack(); // 생성자
	void push(TYPE const&); // 스택이 가득 차지 않았다면 삽입
	void pop(); // 스택이 비어 있지 않다면 top 원소 출력 후 제거
	TYPE top(); // 스택이 비어 있지 않다면 top 원소 반환
	bool isEmpty() const 
	{
		if(numElems==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	} // 스택이 비어 있다면 true, 그렇지 않다면 false
	bool isFull() const
	{ 
		if(numElems==MAXSIZE)
		{
			return true;
		}
		else
		{
			return false;
		}
	} // 스택이 가득 차있다면 true, 그렇지 않다면 false
	int getSize() const 
	{ 
		return numElems;
	} // 스택의 원소 개수 반환
};



template <class TYPE, int MAXSIZE>
Stack<TYPE,MAXSIZE>::Stack () : numElems(0)
{
	
} // (코드작성)초기화 리스트를 이용하여 멤버 변수(numElems)을 0으로 초기화


template <class TYPE, int MAXSIZE>
void Stack<TYPE,MAXSIZE>::push (TYPE const& elem)
{
	if (isFull())
	{ 
		throw out_of_range("Stack<>::push(): stack is full"); 
	}//(참고)스택이 가득찬 경우의 예외처리

	elems[numElems] = elem;
	numElems++;//(코드작성) elem을 스택에 삽입하고 원소의 개수 Increment
//	cout << elems[numElems-1] << endl;//(코드작성) 삽입된 원소를 화면에 출력
}

template <class TYPE, int MAXSIZE>
void Stack<TYPE,MAXSIZE>::pop ()
{
	if (isEmpty()) 
	{ 
		throw out_of_range("Stack<>::pop(): empty stack");
	} // (참고)스택이 빈 경우 예외처리
//	cout << elems[numElems-1] << endl;//현재 top을 출력
	numElems--;//(코드작성) decrement number of elements
}

template <class TYPE, int MAXSIZE>
TYPE Stack<TYPE,MAXSIZE>::top ()
{
	if (isEmpty())
	{
		throw out_of_range("Stack<>::top(): empty stack"); // (참고)스택이 빈 경우 예외처리
	}
	return elems[numElems-1];
}

/* 입력값의 종류를 결정에 사용할 enum 선언 */
enum InputType {FUNCTION = 0, OPERATOR, OPERAND};

/* 입력 처리를 위한 구조체 InputToken */
struct InputToken
{
	InputType type;
	union 
	{
		char Operator;
		char function;
		float operand;
	}
	data;
};

/* undoStack 저장될 undoItem (메로리, 결과값) */
struct undoItem
{
	double mem; // 메모리
	double result; // 연산 결과값
};


/* 계산기 Calc 클래스 */
class Calc
{
private :
	Stack<undoItem, 100> undoStack; // undoItem형 undoStack
	double m_Mem; // 메모리
	double m_LeftOper, m_RightOper; // 연산항
	double m_Result; // 연산 결과
	char m_Oerator; // 연산자
	InputToken inToken; // 입력 토큰
public :
	Calc(); // 생성자
	void run(); // 계산기 실행
	void getInput(); // 사용자 입력을 받고 파싱하는 함수
	void Display(); // 결과 화면 print
	void Operation(); // 연산 수행
	bool isOperator(char* input); // 입력된 문자가 연산자 인지 판별
	void Function(); // 기능키 수행(M,C, R, A, S, U, E 등)
	bool isFunction(char* input); // Function키 입력인지 판별
	void Undo(); // 메모리와 결과값 Undo
	int strLen(char *input); // 입력된 문자 길이 반환
};

Calc::Calc()
{
	m_Mem=0; 
	m_LeftOper=0,
	m_RightOper=0;
	m_Result=0;
	m_Oerator=0;
	//(코드작성)멤버 번수 초기화 및 undoStack에 초기값(mem = result = 0) push() 
} // 생성자

void Calc::Display() //본인의 화면 구성에 맞는 매개변수를 이용하여 자유롭게 구현(아래 코드는 샘플)
{ 
	cout << "-------------------------------------------" << endl;
	if(m_Mem != 0) // 계산기 메모리에 저장된 값이 있는 경우 ‘[M]’을 화면에 출력
		cout << "[M] = "<< setw(35) << m_Result << endl;
	else
		cout << " = "<< setw(35) << m_Result << endl;
	cout << "-------------------------------------------" << endl;
	cout << setw(8) << "[U]Undo" << setw(18) << "[Z]Zero" << setw(16) << "[E]Exit" << endl;
	cout << setw(10) << "[M]Store"; cout << setw(8) << "[R]Read"; cout << setw(9) << "[C]Clear";
	cout << setw(6) << "[A]M+"; cout << setw(7) << "[S]M-" << endl;

}

void Calc::Undo()
{
	if(undoStack.getSize()==1)//초기상태 undoStack의 원소 개수가 1인 경우
	{
		cout << "Initial status" << endl;
		system("pause");
	}
	else
	{
		undoStack.pop();
		undoItem temp;
		
		temp = undoStack.top();
		m_Mem = temp.mem;
		m_Result = temp.result;
		
		// Current value pop() from undoStack
		// Set previous value from undoStack
	}
}
bool Calc::isFunction(char* input) 
{ 
	if(*input=='M'||*input=='R'||*input=='C'||*input=='A'||*input=='S'||*input=='U'||*input=='Z'||*input=='E')
	{
		return true;
	}
	else
	{
		return false;
	}//(코드작성) 기능키 입력인지 판단
}
void Calc::Function()
{
	switch(m_Oerator)
	{
	case 'M':
		m_Mem = m_Result;
		undoItem temp;
		temp.mem = m_Mem;
		temp.result = m_Result;
		undoStack.push(temp);
		break;
	case 'R':
		m_Result = m_Mem;
		break;
	case 'C':
		m_Mem = 0;
		break;
	case 'A':
		m_Mem = m_Mem + m_Result;
		break;
	case 'S':
		m_Mem = m_Mem - m_Result;
		break;
	case 'U':
		Undo();
		break;
	case 'Z':
		m_Result = 0;
		break;
	case 'E':
		exit(100);
		break;
		//(코드작성) 기능키 입력에 따른 동작 수행 코드 
	}
	system("cls");
	Display();
}


void Calc::getInput()
{
	char exp[256]={0}; //input array
	char* p_Exp = exp; //point of input array
	cout << "Input : "; 
	cin >> p_Exp;
	if( isFunction(p_Exp) && strLen(p_Exp) == 1 )
	{ 
		// FUNCTION
		inToken.type = FUNCTION;
		inToken.data.function = *p_Exp;
	}
	else if( isOperator(p_Exp) && strLen(p_Exp) == 1) 
	{ 
		// OPERATOR
		inToken.type = OPERATOR;
		inToken.data.Operator = *p_Exp;
	}
	else 
	{ 
		// OPERAND
		inToken.type = OPERAND;
		inToken.data.operand = atof(p_Exp);
	} // 잘못된 입력에 대한 예외처리 생략
}


bool Calc::isOperator(char* input)
{
	if(*input=='+'||*input=='-'||*input=='*'||*input=='/')
	{
		return true;
	}
	else
	{
		return false;
	};//(코드작성) 연산자 인지 판단
}


void Calc::Operation()
{
	switch(m_Oerator)
	{ 
	case '+':
		m_Result = m_LeftOper + m_RightOper;
		break;
	case '-':
		m_Result = m_LeftOper - m_RightOper;
		break;
	case '*':
		m_Result = m_LeftOper * m_RightOper;
		break;
	case '/':
		m_Result = m_LeftOper / m_RightOper;
		break;//(코드작성) 입력 연산자에 따른 사칙연산 수행
	}
	undoItem temp;
	temp.mem = m_Mem;
	temp.result = m_Result;
	
	undoStack.push(temp);

	// (코드 작성) undoStack 에 현재 결과값 push();
	system("cls");
	Display();
}

int Calc::strLen(char* input)
{ 
	// 문자열 길이가 반환
	int count=0;
	while(input[count] != '\0')
		count++;
	return count;
}
void Calc::run()
{
	int i=0;

	while(1)
	{
		// 사용자 입력을 받아 ‘E’를 받아 종료될 때까지 무한 반복
		getInput();
		switch(inToken.type)
		{
		case FUNCTION:
			m_Oerator = inToken.data.function;
			Function();
			break;
		case OPERATOR:
			m_Oerator = inToken.data.Operator;
			i=1;
			break;
		case OPERAND:
			if(i==0)
			{
				m_LeftOper = inToken.data.operand;
			}
			else if(i==1)
			{
				m_RightOper = inToken.data.operand;
				Operation();
				m_LeftOper = m_Result;
				i = 0;
			}
			break;
			//(코드작성) Token InputType 에 따른 수행 코드 작성 
		}
	}
}

int main()
{
	try
	{ 
		// (참고) try .. Catch : 예외처리 구문(from template class)
		Calc Calculator;
		Calculator.Display();
		Calculator.run();
	}
	catch(exception const& ex)
	{
		cerr << "Exception: " << ex.what() << endl;
		return EXIT_FAILURE; // exit program with ERROR status
	}
}

