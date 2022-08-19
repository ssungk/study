#include "StdAfx.h"
#include "PyramidTest.h"
#include "resource.h"


CPyramidTest::CPyramidTest(void)
{
	m_shuffle=2;				   //카드 셔플 가능 횟수  
	m_ChoiceList1=false;		   //클릭됬는기 확인하는 bool변수 이므로 생성자에서 false로 초기화
	m_ChoiceList2=false;		   //클릭됬는기 확인하는 bool변수 이므로 생성자에서 false로 초기화
	m_IsDraw=false;				   //애니메이션이 출력됬었는지 확인하는 bool변수이므로 생성자에서 false로 초기화
	m_ReDeal=0;					   //카드패 회전 횟수이므로 생성자에서 0으로 초기화
	m_score=0;					   //현재 사용자가 얻은 점수이므로 0으로 초기화
	m_background=IDB_BITMAPBack;   //배경 비트맵 아이디
}


CPyramidTest::~CPyramidTest(void)
{
}

//새게임 함수
void CPyramidTest::NewGame(void)
{
	//모든 리스트 및 변수를 비우고 0으로 초기화
	PlaySound(_T("Shuffle.wav"), AfxGetInstanceHandle(), SND_ASYNC);
	m_List1.RemoveAll();			//리스트1을 비움
	m_List2.RemoveAll();			//리스트2를 비움
	m_CompleteList.RemoveAll();		//완성리스트를 비움
	m_PyrmidStorage.RemoveAll();	//피라미드스토리지를 비움
	m_TempList.RemoveAll();			//임시리스트를 비움
	m_AniList.RemoveAll();			//애니메이션 리스트를 비움
	m_ReDeal=0;						//카트패 회전수를 0으로 초기화
	m_score=0;                      //사용자 점수를 0으로 초기화
	m_ChoiceList1=false;			//클릭됬는기 확인하는 bool변수 이므로 생성자에서 false로 초기화
	m_ChoiceList2=false;			//클릭됬는기 확인하는 bool변수 이므로 생성자에서 false로 초기화
	m_IsDraw=false;				   //애니메이션이 출력됬었는지 확인하는 bool변수이므로 생성자에서 false로 초기화

	srand((unsigned int)time(NULL));//난수의 시작점 설정
	int randnum;					//난수를 받아올 변수 선언
	int i,j;						//반복문을 위한 i,j변수 선언
	POSITION pos;					//리스트의 POSITION값을 저장해둘 pos변수 선언
	CCard card;						//CCard값을 받아올 card변수 선언

	//리스트2에 카드를 차례대로 생성해서 넣음
	for(i=0;i<52;i++)
	{
		m_List2.AddTail(CCard(i+310,i%13+1));	//카드 고유번호(310~361), 카드의 수(1~13)
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<52;j++)
		{
			m_AniList.AddTail(CCard(j+310,j%13+1));	//카드 고유번호(310~361), 카드의 수(1~13)
		}
	}
	int num;
	//게임을 클리어하기 쉽도록 카드를 배치
	for(i=0;i<52;i++)						//52번 반복
	{
		if((i+1)%13!=0 && (i%13)<=5)//K를 제외한 합이 13이 되는 쌍끼리 순서대로 저장 ex) 1-12, 2-11
		{
			num=i%13+1;                     //카드의 숫자를 저장
			card=CCard(310+i,num);          //합이 13이 되는 값들끼리 들어가도록 배치
			m_List1.AddTail(card);          //리스트1에 card값을 넣음
			pos = m_List2.Find(card);	    //card값으로 부터 pos을 위해
			m_List2.RemoveAt(pos);		    //pos을 이용해 리스트2에 card값을 삭제하고
			if(i<12)
				card=CCard(310+11-i,13-num);    //합이 13이 되는 값들끼리 들어가도록 배치
			else
				card=CCard(310+(11-i%13)+i/13*13,13-num);
			m_List1.AddTail(card);          //리스트1에 card값을 넣음
			pos = m_List2.Find(card);	    //card값으로 부터 pos을 위해
			m_List2.RemoveAt(pos);		    //pos을 이용해 리스트2에 card값을 삭제하고
		}
		else if((i+1)%13==0)//K
		{
			card=CCard(310+i,13);           //카드의 숫자를 저장
			pos = m_List2.Find(card);	    //card값으로 부터 pos을 위해
			m_List2.RemoveAt(pos);		    //pos을 이용해 리스트2에 card값을 삭제하고
			m_List2.AddTail(card);          //리스트의 마지막에 카드를 추가
		}
	}
	//K값 저장
	m_List1.AddTail(CCard(335,13));
	m_List1.AddTail(CCard(348,13));
	m_List1.AddTail(CCard(361,13));
	m_List2.RemoveAll();                    //리스트 초기화
	//피라미드 스토리지에 28개의 카드값을 넣음
	for(i=0;i<28;i++)							//28번 반복
	{
		if(i==0)                                    //피라미드 꼭대기 층
			m_PyrmidStorage.Push(CCard(322,13));    //K 저장
		else
		{
			m_PyrmidStorage.Push(m_List1.GetHead());//리스트1의 Head위치의 card를 피라미드스토리지에 넣고
			m_List1.RemoveHead();					//리스트1의 Head위치의 card값 삭제
		}
	}
}

//마우스 클릭을 처리할 함수
void CPyramidTest::MouseClick(CPoint point)
{
	POSITION pos;			//위치를 저장할 POSITION변수
	CCard card;				//CCard값을 저장할 card변수

	//리스트1을 클릭 했을때 처리
	if(IsClickList1(point))
	{
		pos = m_List1.GetHeadPosition();				//Head의 pos을 받아와서
		if(pos)											//pos이 있다면(즉 리스트에 card가 한개라도 있다면)
		{
			card = m_List1.GetNext(pos);				//Head위치의 card값을 받아옴
			//리스트1을 이미 클릭한 상태일때 클릭 해제
			if(m_ChoiceList1)										//리스트1이 클릭된 상태면	
			{
				m_TempList.RemoveAt(m_TempList.Find(card));			//임시리스트에서 리스트1의 card값을 찾아서 삭제하고
				m_ChoiceList1=false;								//리스트1 선택 상태를 false로 변경
			}
			//임시리스트에 카드가 1개 일때 리스트1이 선택 됨
			else if(m_TempList.GetSize()>0&&m_TempList.GetSize()<2)	//임시리스트에 카드가 1개 있으면
			{
				m_TempList.AddTail(card);							//리스트1의 카드값을 임시리스트에 추가하고
				m_ChoiceList1=true;									//리스트1을 선택된 상태 true로 변경
			}
			//위에 경우가 모두 아니라면 카드를 한장 넘김
			else
			{
				PlaySound(_T("Turn.wav"), AfxGetInstanceHandle(), SND_ASYNC);
				m_List2.AddTail(card);								//리스트1의 카드를 리스트2의 Tail에 추가
				m_List1.RemoveHead();								//리스트1의 카드를 삭제
			}
		}
		//리스트1에 카드가 하나도 없을경우 처리
		else
		{
			if(m_ReDeal<m_shuffle)						    		//반복횟수가 아직 2회가 안될경우
			{
				pos = m_List2.GetHeadPosition();					//리스트2의 pos값을 받아와
				while(pos)
				{
					card = m_List2.GetNext(pos);					//리스트2의 모든 card값을
					m_List1.AddTail(card);							//리스트1에 저장하고
				}
				m_List2.RemoveAll();								//리스트2는 비우고
				m_ReDeal++;											//카드패 반복횟수 증가
			}
		}
	}
	//리스트2를 클릭했을 경우 처리
	if(IsClickList2(point))
	{
		pos = m_List2.GetTailPosition();					//Head의 pos을 받아와서
		if(pos)												//pos이 있다면(즉 리스트에 card가 한개라도 있다면)
		{
			card = m_List2.GetPrev(pos);					//카드값을 뒤쪽부터 받아옴
			//리스트1을 이미 클릭한 상태일때 클릭 해제
			if(m_ChoiceList2)
			{
				m_TempList.RemoveAt(m_TempList.Find(card));	//임시리스트에서 리스트2의 card값을 찾아서 삭제하고
				m_ChoiceList2=false;						//리스트2 선택 상태를 false로 변경
			}
			//카드 선택된게 0~1개 일때 처리
			else if(m_TempList.GetSize()<2)					//카드가 0개에서 1개 선택된 상태일때
			{
				m_TempList.AddTail(card);					//임시리스트에 리스트2의 card값을 추가하고
				m_ChoiceList2=true;							//리스트2를 선택 상태인 true로 변경
			}
		}	
	}
	//피라미드 스토리지 클릭 처리
	if(m_TempList.GetSize()<3)								//카드가 선택된 갯수가 0~2개일때
	{
		m_PyrmidStorage.MouseClick(point,m_TempList);		//피라미드스토리지의 마우스클릭 함수 호출(파라미터로 좌표값과,임시리스트를 &로 넘겨줌)
	}

	//현재 클릭된 카드들의 값을 구해서 13인지 체크하는 처리
	int num=0;												//합을 구하므로 0으로 초기화하고
	pos = m_TempList.GetHeadPosition();						//임시리스트의 pos값을 받아와
	while(pos)												//임시리스트에 카드가 있다면
	{
		card = m_TempList.GetNext(pos);						//카드값을 받아오고
		num+=card.m_Num;									//카드값의 카드수를 num에 더함
	}
	//합이 13일 경우 처리
	if(num==13)												//합이 13이면
	{
		pos = m_TempList.GetHeadPosition();					//임시리스트의 pos값을 받아와
		while(pos)											//임시리스트 값을 전부
		{
			card = m_TempList.GetNext(pos);					//card변수에 받아와
			m_CompleteList.AddTail(card);					//완성리스트에 삽입하고
		}

		if(m_ChoiceList1)									//리스트1이 클릭된 상태면
		{
			m_List1.RemoveHead();							//리스트1의 카드를 제거하고
			m_ChoiceList1=false;							//클릭상태 해제
		}
		if(m_ChoiceList2)									//리스트2이 클릭된 상태면
		{
			m_List2.RemoveTail();							//리스트2의 카드를 제거하고
			m_ChoiceList2=false;							//클릭상태 해제
		}
		m_PyrmidStorage.RemoveChoiceCard(m_TempList);		//피라미드스토리지에 있는RemoveChoiceCard호출 (카드 삭제) 

		m_TempList.RemoveAll();								//임시리스트를 비움
	}
	
	//게임 클리어되는 최초 클릭시에만 실행
	if((m_CompleteList.GetSize()==52) && (m_IsDraw == false))						//완성리스트에 카드가 52개 다 모이면
	{
		//게임 클리어
		MessageBox(NULL,_T("축하합니다."),_T("축하합니다."),MB_OK);	//축하 메세지 출력
		PlaySound(_T("clap.wav"), AfxGetInstanceHandle(), SND_ASYNC);
	}
	//게임이 클리어되고 애니메이션 출력도 완료된 경우
	else if((m_CompleteList.GetSize()==52) && (m_IsDraw == true))
	{
		//새게임 실행
		NewGame();
	}
}
void CPyramidTest::MouseMove(CPoint point)
{
}

//Draw함수
void CPyramidTest::Draw(CDC* pDC)
{
	// 더블버퍼링을 위해 사용할 DC와 BITBMP생성
	CDC memDC;
	CBitmap* pOldBitmap;
	CBitmap buffer;

	// 메모리DC와 BITBMP와 현재 DC 설정 일치시킴
	memDC.CreateCompatibleDC(pDC);
	buffer.CreateCompatibleBitmap(pDC, 890, 550);
	pOldBitmap = (CBitmap*)memDC.SelectObject(&buffer);
	//pDC->PatBlt(0, 0, 890, 550, BLACKNESS);

	// 게임이 클리어된 경우
	if(m_CompleteList.GetSize()==52)
	{
		// 아직 애니메이션이 출력되지 않았던 경우
		if(m_IsDraw == false)
		{
			// 애니메이션을 출력하고
			Animation(pDC);
		}
	}
	// 클리어된 것이 아닌 경우
	else
	{
		// 카드들을 메모리DC에 그림
		DrawDoubleBuffering(&memDC);
		// 메모리DC에 그린 내용들을 DC로 복사
		pDC->BitBlt(0, 0, 890, 550, &memDC, 0, 0, SRCCOPY);
	}

	// 사용한 DC, BITBMP삭제
	memDC.SelectObject(pOldBitmap);
	memDC.DeleteDC();
}

//리스트1이 선택되었나 체크하는 함수
bool CPyramidTest::IsClickList1(CPoint point)
{
	CRgn rgn;
	rgn.CreateRectRgn(10,10,81,106);

	return rgn.PtInRegion(point);
}
//리스트2가 선택되었나 체크하는 함수
bool CPyramidTest::IsClickList2(CPoint point)
{
	CRgn rgn;
	rgn.CreateRectRgn(10,120,81,216);

	return rgn.PtInRegion(point);
}


void CPyramidTest::DrawDoubleBuffering(CDC *pDC)
{
	POSITION pos1 = m_List1.GetHeadPosition();					//리스트1의 위치를 저장할 pos1
	POSITION pos2 = m_List2.GetTailPosition();					//리스트2의 위치를 저장할 pos2
	POSITION Completepos = m_CompleteList.GetTailPosition();	//완성리스트의 위치를 저장할 Completepos
	CCard card;													//카드값을 저장할 card
	CBitmap bitmap1;											//리스트1의 비트맵을 저장할 변수
	CBitmap bitmap2;											//리스트2의 비트맵을 저장할 변수
	CBitmap Completebitmap;										//완성리스트의 비트맵을 저장할 변수
	CBitmap Backbitmap;											//배경 비트맵을 저장할 변수

	// 배경 출력. 이미지 구하면 바꾸기
	CDC dcmem;
	Backbitmap.LoadBitmapW(m_background);
	dcmem.CreateCompatibleDC(pDC);
	dcmem.SelectObject(&Backbitmap);
	pDC->BitBlt(0, 0, 890, 550, &dcmem, 0, 0, SRCCOPY);
	//리스트1의 출력 처리
	if(pos1)									//리스트1에 카드값이 있다면								
	{
		//비트맵 출력
		card = m_List1.GetNext(pos1);
		bitmap1.LoadBitmapW(card.m_CardNum);
		BITMAP bmpinfo1;
		bitmap1.GetBitmap(&bmpinfo1);

		CDC dcmem1;
		dcmem1.CreateCompatibleDC(pDC);
		dcmem1.SelectObject(&bitmap1);

		pDC->BitBlt(10,10,bmpinfo1.bmWidth,bmpinfo1.bmHeight,&dcmem1,0,0,SRCCOPY);		//10,10,위치에 출력
		//리스트1이 선택된 상태일경우
		if(m_ChoiceList1)											
		{
			pDC->BitBlt(10,10,bmpinfo1.bmWidth,bmpinfo1.bmHeight,&dcmem1,0,0,DSTINVERT);	//이미지를 반전시켜서 출력
		}
	}
	//리스트2의 출력 처리
	if(pos2)											//리스트2에 카드값이 있다면	
	{
		//비트맵 출력
		card = m_List2.GetPrev(pos2);
		bitmap2.LoadBitmapW(card.m_CardNum);
		BITMAP bmpinfo2;
		bitmap2.GetBitmap(&bmpinfo2);

		CDC dcmem2;
		dcmem2.CreateCompatibleDC(pDC);
		dcmem2.SelectObject(&bitmap2);

		pDC->BitBlt(10,120,bmpinfo2.bmWidth,bmpinfo2.bmHeight,&dcmem2,0,0,SRCCOPY);		//10,120,위치에 출력
		//리스트1이 선택된 상태일경우
		if(m_ChoiceList2)
		{
			pDC->BitBlt(10,120,bmpinfo2.bmWidth,bmpinfo2.bmHeight,&dcmem2,0,0,DSTINVERT);	//이미지를 반전시켜서 출력
		}

	}
	//완성 리스트출력
	if(Completepos)			//완성리스트에 카드값이 있다면
	{
		//비트맵 출력
		card = m_CompleteList.GetPrev(Completepos);
		Completebitmap.LoadBitmapW(card.m_CardNum);
		BITMAP Completebmpinfo;
		Completebitmap.GetBitmap(&Completebmpinfo);

		CDC Completedcmem;
		Completedcmem.CreateCompatibleDC(pDC);
		Completedcmem.SelectObject(&Completebitmap);
		
		pDC->BitBlt(800,10,Completebmpinfo.bmWidth,Completebmpinfo.bmHeight,&Completedcmem,0,0,SRCCOPY);		//800,10에 출력

	}

	//피라미드스토리지 출력(피라미드스토리지에게 pDC를 넘겨서 알아서 처리하게함)
	//m_TempList는 선택 된 상태를 확인해 선택되있는 경우 반전 출력을 하기 위해 파라미터로 넘겨줌
	m_PyrmidStorage.Draw(pDC,m_TempList);

}

//피라미드 게임의 데이터를 저장하고 불러오는 함수
void CPyramidTest::Serialize(CArchive& ar)  
{
	int i,Lsize,Lsize2,Csize;
	CCard card;
	if (ar.IsStoring())//저장 코드
	{
		//배경 비트맵 아이디, 사용자 점수, 카드 셔플 가능 횟수, 카드패 회전수,List1, List2, CompleteList의 사이즈 저장
		ar<<m_background<<m_score<<m_shuffle<<m_ReDeal<<m_List1.GetSize()<<m_List2.GetSize()<<m_CompleteList.GetSize();
		POSITION pos=m_List1.GetHeadPosition();
		while(pos)
			m_List1.GetNext(pos).Serialize(ar);//m_List1의 데이터를 저장
		pos=m_List2.GetHeadPosition();
		while(pos)
			m_List2.GetNext(pos).Serialize(ar);//m_List2의 데이터를 저장
		m_PyrmidStorage.Serialize(ar);//피라미드 스토리지의 카드 데이터를 저장
		pos=m_CompleteList.GetHeadPosition();
		while(pos)
			m_CompleteList.GetNext(pos).Serialize(ar);//m_CompleteList의 데이터를 저장
	}
	else//로딩 코드
	{
		m_List1.RemoveAll();			//리스트1을 비움
		m_List2.RemoveAll();			//리스트2를 비움
		m_CompleteList.RemoveAll();		//완성리스트를 비움
		m_PyrmidStorage.RemoveAll();	//피라미드스토리지를 비움
		m_TempList.RemoveAll();			//임시리스트를 비움
		m_ChoiceList1=false;			//클릭됬는지 확인하는 bool변수 이므로 생성자에서 false로 초기화
		m_ChoiceList2=false;			//클릭됬는지 확인하는 bool변수 이므로 생성자에서 false로 초기화
		//배경 비트맵 아이디, 사용자 점수, 카드 셔플 가능 횟수, 카드패 회전수, 현재 카드패 선택 위치, List1의 사이즈 로드
		ar>>m_background>>m_score>>m_shuffle>>m_ReDeal>>Lsize>>Lsize2>>Csize;
		for(i=0;i<Lsize;i++)
		{
			card.Serialize(ar);        //List1의 데이터를 로드
			m_List1.AddTail(card);     
		}
		for(i=0;i<Lsize2;i++)
		{
			card.Serialize(ar);        //List2의 데이터를 로드
			m_List2.AddTail(card);
		}
		for(i=0;i<28;i++)
		{
			card.Serialize(ar);        //m_PyrmidStorage의 데이터를 로드
			m_PyrmidStorage.Push(card);
		}
		for(i=0;i<Csize;i++)
		{
			card.Serialize(ar);       //m_CompleteList의 데이터를 로드
			m_CompleteList.AddTail(card);
		}
	}
}

void CPyramidTest::CardShuffle(CDC *pDC, CCard card)
{
	CBitmap bitmap1;											//리스트1의 비트맵을 저장할 변수
	// 배경 출력. 이미지 구하면 바꾸기
	CDC dcmem;
	bitmap1.LoadBitmapW(card.m_CardNum);
	BITMAP bmpinfo1;
	bitmap1.GetBitmap(&bmpinfo1);

	CDC dcmem1;
	dcmem1.CreateCompatibleDC(pDC);
	dcmem1.SelectObject(&bitmap1);
//	pDC->BitBlt(10,10,bmpinfo1.bmWidth-1,bmpinfo1.bmHeight-1,&dcmem1,0,0,SRCCOPY);		//10,10,위치에 출력
	//pDC->StretchBlt(10,10,10,10,&dcmem1,0,0,bmpinfo1.bmWidth,bmpinfo1.bmHeight,SRCCOPY);
	pDC->StretchBlt(10+bmpinfo1.bmWidth-1,10+bmpinfo1.bmHeight-1,-bmpinfo1.bmWidth,-bmpinfo1.bmHeight,&dcmem,bmpinfo1.bmWidth,bmpinfo1.bmHeight,0,0,SRCCOPY);
}

void CPyramidTest::Animation(CDC* pDC)
{
	int x, y;									// 카드가 뿌려질 좌표 
	POSITION pos = m_AniList.GetTailPosition();	// 애니메이션에 사용될 카드 정보가 저장된 리스트 포지션
	CCard card;									// 리스트에서 카드 card
	CBitmap bitmap[520];						// 비트맵 저장
	BITMAP bitinfo[520];						// 비트맵 정보 저장
	CDC dcmem;

	dcmem.CreateCompatibleDC(pDC);

	for(int i=0; i<520; i++)
	{
		Sleep(5);
		x = rand()%89;							// 카드 이미지가 출력될 좌표X
		y = rand()%55;							// 카드 이미지가 출력될 좌표Y
		card = m_AniList.GetPrev(pos);
		bitmap[i].LoadBitmapW(card.m_CardNum);
		bitmap[i].GetBitmap(&bitinfo[i]);

		dcmem.SelectObject(bitmap[i]);
		pDC->BitBlt(x*10,y*10,bitinfo[i].bmWidth,bitinfo[i].bmHeight,&dcmem,0,0,SRCCOPY);		//생성된 랜덤한 좌표에 출력
	}
	// 애니메이션 출력이 완료되었음을 알림
	m_IsDraw = true;
}

//게임 옵션 설정 함수
void CPyramidTest::SetOption() 
{
	CDlgSetOption dlg;
	dlg.m_shuffle=m_shuffle;
	dlg.m_back=m_background;
	if(dlg.DoModal()==IDOK)
	{
		m_shuffle=dlg.m_shuffle-1;//카드 셔플 횟수 변경
		m_background=dlg.m_back;//배경 변경
	}
}
