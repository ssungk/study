#include "StdAfx.h"
#include "QUB3D.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include <time.h>
#include "glut.h"
#include "Block.h"
#include "resource.h"
#include <MMSystem.h>
#pragma comment(lib,"winmm")




QUB3D::QUB3D(void)
{
	
	srand(time(NULL));

	

	m_nextBlock.block1 = rand()%4+1;
	m_nextBlock.block2 = rand()%4+1;
	m_nextBlock.blocktype = 0;
	m_nextBlock.X=2;
	m_nextBlock.Y=9;


	//NewGame();


} 

QUB3D::~QUB3D(void)
{
}

void QUB3D::DrawGame()
{
	switch(m_state)
	{
	case 0:
		Draw_Background();
		Draw_Block();
		break;
	case 1:
		Draw_GameOver();
		break;
	}
	
}

void QUB3D::Draw_GameOver()
{
	char score[100] = "Score: ";

	char temp[100];
	_itoa_s(m_score,temp,10);

	strcat_s(score,temp);

	DrawText(score,-350,200); 
	DrawText("GAME OVER",-380,0);
}

void QUB3D::Draw_Background()
{
	DrawScore();
	
	//다음 블럭 모양을 그림
	DrawNextBlock();
	
	glTranslatef(0,0,-1000);
	glRotatef(-40,1,0,0);
	
	//세로선 그림
	Draw_Horizontal_Line();

	//가로선 그림
	Draw_Vertical_Line();

	//보드판 그림
	Draw_Board();
	
}

void QUB3D::Draw_Board()
{
	//보드의 색상 설정
	glColor3f(0.1f, 0.1f, 0.3f);

	glBegin(GL_POLYGON);

	glVertex2f(-300,-500);
	glVertex2f(300,-500);
	glVertex2f(300,400);
	glVertex2f(-300,400);

	glEnd();
}

void QUB3D::Draw_Horizontal_Line()
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(5.0);

	glBegin(GL_LINES);

	int i;
	for(i=-3;i<4;i++)
	{

		glVertex2f(i*100,-500);
		glVertex2f(i*100, 400);
	}

	glEnd();
}

void QUB3D::Draw_Vertical_Line()
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(5.0);

	glBegin(GL_LINES);

	int i;
	for(i=-5;i<5;i++)
	{

		glVertex2f(-300,i*100);
		glVertex2f( 300,i*100);
	}

	glEnd();
}

void QUB3D::Draw_Block()
{
	int field[6][10][2];
	int i,j,k;
	for(i=0;i<6;i++)
	{
		for(j=0;j<10;j++)
		{
			for(k=0;k<2;k++)
			{
				field[i][j][k]=m_field[i][j][k];
			}
		}
	}


	switch(m_block.blocktype)
	{
	case 0:
		field[m_block.X][m_block.Y][0] = m_block.block1;
		field[m_block.X+1][m_block.Y][0] = m_block.block2;
		break;
	case 1:
		field[m_block.X][m_block.Y][0] = m_block.block1;
		field[m_block.X][m_block.Y][1] = m_block.block2;
		break;
	case 2:
		field[m_block.X][m_block.Y][0] = m_block.block1;
		field[m_block.X][m_block.Y-1][0] = m_block.block2;
		break;
	case 3:
		field[m_block.X][m_block.Y][0] = m_block.block1;
		break;
	}

	


		
	
	for(i=0;i<6;i++)
	{
		for(j=0;j<10;j++)
		{
			for(k=0;k<2;k++)
			{
				if(field[i][j][k]>0)
				{
					switch(field[i][j][k])
					{
					case 1:
						glColor3f(1.0f, 0.0f, 0.0f);
						break;
					case 2:
						glColor3f(0.0f, 1.0f, 0.0f);
						break;
					case 3:
						glColor3f(0.0f, 0.0f, 1.0f);
						break;
					case 4:
						glColor3f(1.0f, 1.0f, 0.0f);
						break;
					}
					glPushMatrix();
					glTranslatef(-250,-450,50);
					glTranslatef(i*100,j*100,k*100);
					glutWireCube(75);
					glPopMatrix();
				}				
			}
		}
	}


}

void QUB3D::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{	
	if(m_state==0)
	{
		switch(nChar)
		{
		case VK_RIGHT: 
			RightKey();
			break;
		case VK_LEFT: 
			LeftKey();
			break;		
		case VK_UP : 
			//	UpKey();
			break;
		case VK_DOWN : 
			DownKey();
			break;	
		}
	}	

	if(m_state==1 && nChar==VK_RETURN)
	{
		NewGame();
	}
}

void QUB3D::NewBolck()
{
	m_block = m_nextBlock;
	PrepareNextBlock();
	DeleteBlock();
	
}

void QUB3D::DownKey()
{
	

	switch(m_block.blocktype)
	{
	case TYPE1:
		if(m_block.Y==0 || m_field[m_block.X][m_block.Y-1][0]>0 || m_field[m_block.X+1][m_block.Y-1][0]>0)
		{
			if(m_block.Y==0)
			{
				m_field[m_block.X][m_block.Y][0]=m_block.block1;
				m_field[m_block.X+1][m_block.Y][0]=m_block.block2;
				NewBolck();
				GameOverCheck();
			}

			if(m_field[m_block.X][m_block.Y-1][0]>0 && m_field[m_block.X+1][m_block.Y-1][0]>0)
			{
				m_field[m_block.X][m_block.Y][0]=m_block.block1;
				m_field[m_block.X+1][m_block.Y][0]=m_block.block2;
				NewBolck();
				GameOverCheck();
			}
			if(m_field[m_block.X][m_block.Y-1][0]<0 && m_field[m_block.X+1][m_block.Y-1][0]>0)
			{
				m_field[m_block.X+1][m_block.Y][0]=m_block.block2;

				m_block.blocktype = 3;
			}

			if(m_field[m_block.X][m_block.Y-1][0]>0 && m_field[m_block.X+1][m_block.Y-1][0]<0)
			{
				m_field[m_block.X][m_block.Y][0]=m_block.block1;

				m_block.block1=m_block.block2;

				m_block.X++;

				m_block.blocktype = 3;
			}
						
		}
		else
		{
			m_block.Y--;
		}
		
		break;
	case TYPE2:
		if(m_block.Y==0 || m_field[m_block.X][m_block.Y-1][0]>0)
		{
			m_field[m_block.X][m_block.Y][0]=m_block.block1;
			NewBolck();
			GameOverCheck();
		}
		else
		{
			m_block.blocktype=2;
		}
		break;
	case TYPE3:
		if((m_block.Y-1)==0 || m_field[m_block.X][m_block.Y-2][0]>0)
		{
			m_field[m_block.X][m_block.Y][0]=m_block.block1;
			m_field[m_block.X][m_block.Y-1][0]=m_block.block2;
			NewBolck();
			GameOverCheck();
		}
		else
		{
			m_block.blocktype=1;
			int temp = m_block.block1;
			m_block.block1 = m_block.block2;
			m_block.block2 = temp;
			m_block.Y--;
		}

		break;
	case TYPE4:
		if(m_block.Y==0 || m_field[m_block.X][m_block.Y-1][0]>0)
		{
			m_field[m_block.X][m_block.Y][0]=m_block.block1;
			NewBolck();
			GameOverCheck();
		}
		else
		{
			m_block.Y--;
		}
		break;
	}
	

}

void QUB3D::UpKey()
{
	switch(m_block.blocktype)
	{
	case 0:
	case 1:
	case 2:
		m_block.Y++;
		break;
	case 3:

		break;
	}
	
}

void QUB3D::LeftKey()
{
	switch(m_block.blocktype)
	{
	case TYPE1:
		m_block.blocktype = 1;
		break;
	case TYPE2:
		if(m_block.X>0)
		{
			if(m_field[m_block.X-1][m_block.Y][0]<0)
			{
				m_block.blocktype = 0;
				int temp = m_block.block1;
				m_block.block1 = m_block.block2;
				m_block.block2 = temp;
				m_block.X--;
			}
		}		
		break;
	case TYPE3:
		if(m_field[m_block.X-1][m_block.Y][0]<0 && m_field[m_block.X-1][m_block.Y-1][0]<0 && m_block.X>0)
		{
			m_block.X--;
		}		
		break;
	case TYPE4:

		break;
	}
	
}

void QUB3D::RightKey()
{
	int temp;
	switch(m_block.blocktype)
	{
	case TYPE1:		
		m_block.blocktype = 1;
		temp = m_block.block1;
		m_block.block1 = m_block.block2;
		m_block.block2 = temp;
		m_block.X++;
		
		break;
	case TYPE2:
		if(m_block.X<5)
		{
			if(m_field[m_block.X+1][m_block.Y][0]<0)
			{
				m_block.blocktype = 0;
			}
		}		
		break;
	case TYPE3:
		if(m_field[m_block.X+1][m_block.Y][0]<0 && m_field[m_block.X+1][m_block.Y-1][0]<0 && m_block.X<5)
		{
			m_block.X++;
		}	
		break;
	case TYPE4:

		break;
	}	
}

void QUB3D::DrawText(const char* str,int x, int y)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(2.0);
	glPushMatrix();

	glTranslatef(x,y,-1000);
	
	int i,length = strlen(str);
	for(i=0;i<length;i++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN,(int)str[i]);
	}

	glPopMatrix();
}

void QUB3D::DrawScore()
{
	char score[100] = "Score: ";
	
	char temp[100];
	_itoa_s(m_score,temp,10);

	strcat_s(score,temp);

	DrawText(score,0,500); 
}

void QUB3D::DeleteBlock()
{
	int count=0;
	bool flag=true;
	int i,j;

	while(flag)
	{
		count=0;
		for(i=0;i<6;i++)
		{
			for(j=0;j<10;j++)
			{
				if(CheckBlock(i,j))
				{
					count++;
				}

			}
		}

		if(count==0)
		{
			flag=false;
		}

	}
}

bool QUB3D::CheckBlock(int x, int y)
{
	if(m_field[x][y][0]>0)
	{
		int color = m_field[x][y][0];

		int check1[6][9] = {false};
		int check2[6][9] = {false};
		
		int count = 0;

		count += CheckBlockRecursive(check1,check2,color,x,y);

		if(count>=4)
		{
			//삭제
			DeleteCheckBlock(check2);

			m_score+=count*100;

			//내리기
			PushDownBlock();

			return true;
		}
		


		
	}
	
	return false;	
}

int QUB3D::CheckBlockRecursive(int check1[][9],int check2[][9],int color, int x, int y)
{
	int count=0;
	
	if(check1[x][y]==true)
	{
		return 0;
	}
	else
	{
		check1[x][y]=true;
	}
	
	

	if(m_field[x][y][0]==color)
	{
		check2[x][y]=true;

		count++;

		if(x>0)
		{
			count+=CheckBlockRecursive(check1,check2,color,x-1,y);
		}
		if(y>0)
		{
			count+=CheckBlockRecursive(check1,check2,color,x,y-1);
		}
		if(x<5)
		{
			count+=CheckBlockRecursive(check1,check2,color,x+1,y);
		}
		if(x<8)
		{
			count+=CheckBlockRecursive(check1,check2,color,x,y+1);
		}


	}
	return count;
}

void QUB3D::DeleteCheckBlock(int check[][9])
{
	int i,j;
	for(i=0;i<6;i++)
	{
		for(j=0;j<9;j++)
		{
			if(check[i][j]==true)
			{
				m_field[i][j][0]=-1;
			}
		}
	}
}

void QUB3D::PushDownBlock()
{
	int i,j,k;
	for(k=0;k<9;k++)
	{
		for(i=0;i<6;i++)
		{
			for(j=0;j<8;j++)
			{
				if(m_field[i][j][0]<0 && m_field[i][j+1][0]>0)
				{
					m_field[i][j][0] = m_field[i][j+1][0];
					m_field[i][j+1][0]=-1;
				}
			}
		}
	}			
}

void QUB3D::GameOverCheck()
{
	int i;
	for(i=0;i<6;i++)
	{
		if(m_field[i][9][0]>0)
		{
			m_state=1;
			PlaySound(NULL,NULL,NULL);
			PlaySound((LPCWSTR)MAKEINTRESOURCE(IDR_WAVE2), NULL, SND_ASYNC | SND_NODEFAULT | SND_RESOURCE);

			//NewGame();
		}
	}
}

void QUB3D::NewGame()
{
	PlaySound((LPCWSTR)MAKEINTRESOURCE(IDR_WAVE1), NULL,SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT | SND_RESOURCE);

	m_score=0;
	m_state=0;
	NewBolck();

	int i,j,k;
	for(i=0;i<6;i++)
	{
		for(j=0;j<10;j++)
		{
			for(k=0;k<2;k++)
			{
				m_field[i][j][k] = -1;
			}
		}
	}
}

void QUB3D::PrepareNextBlock()
{
	m_nextBlock.block1 = rand()%4+1;
	m_nextBlock.block2 = rand()%4+1;
	m_nextBlock.blocktype = 0;
	m_nextBlock.X=2;
	m_nextBlock.Y=9;
}

void QUB3D::DrawNextBlock()
{
	


	DrawText("Next:",-800,500);

	glLineWidth(2.0);

	glPushMatrix();

	glTranslatef(-400,550,-1000);

	ChoseColor(m_nextBlock.block1);

	glPushMatrix();
	
	glTranslatef(0,0,0);
	glutWireCube(75);
	glPopMatrix();

	ChoseColor(m_nextBlock.block2);

	glPushMatrix();
	
	glTranslatef(100,0,0);
	glutWireCube(75);
	glPopMatrix();
	

	glPopMatrix();




	
}

void QUB3D::ChoseColor(int color)
{
	switch(color)
	{
	case 1:
		glColor3f(1.0f, 0.0f, 0.0f);
		break;
	case 2:
		glColor3f(0.0f, 1.0f, 0.0f);
		break;
	case 3:
		glColor3f(0.0f, 0.0f, 1.0f);
		break;
	case 4:
		glColor3f(1.0f, 1.0f, 0.0f);
		break;
	}
}

void QUB3D::Timer()
{
	switch(m_state)
	{
	case 0:
		DownKey();
		break;
	case 1:
		
		break;
	}
}