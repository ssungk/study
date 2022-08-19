#pragma once

#include "Block.h"


enum type {TYPE1=0,TYPE2,TYPE3,TYPE4};

class QUB3D
{
private:
	int m_field[6][10][2];
	Block m_block;
	Block m_nextBlock;
	int m_score;
	int m_state;
public:
	QUB3D(void);
	~QUB3D(void);
	void DrawGame();
	void Draw_Background();
	void Draw_Board();
	void Draw_GameOver();
	void Draw_Horizontal_Line();
	void Draw_Vertical_Line();
	void Draw_Block();
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void NewBolck();
	void DownKey();
	void UpKey();
	void LeftKey();
	void RightKey();

	void DrawScore();
	void DrawText(const char* str,int x, int y);

	void DrawNextBlock();

	void DeleteBlock();
	bool CheckBlock(int x, int y);
	int CheckBlockRecursive(int check1[][9],int check2[][9],int color, int x, int y);
	void DeleteCheckBlock(int check[][9]);

	void PushDownBlock();
	void GameOverCheck();
	void NewGame();
	void PrepareNextBlock();
	void ChoseColor(int color);

	void Timer();
};

