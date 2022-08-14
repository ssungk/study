#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
using namespace std;

template <class TYPE, int MAXSIZE>
class Stack
{
private:
	TYPE elems[MAXSIZE];// (�ڵ��ۼ�) MAXSIZE ������ TYPE�� �迭�� ������ �� �ִ� ���� elems
	int numElems;// (�ڵ��ۼ�) ���� ���ÿ� ���Ե� ������ ���� ���� numElems
public:
	Stack(); // ������
	void push(TYPE const&); // ������ ���� ���� �ʾҴٸ� ����
	void pop(); // ������ ��� ���� �ʴٸ� top ���� ��� �� ����
	TYPE top(); // ������ ��� ���� �ʴٸ� top ���� ��ȯ
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
	} // ������ ��� �ִٸ� true, �׷��� �ʴٸ� false
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
	} // ������ ���� ���ִٸ� true, �׷��� �ʴٸ� false
	int getSize() const 
	{ 
		return numElems;
	} // ������ ���� ���� ��ȯ
};



template <class TYPE, int MAXSIZE>
Stack<TYPE,MAXSIZE>::Stack () : numElems(0)
{
	
} // (�ڵ��ۼ�)�ʱ�ȭ ����Ʈ�� �̿��Ͽ� ��� ����(numElems)�� 0���� �ʱ�ȭ


template <class TYPE, int MAXSIZE>
void Stack<TYPE,MAXSIZE>::push (TYPE const& elem)
{
	if (isFull())
	{ 
		throw out_of_range("Stack<>::push(): stack is full"); 
	}//(����)������ ������ ����� ����ó��

	elems[numElems] = elem;
	numElems++;//(�ڵ��ۼ�) elem�� ���ÿ� �����ϰ� ������ ���� Increment
//	cout << elems[numElems-1] << endl;//(�ڵ��ۼ�) ���Ե� ���Ҹ� ȭ�鿡 ���
}

template <class TYPE, int MAXSIZE>
void Stack<TYPE,MAXSIZE>::pop ()
{
	if (isEmpty()) 
	{ 
		throw out_of_range("Stack<>::pop(): empty stack");
	} // (����)������ �� ��� ����ó��
//	cout << elems[numElems-1] << endl;//���� top�� ���
	numElems--;//(�ڵ��ۼ�) decrement number of elements
}

template <class TYPE, int MAXSIZE>
TYPE Stack<TYPE,MAXSIZE>::top ()
{
	if (isEmpty())
	{
		throw out_of_range("Stack<>::top(): empty stack"); // (����)������ �� ��� ����ó��
	}
	return elems[numElems-1];
}

/* �Է°��� ������ ������ ����� enum ���� */
enum InputType {FUNCTION = 0, OPERATOR, OPERAND};

/* �Է� ó���� ���� ����ü InputToken */
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

/* undoStack ����� undoItem (�޷θ�, �����) */
struct undoItem
{
	double mem; // �޸�
	double result; // ���� �����
};


/* ���� Calc Ŭ���� */
class Calc
{
private :
	Stack<undoItem, 100> undoStack; // undoItem�� undoStack
	double m_Mem; // �޸�
	double m_LeftOper, m_RightOper; // ������
	double m_Result; // ���� ���
	char m_Oerator; // ������
	InputToken inToken; // �Է� ��ū
public :
	Calc(); // ������
	void run(); // ���� ����
	void getInput(); // ����� �Է��� �ް� �Ľ��ϴ� �Լ�
	void Display(); // ��� ȭ�� print
	void Operation(); // ���� ����
	bool isOperator(char* input); // �Էµ� ���ڰ� ������ ���� �Ǻ�
	void Function(); // ���Ű ����(M,C, R, A, S, U, E ��)
	bool isFunction(char* input); // FunctionŰ �Է����� �Ǻ�
	void Undo(); // �޸𸮿� ����� Undo
	int strLen(char *input); // �Էµ� ���� ���� ��ȯ
};

Calc::Calc()
{
	m_Mem=0; 
	m_LeftOper=0,
	m_RightOper=0;
	m_Result=0;
	m_Oerator=0;
	//(�ڵ��ۼ�)��� ���� �ʱ�ȭ �� undoStack�� �ʱⰪ(mem = result = 0) push() 
} // ������

void Calc::Display() //������ ȭ�� ������ �´� �Ű������� �̿��Ͽ� �����Ӱ� ����(�Ʒ� �ڵ�� ����)
{ 
	cout << "-------------------------------------------" << endl;
	if(m_Mem != 0) // ���� �޸𸮿� ����� ���� �ִ� ��� ��[M]���� ȭ�鿡 ���
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
	if(undoStack.getSize()==1)//�ʱ���� undoStack�� ���� ������ 1�� ���
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
	}//(�ڵ��ۼ�) ���Ű �Է����� �Ǵ�
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
		//(�ڵ��ۼ�) ���Ű �Է¿� ���� ���� ���� �ڵ� 
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
	} // �߸��� �Է¿� ���� ����ó�� ����
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
	};//(�ڵ��ۼ�) ������ ���� �Ǵ�
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
		break;//(�ڵ��ۼ�) �Է� �����ڿ� ���� ��Ģ���� ����
	}
	undoItem temp;
	temp.mem = m_Mem;
	temp.result = m_Result;
	
	undoStack.push(temp);

	// (�ڵ� �ۼ�) undoStack �� ���� ����� push();
	system("cls");
	Display();
}

int Calc::strLen(char* input)
{ 
	// ���ڿ� ���̰� ��ȯ
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
		// ����� �Է��� �޾� ��E���� �޾� ����� ������ ���� �ݺ�
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
			//(�ڵ��ۼ�) Token InputType �� ���� ���� �ڵ� �ۼ� 
		}
	}
}

int main()
{
	try
	{ 
		// (����) try .. Catch : ����ó�� ����(from template class)
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

