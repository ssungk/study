#include <iostream>
#include <iomanip>
#include <string>
#include <list>
using namespace std;


class WordElement
{//�ܾ�� ���� ���� �����ϴ� Ŭ����
public:
	WordElement();//�⺻ ������
	WordElement(const string& str);//�ܾ �Է� �޴� ������, nCount=1
	WordElement(const WordElement& wc);//���� ������
	//	~WordElement();
	void print( void );//strWord �� nCount�� ���
public: //������ �����ε�
	WordElement& operator++( void );//���� Ƚ���� ����
	bool operator==( const WordElement& wc );//�ܾ ������ ��
	bool operator==( const string& word );//�ܾ ������ ��
	bool operator>( const WordElement& wc );//������ ���� ��, �ܾ ��
	bool operator<( const WordElement& wc );//������ ���� ��, �ܾ ��
	bool operator=( const WordElement& wc );//�ܾ ����
protected:
	string strWord;//�ܾ�
	int nCount ;//�ܾ ���� Ƚ��
	//�ܾ ���� Ƚ���� ���ϴ� �����ڸ� friend �Լ��� ���
	friend bool CompareCount(const WordElement& first, const WordElement& second);
};

WordElement::WordElement()
{
}

WordElement::WordElement(const string& str)
{
	strWord = str;
	nCount = 1;
}

WordElement::WordElement(const WordElement& wc)
{
	strWord = wc.strWord;
	nCount = wc.nCount;
}

void WordElement::print( void )
{
	cout << setw(20) << strWord << setw(5) << nCount << endl; 
}

WordElement& WordElement::operator++(void)
{
	nCount++;
	return *this;
}

bool CompareCount(const WordElement& first, const WordElement& second)// �ܾ ���� Ƚ���� ���ϴ� ������ ����
{
	return 0;
} //���� Ƚ���� ��, Ƚ���� ���ٸ�, �ܾ�� ��

typedef list<WordElement> LIST_WORDCOUNT;//WordElement�� �����ϴ� list�� ����

typedef LIST_WORDCOUNT::iterator LIST_WORDCOUNTIter;//WordElement�� �����ϴ� list�� iterator�� ����

class WordCount 
{//�ܾ �����ϴ� Ŭ����
public:
	WordCount(){};
	~WordCount(){};
public:
	void addWord( const string& word )
	{
		LIST_WORDCOUNTIter it = m_listWC.begin();

		while(it != m_listWC.end()) 
		{
			if( (*it) == word )
			{
				++(*it);
				return;
			}
			it++;
		}

		m_listWC.push_back( WordElement(word) );

		


		WordElement temp(word);
		m_listWC.push_back(temp);
		//m_listWC�� word�� ���� �ܾ ������ m_listWC�ȿ� �ִ� �ش� �ܾ��� Ƚ���� 1����
		//m_listWC�� word�� ���� �ܾ ������ m_listWC�� �ű� �ܾ�� �߰�
	}
	void sort( void ) 
	{
		//std::list ��� �Լ��� ����Ͽ� m_listWC�� ����
	}
	void printSrotByWord(void)
	{
		m_listWC.sort();//�ܾ� �� ����
		cout << "Word count = "<< m_listWC.size() << endl;
		cout << setw(20) << " Word " << setw(5) << " Count "<< endl;
		cout <<"____________________________" << endl;
		//m_listWC�� �ݺ��ڸ� Ž���ϸ� ���
	}
	void printSrotByCount( void )
	{
		//���� Ƚ�� ������ ����, Ƚ���� ���ٸ�, �ܾ� �� ����
		//�⺻ ���� ��� �� m_listWC�� �ݺ��ڸ� Ž���ϸ� ���
	}
protected:
	LIST_WORDCOUNT m_listWC;
};

void WordCounting (string& source);

int main ( void ) 
{
	string theLittlePrince = "\
							 Once when man.\n\
							 ";
	WordCounting( theLittlePrince );

	return 0;
}

void WordCounting (string& source) 
{
	string::iterator iter = source.begin();
	string word;
	WordCount wc;


	for(;iter != source.end();)//iter�� source.end()�� ���� ���� ���� �ݺ�
	{
		//		//iter��ġ�� 'A'~'Z', 'a'~'z'�� ���� ���� ���� ��� iter����
		//word�� �ʱ�ȭ
		if((*iter != ' ')&&*iter !=','&&*iter !='\n'&&*iter !='.')
		{
			word += (*iter);
			iter++;
		}
		else
		{
			cout << word << "      "; 
			iter++;
			word.erase();

		}



		//' ', ',', '\n', '.'�� Ư�� ���ڰ� ��Ÿ���� ���� ���� iter�� ���ڸ� word�� �߰� ����
		wc.addWord(word);//wc�� word�� addWord()�Լ��� ���� �߰�

	}
	cout << "Print Srot By Word" << endl;
	wc.printSrotByWord();
	system( "pause" );
	cout << endl << "Print Srot By Count" << endl;
	//	wc.printSrotByCount();
}




/*for(;(*iter != ' ')&&*iter !=','&&*iter !='\n'&&*iter !='.';)
{
word += (*iter);
iter++;
}
for(;*iter !='a'&&*iter !='b'&&*iter !='c'&&*iter !='d'&&*iter !='e'&&*iter !='f'&&*iter !='g'&&*iter !='h'&&*iter !='i'&&*iter !='j'&&*iter !='k'&&*iter !='l'&&*iter !='m'&&*iter !='n'&&*iter !='o'&&*iter !='p'&&*iter !='q'&&*iter !='r'&&*iter !='s'&&*iter !='t'&&*iter !='u'&&*iter !='v'&&*iter !='r'&&*iter !='w'&&*iter !='x'&&*iter !='y'&&*iter !='z'&&*iter !='A'&&*iter !='B'&&*iter !='C'&&*iter !='D'&&*iter !='E'&&*iter !='F'&&*iter !='G'&&*iter !='H'&&*iter !='I'&&*iter !='J'&&*iter !='K'&&*iter !='L'&&*iter !='M'&&*iter !='N'&&*iter !='O'&&*iter !='P'&&*iter !='Q'&&*iter !='R'&&*iter !='S'&&*iter !='T'&&*iter !='U'&&*iter !='V'&&*iter !='R'&&*iter !='W'&&*iter !='X'&&*iter !='Y'&&*iter !='X';)	
{	
if(iter != source.end())
{
iter++;
}
}*/