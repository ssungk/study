#include "StdAfx.h"
#include "GLInterface.h"

#include <gl/GL.h>
#include <gl/GLU.h>

CGLInterface::CGLInterface(void)
{
	m_hRC = NULL;
	m_pDC = NULL;
}


CGLInterface::~CGLInterface(void)
{
	if(m_pDC || m_hRC)
		Release();
}

int CGLInterface::Initialize(CDC *pDC)
{
	if(m_pDC || m_hRC) 
	{
		::AfxMessageBox(L"Already initialized");
		return -1;
	}
	
	if(!(m_pDC = pDC)) 
	{
		::AfxMessageBox(L"Fail to get device context");
		return -1;
	}

	if(!SetPixelFormat(NULL))
	{
		::AfxMessageBox(L"SetupPixelFormat failed");
		return -1;
	}

	if(!(m_hRC = wglCreateContext(m_pDC->GetSafeHdc())))
	{
		::AfxMessageBox(L"wglCreateContext failed");
		return -1;
	}

	if (!wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC))
	{
		::AfxMessageBox(L"wglMakeCurrent failed");
		return -1;
	}

	return 0;
}

void CGLInterface::Release(void)
{
	if(!wglMakeCurrent(0,0))
		::AfxMessageBox(L"wglMakeCurrent dailed");

	if(m_hRC && !wglDeleteContext(m_hRC))
		::AfxMessageBox(L"wglDeleteContext dailed");

	if(m_pDC)
		delete m_pDC;

	m_hRC = NULL;	//Must be NULL
	m_pDC = NULL;	//Must be NULL
}

BOOL CGLInterface::SetPixelFormat(PIXELFORMATDESCRIPTOR *pPFD)
{
	if (!pPFD)
	{
		PIXELFORMATDESCRIPTOR pfd = {
			sizeof(PIXELFORMATDESCRIPTOR),
			1, PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
			PFD_TYPE_RGBA, 24, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 16, 0, 0,
			PFD_MAIN_PLANE, 0, 0, 0, 0 };
			pPFD = &pfd;
	}

	int nPF = ::ChoosePixelFormat(m_pDC->GetSafeHdc(),pPFD);
	if(!nPF)
	{
		::AfxMessageBox(L"ChoosePixelFormat failed");
		return FALSE;
	}

	if(!::SetPixelFormat(m_pDC->GetSafeHdc(), nPF, pPFD) )
	{
		::AfxMessageBox(L"SetpixelFormat failed");
		return FALSE;
	}

	return TRUE ;
}

void CGLInterface::SetProjectView(int cx, int cy)
{
	// cx와 cy는 클라이언트 영역의 x축, y축 크기
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLdouble)cx / (GLdouble)cy, 1.0, 5000.0);
	glViewport(0,0,cx,cy);
	//gluLookAt(0.0,-600.0,900.0, 0.0,0.0,0.0, 0.0,1.0,0.0);

	

	glEnable(GL_DEPTH_TEST);
}

void CGLInterface::Display(void * pData)
{
	glMatrixMode(GL_MODELVIEW);
	//COLOR_BUFFER 초기화
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//배경을 검은색으로 초기화
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//매트릭스 초기화
	glLoadIdentity();
	
	
	

	qub3d.DrawGame();

	

	glFlush();
	SwapBuffers(wglGetCurrentDC());
}

void CGLInterface::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	qub3d.OnKeyDown(nChar,nRepCnt,nFlags);
}

void CGLInterface::Timer()
{
	qub3d.Timer();
}

void CGLInterface::NewGame()
{
	qub3d.NewGame();
}