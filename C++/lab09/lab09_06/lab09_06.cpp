#include <iostream>
using namespace std;

template <class TYPE>
class smartAry
{
private:
	TYPE* m_ptr; //(코드 작성) 동적으로 할당 받은 배열을 저장할 수 있는 TYPE형 포인터 변수(m_ptr)
	int arySize;//(코드 작성) 배열 사이즈(arySize)
public:
	smartAry(int size); //생성자
	~smartAry(); //소멸자
	TYPE& operator[] (int idx ); //[]연산자 오버로딩
	int GetSize()
	{
		return (sizeof(m_ptr)/sizeof(m_ptr[0]));//(코드작성) 
	}//배열 길이 반환
};

template <class TYPE>
smartAry<TYPE>::smartAry(int size)
{ 
	arySize = size;
	m_ptr = new TYPE [size];//(코드작성) size 만큼의 TYPE형 동적 배열 할당 및 멤버 변수 초기화 }
}

template <class TYPE>
smartAry<TYPE>::~smartAry()
{	
	delete[] m_ptr;//(코드 작성) 소멸자 - 멤버 변수에 할당된 메모리 해제
}

template <class TYPE>
TYPE& smartAry<TYPE>::operator[] (int idx )
{
	return m_ptr[idx];//(코드 작성) []연산자 오버로딩 - 매개변수로 입력 받은 인덱스의 TYPE& 반환
}

void main()
{
	smartAry<int> arr1(4);
	arr1[0] = 1; arr1[1] = 4;
	int i;
	for(i=0;i<4;i++)
	{
		cout << arr1[i] << endl;
	}//(코드 작성) for문을 이용한 arr1의 출력 코드 작성
	
	smartAry<double> arr2(4);//(코드 작성) 동적 할당된 double형 배열을 저장하는 smartAry 객체(arr2) 생성
	arr2[0] = 5.5; arr2[3] = 3.14;
	for(i=0;i<4;i++)
	{
		cout << arr2[i] << endl;
	}//(코드 작성) for문을 이용한 arr2의 출력 코드 작성
}