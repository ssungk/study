#include "StdAfx.h"
#include "Card.h"


CCard::CCard(void)
{
	//기본 생성자는 0으로 초기화
	m_CardNum = 0;
	m_Num = 0;
}


CCard::~CCard(void)
{
}


CCard::CCard(int CardNum, int Num)
{
	//카드번호와 카드의 수를 파라미터로 받는 생성자
	m_CardNum = CardNum;
	m_Num = Num;
}

//카드의 데이터를 저장하고 불러오는 함수
void CCard::Serialize(CArchive& ar)  
{
	if (ar.IsStoring())//저장 코드
	{
		ar<<m_CardNum<<m_Num;
	}
	else//로딩 코드
	{
		ar>>m_CardNum>>m_Num;
	}
}