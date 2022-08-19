#include "StdAfx.h"
#include "PyramidStorage.h"


CPyramidStorage::CPyramidStorage(void)
{
	//�Ƕ�̵��� 2���� �迭�� �������� ����
	int i,j;
	m_pointer = new CCard*[7];				//CCard*[7]�� ���� ��
	
	for(i=0;i<7;i++)
	{
		m_pointer[i] = new CCard[i+1];		//�� CCard*[i]���� i+1���� �迭�� ���� (���� �ϳ������Ҷ����� �迭ũ�⵵ �Ѱ��� �����ؼ� �迭����) 
	}
	//���θ��� �Ǹ������ �迭�� CCard()�� �ʱ�ȭ
	for(i=0;i<7;i++)
	{
		for(j=0;j<i+1;j++)
		{
			m_pointer[i][j] = CCard();
		}
	}

	row=0,col=0;				//row��col�� 0���� �ʱ�ȭ
}

//�Ҹ���(�����Ҵ� ��ȯó��)
CPyramidStorage::~CPyramidStorage(void)
{
	int i;
	for(i=0;i<7;i++)
	{
		delete[] m_pointer[i];	//�����Ҵ� ��ȯ
	}

	delete[] m_pointer;			//�����Ҵ� ��ȯ

}

//�Ƕ�̵彺�丮���� �����Լ�
void CPyramidStorage::Push(CCard card)
{
	m_pointer[row][col] = card;	//���� row,col��ġ�� �Ķ���ͷ� �Ѿ�� card���� ����

	if(row==col)				//row,col�� ���ٸ�(���� ���� ��ä���ٸ�)
	{
		row++;					//row++(���� �ϳ� ����)
		col=0;					//���� 0���� ����
	}
	else						//�������� �� ��á�ٸ�
	{
		col++;					//row�� �״�� �ΰ� (���� �״��) ���� �ϳ� ����
	}
}

//�Ƕ�̵� ���丮�� Draw �Լ�
void CPyramidStorage::Draw(CDC* pDC, CList<CCard,CCard&>& List)
{
	//28���� ��Ʈ�� ������ �����صΰ�
	CBitmap bitmap[28];
	BITMAP bmpinfo[28];

	int i,j,k;
	//28�� �ݺ����� ���鼭(1,2,3,4,5,6,7���� ó��)
	for(i=0,k=0;i<7;i++)
	{
		for(j=0;j<i+1;j++,k++)
		{
			if(m_pointer[i][j].m_CardNum==0)	//���� card������ȣ�� 0�̸� ī�尡 ���� ���̹Ƿ� 
			{
				continue;						//������ �۾��� �������� ���� �ݺ������� �Ѿ
			}
			//ī���ȣ�� �����Ѵٸ� ��Ʈ�� ���
			bitmap[k].LoadBitmapW(m_pointer[i][j].m_CardNum);
			bitmap[k].GetBitmap(&bmpinfo[k]);

			CDC dcmem;
			dcmem.CreateCompatibleDC(pDC);
			dcmem.SelectObject(&bitmap[k]);

			POSITION pos;
			CCard card;
			bool choice=false;				//ī�尡 ���õǾ��� üũ�� bool����
			//�ӽø���Ʈ�� ī�尡 �ִ��� Ȯ���ؼ� ������Ű�� ó��
			pos = List.GetHeadPosition();
			while(pos)
			{
				card = List.GetNext(pos);
				if(card==m_pointer[i][j])		//�ӽø���Ʈ�� ī��� ��ġ�ϴ� ī�尡 �Ƕ�̵� ���丮���� �ִٸ�
				{
					choice=true;				//choice=true
				}
			}
			//��Ʈ���� ���
			pDC->BitBlt(400-(i*40)+(j*80),10+(i*50),bmpinfo[k].bmWidth,bmpinfo[k].bmHeight,&dcmem,0,0,SRCCOPY);
			//���� ���õ� ī����
			if(choice)
			{
				//ī�带 �������Ѽ� ���
				pDC->BitBlt(400-(i*40)+(j*80),10+(i*50),bmpinfo[k].bmWidth,bmpinfo[k].bmHeight,&dcmem,0,0,DSTINVERT);
			}

		}
	}
}

//�Ƕ�̵彺�丮�� ���콺Ŭ�� �Լ�
void CPyramidStorage::MouseClick(CPoint point,CList<CCard,CCard&>& List)
{
	int i,j,k;
	CRgn rgn[28];
	POSITION pos;
	CCard card;
	
	//28�� �ݺ����� ����
	for(i=0,k=0;i<7;i++)
	{
		for(j=0;j<i+1;j++,k++)
		{
			//�ش� rgn�� ����
			rgn[k].CreateRectRgn(400-(i*40)+(j*80),10+(i*50),400-(i*40)+(j*80)+71,10+(i*50)+96);
			if(rgn[k].PtInRegion(point))			//rgn�ȿ� point�� �ִٸ�
			{
				//�ǾƷ����� ���
				if(i==6)							
				{
					//���õȰ� �ٽ� Ŭ�� ��ٸ� Ŭ�� ���� ����
					pos= List.GetHeadPosition();

					while(pos)
					{
						card = List.GetNext(pos);
						if(card==m_pointer[i][j])			//�ӽø���Ʈ�� ���� ī�尡 �մٸ�
						{
							List.RemoveAt(List.Find(card));	//�ӽø���Ʈ�� ī�带 ����
							return;
						}
					}
					//�̹�Ŭ���Ȱ� �ƴϰ� ���õ� ī���� ������ 0~1�� �ϰ��
					if(List.GetSize()<2&&m_pointer[i][j].m_CardNum!=0)
					{
						//�ӽø���Ʈ�� ���� ī�� �߰�
						List.AddTail(m_pointer[i][j]);
					}
				}
				//�׿� 0~5���� ���
				else
				{
					if(m_pointer[i+1][j].m_CardNum==0&&m_pointer[i+1][j+1].m_CardNum==0)
					{
						//���õȰ� �ٽ� Ŭ�� ��ٸ� Ŭ�� ���� ����
						pos= List.GetHeadPosition();
						
						while(pos)
						{
							card = List.GetNext(pos);
							if(card==m_pointer[i][j])				//�ӽø���Ʈ�� ���� ī�尡 �մٸ�
							{
								List.RemoveAt(List.Find(card));		//�ӽø���Ʈ�� ī�带 ����
								return;
							}
						}
						//�̹�Ŭ���Ȱ� �ƴϰ� ���õ� ī���� ������ 0~1�� �ϰ��
						if(List.GetSize()<2&&m_pointer[i][j].m_CardNum!=0)
						{
							//�ӽø���Ʈ�� ���� ī�� �߰�
							List.AddTail(m_pointer[i][j]);
						}
					}
				}
			}
		}
	}
}

//���õ� ī�带 �Ƕ�̵� ���丮������ �����ϴ� �Լ�
void CPyramidStorage::RemoveChoiceCard(CList<CCard,CCard&>& List)
{
	int i,j,k;
	POSITION pos;
	CCard card;
	//28�� �ݺ����� ����
	for(i=0,k=0;i<7;i++)
	{
		for(j=0;j<i+1;j++,k++)
		{
			pos= List.GetHeadPosition();
			while(pos)
			{
				card = List.GetNext(pos);
				if(card==m_pointer[i][j])			//�ӽø���Ʈ�� ��ġ�°� �ִٸ�
				{
					m_pointer[i][j] = CCard(0,0);	//�Ƕ�̵彺�丮���� card���� 0,0���� ����(�������� ȿ��)
				}
			}
		}
	}
}

//�Ƕ�̵� ���丮���� �ٺ��� �Լ�
void CPyramidStorage::RemoveAll()
{
	//�Ƕ�̵� ��� �迭�� ���� CCard()���� �ʱ�ȭ
	int i,j;
	for(i=0;i<7;i++)
	{
		for(j=0;j<i+1;j++)
		{
			m_pointer[i][j] = CCard();
		}
	}
	//���� row,col�� 0���� �ʱ�ȭ
	row=0,col=0;
}

//�Ƕ�̵��� �����͸� �����ϰ� �ҷ����� �Լ�
void CPyramidStorage::Serialize(CArchive& ar)
{

	int i,j;
	for(int i=0;i<7;i++)//28�� ȣ��
		for(int j=0;j<i+1;j++)
			m_pointer[i][j].Serialize(ar);//card�� serialize �Լ� ȣ��
}