#include "StdAfx.h"
#include "PyramidTest.h"
#include "resource.h"


CPyramidTest::CPyramidTest(void)
{
	m_shuffle=2;				   //ī�� ���� ���� Ƚ��  
	m_ChoiceList1=false;		   //Ŭ����±� Ȯ���ϴ� bool���� �̹Ƿ� �����ڿ��� false�� �ʱ�ȭ
	m_ChoiceList2=false;		   //Ŭ����±� Ȯ���ϴ� bool���� �̹Ƿ� �����ڿ��� false�� �ʱ�ȭ
	m_IsDraw=false;				   //�ִϸ��̼��� �������� Ȯ���ϴ� bool�����̹Ƿ� �����ڿ��� false�� �ʱ�ȭ
	m_ReDeal=0;					   //ī���� ȸ�� Ƚ���̹Ƿ� �����ڿ��� 0���� �ʱ�ȭ
	m_score=0;					   //���� ����ڰ� ���� �����̹Ƿ� 0���� �ʱ�ȭ
	m_background=IDB_BITMAPBack;   //��� ��Ʈ�� ���̵�
}


CPyramidTest::~CPyramidTest(void)
{
}

//������ �Լ�
void CPyramidTest::NewGame(void)
{
	//��� ����Ʈ �� ������ ���� 0���� �ʱ�ȭ
	PlaySound(_T("Shuffle.wav"), AfxGetInstanceHandle(), SND_ASYNC);
	m_List1.RemoveAll();			//����Ʈ1�� ���
	m_List2.RemoveAll();			//����Ʈ2�� ���
	m_CompleteList.RemoveAll();		//�ϼ�����Ʈ�� ���
	m_PyrmidStorage.RemoveAll();	//�Ƕ�̵彺�丮���� ���
	m_TempList.RemoveAll();			//�ӽø���Ʈ�� ���
	m_AniList.RemoveAll();			//�ִϸ��̼� ����Ʈ�� ���
	m_ReDeal=0;						//īƮ�� ȸ������ 0���� �ʱ�ȭ
	m_score=0;                      //����� ������ 0���� �ʱ�ȭ
	m_ChoiceList1=false;			//Ŭ����±� Ȯ���ϴ� bool���� �̹Ƿ� �����ڿ��� false�� �ʱ�ȭ
	m_ChoiceList2=false;			//Ŭ����±� Ȯ���ϴ� bool���� �̹Ƿ� �����ڿ��� false�� �ʱ�ȭ
	m_IsDraw=false;				   //�ִϸ��̼��� �������� Ȯ���ϴ� bool�����̹Ƿ� �����ڿ��� false�� �ʱ�ȭ

	srand((unsigned int)time(NULL));//������ ������ ����
	int randnum;					//������ �޾ƿ� ���� ����
	int i,j;						//�ݺ����� ���� i,j���� ����
	POSITION pos;					//����Ʈ�� POSITION���� �����ص� pos���� ����
	CCard card;						//CCard���� �޾ƿ� card���� ����

	//����Ʈ2�� ī�带 ���ʴ�� �����ؼ� ����
	for(i=0;i<52;i++)
	{
		m_List2.AddTail(CCard(i+310,i%13+1));	//ī�� ������ȣ(310~361), ī���� ��(1~13)
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<52;j++)
		{
			m_AniList.AddTail(CCard(j+310,j%13+1));	//ī�� ������ȣ(310~361), ī���� ��(1~13)
		}
	}
	int num;
	//������ Ŭ�����ϱ� ������ ī�带 ��ġ
	for(i=0;i<52;i++)						//52�� �ݺ�
	{
		if((i+1)%13!=0 && (i%13)<=5)//K�� ������ ���� 13�� �Ǵ� �ֳ��� ������� ���� ex) 1-12, 2-11
		{
			num=i%13+1;                     //ī���� ���ڸ� ����
			card=CCard(310+i,num);          //���� 13�� �Ǵ� ���鳢�� ������ ��ġ
			m_List1.AddTail(card);          //����Ʈ1�� card���� ����
			pos = m_List2.Find(card);	    //card������ ���� pos�� ����
			m_List2.RemoveAt(pos);		    //pos�� �̿��� ����Ʈ2�� card���� �����ϰ�
			if(i<12)
				card=CCard(310+11-i,13-num);    //���� 13�� �Ǵ� ���鳢�� ������ ��ġ
			else
				card=CCard(310+(11-i%13)+i/13*13,13-num);
			m_List1.AddTail(card);          //����Ʈ1�� card���� ����
			pos = m_List2.Find(card);	    //card������ ���� pos�� ����
			m_List2.RemoveAt(pos);		    //pos�� �̿��� ����Ʈ2�� card���� �����ϰ�
		}
		else if((i+1)%13==0)//K
		{
			card=CCard(310+i,13);           //ī���� ���ڸ� ����
			pos = m_List2.Find(card);	    //card������ ���� pos�� ����
			m_List2.RemoveAt(pos);		    //pos�� �̿��� ����Ʈ2�� card���� �����ϰ�
			m_List2.AddTail(card);          //����Ʈ�� �������� ī�带 �߰�
		}
	}
	//K�� ����
	m_List1.AddTail(CCard(335,13));
	m_List1.AddTail(CCard(348,13));
	m_List1.AddTail(CCard(361,13));
	m_List2.RemoveAll();                    //����Ʈ �ʱ�ȭ
	//�Ƕ�̵� ���丮���� 28���� ī�尪�� ����
	for(i=0;i<28;i++)							//28�� �ݺ�
	{
		if(i==0)                                    //�Ƕ�̵� ����� ��
			m_PyrmidStorage.Push(CCard(322,13));    //K ����
		else
		{
			m_PyrmidStorage.Push(m_List1.GetHead());//����Ʈ1�� Head��ġ�� card�� �Ƕ�̵彺�丮���� �ְ�
			m_List1.RemoveHead();					//����Ʈ1�� Head��ġ�� card�� ����
		}
	}
}

//���콺 Ŭ���� ó���� �Լ�
void CPyramidTest::MouseClick(CPoint point)
{
	POSITION pos;			//��ġ�� ������ POSITION����
	CCard card;				//CCard���� ������ card����

	//����Ʈ1�� Ŭ�� ������ ó��
	if(IsClickList1(point))
	{
		pos = m_List1.GetHeadPosition();				//Head�� pos�� �޾ƿͼ�
		if(pos)											//pos�� �ִٸ�(�� ����Ʈ�� card�� �Ѱ��� �ִٸ�)
		{
			card = m_List1.GetNext(pos);				//Head��ġ�� card���� �޾ƿ�
			//����Ʈ1�� �̹� Ŭ���� �����϶� Ŭ�� ����
			if(m_ChoiceList1)										//����Ʈ1�� Ŭ���� ���¸�	
			{
				m_TempList.RemoveAt(m_TempList.Find(card));			//�ӽø���Ʈ���� ����Ʈ1�� card���� ã�Ƽ� �����ϰ�
				m_ChoiceList1=false;								//����Ʈ1 ���� ���¸� false�� ����
			}
			//�ӽø���Ʈ�� ī�尡 1�� �϶� ����Ʈ1�� ���� ��
			else if(m_TempList.GetSize()>0&&m_TempList.GetSize()<2)	//�ӽø���Ʈ�� ī�尡 1�� ������
			{
				m_TempList.AddTail(card);							//����Ʈ1�� ī�尪�� �ӽø���Ʈ�� �߰��ϰ�
				m_ChoiceList1=true;									//����Ʈ1�� ���õ� ���� true�� ����
			}
			//���� ��찡 ��� �ƴ϶�� ī�带 ���� �ѱ�
			else
			{
				PlaySound(_T("Turn.wav"), AfxGetInstanceHandle(), SND_ASYNC);
				m_List2.AddTail(card);								//����Ʈ1�� ī�带 ����Ʈ2�� Tail�� �߰�
				m_List1.RemoveHead();								//����Ʈ1�� ī�带 ����
			}
		}
		//����Ʈ1�� ī�尡 �ϳ��� ������� ó��
		else
		{
			if(m_ReDeal<m_shuffle)						    		//�ݺ�Ƚ���� ���� 2ȸ�� �ȵɰ��
			{
				pos = m_List2.GetHeadPosition();					//����Ʈ2�� pos���� �޾ƿ�
				while(pos)
				{
					card = m_List2.GetNext(pos);					//����Ʈ2�� ��� card����
					m_List1.AddTail(card);							//����Ʈ1�� �����ϰ�
				}
				m_List2.RemoveAll();								//����Ʈ2�� ����
				m_ReDeal++;											//ī���� �ݺ�Ƚ�� ����
			}
		}
	}
	//����Ʈ2�� Ŭ������ ��� ó��
	if(IsClickList2(point))
	{
		pos = m_List2.GetTailPosition();					//Head�� pos�� �޾ƿͼ�
		if(pos)												//pos�� �ִٸ�(�� ����Ʈ�� card�� �Ѱ��� �ִٸ�)
		{
			card = m_List2.GetPrev(pos);					//ī�尪�� ���ʺ��� �޾ƿ�
			//����Ʈ1�� �̹� Ŭ���� �����϶� Ŭ�� ����
			if(m_ChoiceList2)
			{
				m_TempList.RemoveAt(m_TempList.Find(card));	//�ӽø���Ʈ���� ����Ʈ2�� card���� ã�Ƽ� �����ϰ�
				m_ChoiceList2=false;						//����Ʈ2 ���� ���¸� false�� ����
			}
			//ī�� ���õȰ� 0~1�� �϶� ó��
			else if(m_TempList.GetSize()<2)					//ī�尡 0������ 1�� ���õ� �����϶�
			{
				m_TempList.AddTail(card);					//�ӽø���Ʈ�� ����Ʈ2�� card���� �߰��ϰ�
				m_ChoiceList2=true;							//����Ʈ2�� ���� ������ true�� ����
			}
		}	
	}
	//�Ƕ�̵� ���丮�� Ŭ�� ó��
	if(m_TempList.GetSize()<3)								//ī�尡 ���õ� ������ 0~2���϶�
	{
		m_PyrmidStorage.MouseClick(point,m_TempList);		//�Ƕ�̵彺�丮���� ���콺Ŭ�� �Լ� ȣ��(�Ķ���ͷ� ��ǥ����,�ӽø���Ʈ�� &�� �Ѱ���)
	}

	//���� Ŭ���� ī����� ���� ���ؼ� 13���� üũ�ϴ� ó��
	int num=0;												//���� ���ϹǷ� 0���� �ʱ�ȭ�ϰ�
	pos = m_TempList.GetHeadPosition();						//�ӽø���Ʈ�� pos���� �޾ƿ�
	while(pos)												//�ӽø���Ʈ�� ī�尡 �ִٸ�
	{
		card = m_TempList.GetNext(pos);						//ī�尪�� �޾ƿ���
		num+=card.m_Num;									//ī�尪�� ī����� num�� ����
	}
	//���� 13�� ��� ó��
	if(num==13)												//���� 13�̸�
	{
		pos = m_TempList.GetHeadPosition();					//�ӽø���Ʈ�� pos���� �޾ƿ�
		while(pos)											//�ӽø���Ʈ ���� ����
		{
			card = m_TempList.GetNext(pos);					//card������ �޾ƿ�
			m_CompleteList.AddTail(card);					//�ϼ�����Ʈ�� �����ϰ�
		}

		if(m_ChoiceList1)									//����Ʈ1�� Ŭ���� ���¸�
		{
			m_List1.RemoveHead();							//����Ʈ1�� ī�带 �����ϰ�
			m_ChoiceList1=false;							//Ŭ������ ����
		}
		if(m_ChoiceList2)									//����Ʈ2�� Ŭ���� ���¸�
		{
			m_List2.RemoveTail();							//����Ʈ2�� ī�带 �����ϰ�
			m_ChoiceList2=false;							//Ŭ������ ����
		}
		m_PyrmidStorage.RemoveChoiceCard(m_TempList);		//�Ƕ�̵彺�丮���� �ִ�RemoveChoiceCardȣ�� (ī�� ����) 

		m_TempList.RemoveAll();								//�ӽø���Ʈ�� ���
	}
	
	//���� Ŭ����Ǵ� ���� Ŭ���ÿ��� ����
	if((m_CompleteList.GetSize()==52) && (m_IsDraw == false))						//�ϼ�����Ʈ�� ī�尡 52�� �� ���̸�
	{
		//���� Ŭ����
		MessageBox(NULL,_T("�����մϴ�."),_T("�����մϴ�."),MB_OK);	//���� �޼��� ���
		PlaySound(_T("clap.wav"), AfxGetInstanceHandle(), SND_ASYNC);
	}
	//������ Ŭ����ǰ� �ִϸ��̼� ��µ� �Ϸ�� ���
	else if((m_CompleteList.GetSize()==52) && (m_IsDraw == true))
	{
		//������ ����
		NewGame();
	}
}
void CPyramidTest::MouseMove(CPoint point)
{
}

//Draw�Լ�
void CPyramidTest::Draw(CDC* pDC)
{
	// ������۸��� ���� ����� DC�� BITBMP����
	CDC memDC;
	CBitmap* pOldBitmap;
	CBitmap buffer;

	// �޸�DC�� BITBMP�� ���� DC ���� ��ġ��Ŵ
	memDC.CreateCompatibleDC(pDC);
	buffer.CreateCompatibleBitmap(pDC, 890, 550);
	pOldBitmap = (CBitmap*)memDC.SelectObject(&buffer);
	//pDC->PatBlt(0, 0, 890, 550, BLACKNESS);

	// ������ Ŭ����� ���
	if(m_CompleteList.GetSize()==52)
	{
		// ���� �ִϸ��̼��� ��µ��� �ʾҴ� ���
		if(m_IsDraw == false)
		{
			// �ִϸ��̼��� ����ϰ�
			Animation(pDC);
		}
	}
	// Ŭ����� ���� �ƴ� ���
	else
	{
		// ī����� �޸�DC�� �׸�
		DrawDoubleBuffering(&memDC);
		// �޸�DC�� �׸� ������� DC�� ����
		pDC->BitBlt(0, 0, 890, 550, &memDC, 0, 0, SRCCOPY);
	}

	// ����� DC, BITBMP����
	memDC.SelectObject(pOldBitmap);
	memDC.DeleteDC();
}

//����Ʈ1�� ���õǾ��� üũ�ϴ� �Լ�
bool CPyramidTest::IsClickList1(CPoint point)
{
	CRgn rgn;
	rgn.CreateRectRgn(10,10,81,106);

	return rgn.PtInRegion(point);
}
//����Ʈ2�� ���õǾ��� üũ�ϴ� �Լ�
bool CPyramidTest::IsClickList2(CPoint point)
{
	CRgn rgn;
	rgn.CreateRectRgn(10,120,81,216);

	return rgn.PtInRegion(point);
}


void CPyramidTest::DrawDoubleBuffering(CDC *pDC)
{
	POSITION pos1 = m_List1.GetHeadPosition();					//����Ʈ1�� ��ġ�� ������ pos1
	POSITION pos2 = m_List2.GetTailPosition();					//����Ʈ2�� ��ġ�� ������ pos2
	POSITION Completepos = m_CompleteList.GetTailPosition();	//�ϼ�����Ʈ�� ��ġ�� ������ Completepos
	CCard card;													//ī�尪�� ������ card
	CBitmap bitmap1;											//����Ʈ1�� ��Ʈ���� ������ ����
	CBitmap bitmap2;											//����Ʈ2�� ��Ʈ���� ������ ����
	CBitmap Completebitmap;										//�ϼ�����Ʈ�� ��Ʈ���� ������ ����
	CBitmap Backbitmap;											//��� ��Ʈ���� ������ ����

	// ��� ���. �̹��� ���ϸ� �ٲٱ�
	CDC dcmem;
	Backbitmap.LoadBitmapW(m_background);
	dcmem.CreateCompatibleDC(pDC);
	dcmem.SelectObject(&Backbitmap);
	pDC->BitBlt(0, 0, 890, 550, &dcmem, 0, 0, SRCCOPY);
	//����Ʈ1�� ��� ó��
	if(pos1)									//����Ʈ1�� ī�尪�� �ִٸ�								
	{
		//��Ʈ�� ���
		card = m_List1.GetNext(pos1);
		bitmap1.LoadBitmapW(card.m_CardNum);
		BITMAP bmpinfo1;
		bitmap1.GetBitmap(&bmpinfo1);

		CDC dcmem1;
		dcmem1.CreateCompatibleDC(pDC);
		dcmem1.SelectObject(&bitmap1);

		pDC->BitBlt(10,10,bmpinfo1.bmWidth,bmpinfo1.bmHeight,&dcmem1,0,0,SRCCOPY);		//10,10,��ġ�� ���
		//����Ʈ1�� ���õ� �����ϰ��
		if(m_ChoiceList1)											
		{
			pDC->BitBlt(10,10,bmpinfo1.bmWidth,bmpinfo1.bmHeight,&dcmem1,0,0,DSTINVERT);	//�̹����� �������Ѽ� ���
		}
	}
	//����Ʈ2�� ��� ó��
	if(pos2)											//����Ʈ2�� ī�尪�� �ִٸ�	
	{
		//��Ʈ�� ���
		card = m_List2.GetPrev(pos2);
		bitmap2.LoadBitmapW(card.m_CardNum);
		BITMAP bmpinfo2;
		bitmap2.GetBitmap(&bmpinfo2);

		CDC dcmem2;
		dcmem2.CreateCompatibleDC(pDC);
		dcmem2.SelectObject(&bitmap2);

		pDC->BitBlt(10,120,bmpinfo2.bmWidth,bmpinfo2.bmHeight,&dcmem2,0,0,SRCCOPY);		//10,120,��ġ�� ���
		//����Ʈ1�� ���õ� �����ϰ��
		if(m_ChoiceList2)
		{
			pDC->BitBlt(10,120,bmpinfo2.bmWidth,bmpinfo2.bmHeight,&dcmem2,0,0,DSTINVERT);	//�̹����� �������Ѽ� ���
		}

	}
	//�ϼ� ����Ʈ���
	if(Completepos)			//�ϼ�����Ʈ�� ī�尪�� �ִٸ�
	{
		//��Ʈ�� ���
		card = m_CompleteList.GetPrev(Completepos);
		Completebitmap.LoadBitmapW(card.m_CardNum);
		BITMAP Completebmpinfo;
		Completebitmap.GetBitmap(&Completebmpinfo);

		CDC Completedcmem;
		Completedcmem.CreateCompatibleDC(pDC);
		Completedcmem.SelectObject(&Completebitmap);
		
		pDC->BitBlt(800,10,Completebmpinfo.bmWidth,Completebmpinfo.bmHeight,&Completedcmem,0,0,SRCCOPY);		//800,10�� ���

	}

	//�Ƕ�̵彺�丮�� ���(�Ƕ�̵彺�丮������ pDC�� �Ѱܼ� �˾Ƽ� ó���ϰ���)
	//m_TempList�� ���� �� ���¸� Ȯ���� ���õ��ִ� ��� ���� ����� �ϱ� ���� �Ķ���ͷ� �Ѱ���
	m_PyrmidStorage.Draw(pDC,m_TempList);

}

//�Ƕ�̵� ������ �����͸� �����ϰ� �ҷ����� �Լ�
void CPyramidTest::Serialize(CArchive& ar)  
{
	int i,Lsize,Lsize2,Csize;
	CCard card;
	if (ar.IsStoring())//���� �ڵ�
	{
		//��� ��Ʈ�� ���̵�, ����� ����, ī�� ���� ���� Ƚ��, ī���� ȸ����,List1, List2, CompleteList�� ������ ����
		ar<<m_background<<m_score<<m_shuffle<<m_ReDeal<<m_List1.GetSize()<<m_List2.GetSize()<<m_CompleteList.GetSize();
		POSITION pos=m_List1.GetHeadPosition();
		while(pos)
			m_List1.GetNext(pos).Serialize(ar);//m_List1�� �����͸� ����
		pos=m_List2.GetHeadPosition();
		while(pos)
			m_List2.GetNext(pos).Serialize(ar);//m_List2�� �����͸� ����
		m_PyrmidStorage.Serialize(ar);//�Ƕ�̵� ���丮���� ī�� �����͸� ����
		pos=m_CompleteList.GetHeadPosition();
		while(pos)
			m_CompleteList.GetNext(pos).Serialize(ar);//m_CompleteList�� �����͸� ����
	}
	else//�ε� �ڵ�
	{
		m_List1.RemoveAll();			//����Ʈ1�� ���
		m_List2.RemoveAll();			//����Ʈ2�� ���
		m_CompleteList.RemoveAll();		//�ϼ�����Ʈ�� ���
		m_PyrmidStorage.RemoveAll();	//�Ƕ�̵彺�丮���� ���
		m_TempList.RemoveAll();			//�ӽø���Ʈ�� ���
		m_ChoiceList1=false;			//Ŭ������� Ȯ���ϴ� bool���� �̹Ƿ� �����ڿ��� false�� �ʱ�ȭ
		m_ChoiceList2=false;			//Ŭ������� Ȯ���ϴ� bool���� �̹Ƿ� �����ڿ��� false�� �ʱ�ȭ
		//��� ��Ʈ�� ���̵�, ����� ����, ī�� ���� ���� Ƚ��, ī���� ȸ����, ���� ī���� ���� ��ġ, List1�� ������ �ε�
		ar>>m_background>>m_score>>m_shuffle>>m_ReDeal>>Lsize>>Lsize2>>Csize;
		for(i=0;i<Lsize;i++)
		{
			card.Serialize(ar);        //List1�� �����͸� �ε�
			m_List1.AddTail(card);     
		}
		for(i=0;i<Lsize2;i++)
		{
			card.Serialize(ar);        //List2�� �����͸� �ε�
			m_List2.AddTail(card);
		}
		for(i=0;i<28;i++)
		{
			card.Serialize(ar);        //m_PyrmidStorage�� �����͸� �ε�
			m_PyrmidStorage.Push(card);
		}
		for(i=0;i<Csize;i++)
		{
			card.Serialize(ar);       //m_CompleteList�� �����͸� �ε�
			m_CompleteList.AddTail(card);
		}
	}
}

void CPyramidTest::CardShuffle(CDC *pDC, CCard card)
{
	CBitmap bitmap1;											//����Ʈ1�� ��Ʈ���� ������ ����
	// ��� ���. �̹��� ���ϸ� �ٲٱ�
	CDC dcmem;
	bitmap1.LoadBitmapW(card.m_CardNum);
	BITMAP bmpinfo1;
	bitmap1.GetBitmap(&bmpinfo1);

	CDC dcmem1;
	dcmem1.CreateCompatibleDC(pDC);
	dcmem1.SelectObject(&bitmap1);
//	pDC->BitBlt(10,10,bmpinfo1.bmWidth-1,bmpinfo1.bmHeight-1,&dcmem1,0,0,SRCCOPY);		//10,10,��ġ�� ���
	//pDC->StretchBlt(10,10,10,10,&dcmem1,0,0,bmpinfo1.bmWidth,bmpinfo1.bmHeight,SRCCOPY);
	pDC->StretchBlt(10+bmpinfo1.bmWidth-1,10+bmpinfo1.bmHeight-1,-bmpinfo1.bmWidth,-bmpinfo1.bmHeight,&dcmem,bmpinfo1.bmWidth,bmpinfo1.bmHeight,0,0,SRCCOPY);
}

void CPyramidTest::Animation(CDC* pDC)
{
	int x, y;									// ī�尡 �ѷ��� ��ǥ 
	POSITION pos = m_AniList.GetTailPosition();	// �ִϸ��̼ǿ� ���� ī�� ������ ����� ����Ʈ ������
	CCard card;									// ����Ʈ���� ī�� card
	CBitmap bitmap[520];						// ��Ʈ�� ����
	BITMAP bitinfo[520];						// ��Ʈ�� ���� ����
	CDC dcmem;

	dcmem.CreateCompatibleDC(pDC);

	for(int i=0; i<520; i++)
	{
		Sleep(5);
		x = rand()%89;							// ī�� �̹����� ��µ� ��ǥX
		y = rand()%55;							// ī�� �̹����� ��µ� ��ǥY
		card = m_AniList.GetPrev(pos);
		bitmap[i].LoadBitmapW(card.m_CardNum);
		bitmap[i].GetBitmap(&bitinfo[i]);

		dcmem.SelectObject(bitmap[i]);
		pDC->BitBlt(x*10,y*10,bitinfo[i].bmWidth,bitinfo[i].bmHeight,&dcmem,0,0,SRCCOPY);		//������ ������ ��ǥ�� ���
	}
	// �ִϸ��̼� ����� �Ϸ�Ǿ����� �˸�
	m_IsDraw = true;
}

//���� �ɼ� ���� �Լ�
void CPyramidTest::SetOption() 
{
	CDlgSetOption dlg;
	dlg.m_shuffle=m_shuffle;
	dlg.m_back=m_background;
	if(dlg.DoModal()==IDOK)
	{
		m_shuffle=dlg.m_shuffle-1;//ī�� ���� Ƚ�� ����
		m_background=dlg.m_back;//��� ����
	}
}
