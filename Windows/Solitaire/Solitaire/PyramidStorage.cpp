#include "StdAfx.h"
#include "PyramidStorage.h"


CPyramidStorage::CPyramidStorage(void)
{
	//피라미드모양 2차원 배열을 동적으로 생성
	int i,j;
	m_pointer = new CCard*[7];				//CCard*[7]를 생성 후
	
	for(i=0;i<7;i++)
	{
		m_pointer[i] = new CCard[i+1];		//각 CCard*[i]마다 i+1개씩 배열을 생성 (층이 하나증가할때마다 배열크기도 한개씩 증가해서 배열생성) 
	}
	//새로만든 피마디드모양 배열을 CCard()로 초기화
	for(i=0;i<7;i++)
	{
		for(j=0;j<i+1;j++)
		{
			m_pointer[i][j] = CCard();
		}
	}

	row=0,col=0;				//row와col도 0으로 초기화
}

//소멸자(동적할당 반환처리)
CPyramidStorage::~CPyramidStorage(void)
{
	int i;
	for(i=0;i<7;i++)
	{
		delete[] m_pointer[i];	//동적할당 반환
	}

	delete[] m_pointer;			//동적할당 반환

}

//피라미드스토리지에 삽입함수
void CPyramidStorage::Push(CCard card)
{
	m_pointer[row][col] = card;	//현재 row,col위치에 파라미터로 넘어온 card값을 저장

	if(row==col)				//row,col이 같다면(현재 층이 다채웠다면)
	{
		row++;					//row++(층을 하나 증가)
		col=0;					//행은 0으로 변경
	}
	else						//현재층이 다 안찼다면
	{
		col++;					//row는 그대로 두고 (층을 그대로) 행을 하나 증가
	}
}

//피라미드 스토리지 Draw 함수
void CPyramidStorage::Draw(CDC* pDC, CList<CCard,CCard&>& List)
{
	//28개의 비트맵 변수를 선언해두고
	CBitmap bitmap[28];
	BITMAP bmpinfo[28];

	int i,j,k;
	//28번 반복문을 돌면서(1,2,3,4,5,6,7으로 처리)
	for(i=0,k=0;i<7;i++)
	{
		for(j=0;j<i+1;j++,k++)
		{
			if(m_pointer[i][j].m_CardNum==0)	//만약 card고유번호가 0이면 카드가 없는 것이므로 
			{
				continue;						//나머지 작업을 하지말고 다음 반복문으로 넘어감
			}
			//카드번호가 존재한다면 비트맵 출력
			bitmap[k].LoadBitmapW(m_pointer[i][j].m_CardNum);
			bitmap[k].GetBitmap(&bmpinfo[k]);

			CDC dcmem;
			dcmem.CreateCompatibleDC(pDC);
			dcmem.SelectObject(&bitmap[k]);

			POSITION pos;
			CCard card;
			bool choice=false;				//카드가 선택되었나 체크할 bool변수
			//임시리스트에 카드가 있는지 확인해서 반전시키는 처리
			pos = List.GetHeadPosition();
			while(pos)
			{
				card = List.GetNext(pos);
				if(card==m_pointer[i][j])		//임시리스트에 카드랑 일치하는 카드가 피라미드 스토리지에 있다면
				{
					choice=true;				//choice=true
				}
			}
			//비트맵을 출력
			pDC->BitBlt(400-(i*40)+(j*80),10+(i*50),bmpinfo[k].bmWidth,bmpinfo[k].bmHeight,&dcmem,0,0,SRCCOPY);
			//만약 선택된 카드라면
			if(choice)
			{
				//카드를 반전시켜서 출력
				pDC->BitBlt(400-(i*40)+(j*80),10+(i*50),bmpinfo[k].bmWidth,bmpinfo[k].bmHeight,&dcmem,0,0,DSTINVERT);
			}

		}
	}
}

//피라미드스토리지 마우스클릭 함수
void CPyramidStorage::MouseClick(CPoint point,CList<CCard,CCard&>& List)
{
	int i,j,k;
	CRgn rgn[28];
	POSITION pos;
	CCard card;
	
	//28번 반복분을 실행
	for(i=0,k=0;i<7;i++)
	{
		for(j=0;j<i+1;j++,k++)
		{
			//해당 rgn을 생성
			rgn[k].CreateRectRgn(400-(i*40)+(j*80),10+(i*50),400-(i*40)+(j*80)+71,10+(i*50)+96);
			if(rgn[k].PtInRegion(point))			//rgn안에 point가 있다면
			{
				//맨아래층의 경우
				if(i==6)							
				{
					//선택된게 다시 클릭 됬다면 클릭 상태 해제
					pos= List.GetHeadPosition();

					while(pos)
					{
						card = List.GetNext(pos);
						if(card==m_pointer[i][j])			//임시리스트랑 같은 카드가 잇다면
						{
							List.RemoveAt(List.Find(card));	//임시리스트에 카드를 삭제
							return;
						}
					}
					//이미클릭된게 아니고 선택된 카드의 갯수가 0~1개 일경우
					if(List.GetSize()<2&&m_pointer[i][j].m_CardNum!=0)
					{
						//임시리스트에 현재 카드 추가
						List.AddTail(m_pointer[i][j]);
					}
				}
				//그외 0~5층의 경우
				else
				{
					if(m_pointer[i+1][j].m_CardNum==0&&m_pointer[i+1][j+1].m_CardNum==0)
					{
						//선택된게 다시 클릭 됬다면 클릭 상태 해제
						pos= List.GetHeadPosition();
						
						while(pos)
						{
							card = List.GetNext(pos);
							if(card==m_pointer[i][j])				//임시리스트랑 같은 카드가 잇다면
							{
								List.RemoveAt(List.Find(card));		//임시리스트에 카드를 삭제
								return;
							}
						}
						//이미클릭된게 아니고 선택된 카드의 갯수가 0~1개 일경우
						if(List.GetSize()<2&&m_pointer[i][j].m_CardNum!=0)
						{
							//임시리스트에 현재 카드 추가
							List.AddTail(m_pointer[i][j]);
						}
					}
				}
			}
		}
	}
}

//선택된 카드를 피라미드 스토리지에서 삭제하는 함수
void CPyramidStorage::RemoveChoiceCard(CList<CCard,CCard&>& List)
{
	int i,j,k;
	POSITION pos;
	CCard card;
	//28번 반복문을 돌며
	for(i=0,k=0;i<7;i++)
	{
		for(j=0;j<i+1;j++,k++)
		{
			pos= List.GetHeadPosition();
			while(pos)
			{
				card = List.GetNext(pos);
				if(card==m_pointer[i][j])			//임시리스트랑 겹치는게 있다면
				{
					m_pointer[i][j] = CCard(0,0);	//피라미드스토리지의 card값을 0,0으로 변경(삭제같은 효과)
				}
			}
		}
	}
}

//피라미드 스토리지를 다비우는 함수
void CPyramidStorage::RemoveAll()
{
	//피라미드 모양 배열을 전부 CCard()으로 초기화
	int i,j;
	for(i=0;i<7;i++)
	{
		for(j=0;j<i+1;j++)
		{
			m_pointer[i][j] = CCard();
		}
	}
	//현재 row,col을 0으로 초기화
	row=0,col=0;
}

//피라미드의 데이터를 저장하고 불러오는 함수
void CPyramidStorage::Serialize(CArchive& ar)
{

	int i,j;
	for(int i=0;i<7;i++)//28번 호출
		for(int j=0;j<i+1;j++)
			m_pointer[i][j].Serialize(ar);//card의 serialize 함수 호출
}