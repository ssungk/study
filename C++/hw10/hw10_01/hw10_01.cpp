#include <iostream>
#include <iomanip>
#include <string>
#include <list>
using namespace std;


class WordElement
{//단어와 나온 수를 관리하는 클래스
public:
	WordElement();//기본 생성자
	WordElement(const string& str);//단어를 입력 받는 생성자, nCount=1
	WordElement(const WordElement& wc);//복사 생성자
	//	~WordElement();
	void print( void );//strWord 와 nCount를 출력
public: //연산자 오버로드
	WordElement& operator++( void );//나온 횟수를 증가
	bool operator==( const WordElement& wc );//단어가 같은지 비교
	bool operator==( const string& word );//단어가 같은지 비교
	bool operator>( const WordElement& wc );//정렬을 위한 비교, 단어를 비교
	bool operator<( const WordElement& wc );//정렬을 위한 비교, 단어를 비교
	bool operator=( const WordElement& wc );//단어를 대입
protected:
	string strWord;//단어
	int nCount ;//단어가 나온 횟수
	//단어가 나온 횟수를 비교하는 연산자를 friend 함수로 등록
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

bool CompareCount(const WordElement& first, const WordElement& second)// 단어가 나온 횟수를 비교하는 연산자 구현
{
	return 0;
} //나온 횟수로 비교, 횟수가 같다면, 단어로 비교

typedef list<WordElement> LIST_WORDCOUNT;//WordElement를 저장하는 list를 정의

typedef LIST_WORDCOUNT::iterator LIST_WORDCOUNTIter;//WordElement를 저장하는 list의 iterator를 정의

class WordCount 
{//단어를 관리하는 클래스
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
		//m_listWC에 word와 같은 단어가 있으면 m_listWC안에 있는 해당 단어의 횟수를 1증가
		//m_listWC에 word와 같은 단어가 없으면 m_listWC에 신규 단어로 추가
	}
	void sort( void ) 
	{
		//std::list 멤버 함수를 사용하여 m_listWC를 정렬
	}
	void printSrotByWord(void)
	{
		m_listWC.sort();//단어 순 정렬
		cout << "Word count = "<< m_listWC.size() << endl;
		cout << setw(20) << " Word " << setw(5) << " Count "<< endl;
		cout <<"____________________________" << endl;
		//m_listWC의 반복자를 탐색하며 출력
	}
	void printSrotByCount( void )
	{
		//나온 횟수 순으로 정렬, 횟수가 같다면, 단어 순 정렬
		//기본 정보 출력 및 m_listWC의 반복자를 탐색하며 출력
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


	for(;iter != source.end();)//iter이 source.end()와 같지 않을 동안 반복
	{
		//		//iter위치에 'A'~'Z', 'a'~'z'이 외의 값이 있을 경우 iter증가
		//word를 초기화
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



		//' ', ',', '\n', '.'의 특수 문자가 나타나지 않을 동안 iter의 문자를 word에 추가 대입
		wc.addWord(word);//wc에 word를 addWord()함수를 통해 추가

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