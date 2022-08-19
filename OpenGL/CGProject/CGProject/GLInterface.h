#pragma once

#include "QUB3D.h"

class CGLInterface
{
public:
	CGLInterface(void);
	virtual ~CGLInterface(void);
	int Initialize(CDC *pDC);
	void Release(void);
	BOOL SetPixelFormat(PIXELFORMATDESCRIPTOR *pPFD = NULL);
	void SetProjectView(int cx, int cy);
	void Display(void * pData = NULL);
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void Timer();
	void NewGame();


private:
	HGLRC m_hRC;
	CDC * m_pDC;
	QUB3D qub3d;
};

