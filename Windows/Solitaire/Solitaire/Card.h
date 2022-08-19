#pragma once
#include "afx.h"
class CCard 
{
public:
	CCard(void);					//기본생성자
	virtual ~CCard(void);			//소멸자
	CCard(int CardNum, int Num);	//카드고유번호,카드의 수(1~13)를 파라미터로 받는 생성자
	void Serialize(CArchive& ar);  	//카드의 데이터를 저장하고 불러오는 함수
public:
	int m_CardNum;					//카드 고유번호
	int m_Num;						//카드의 수(1~13)
public:
	//find함수를 사용하기 위해 friend bool operator == 정의
	friend bool operator == (const CCard& leftcard, const CCard& rightcard)
	{
		return (leftcard.m_CardNum==rightcard.m_CardNum)&&(leftcard.m_Num==rightcard.m_Num);
	}
	
};
