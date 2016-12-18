#include <afxwin.h>

int counter = 0;
int statusOfTimer = 1;
int TimerID = 1;

class CMyMainWnd : public CFrameWnd 
{
	int key;
	CBrush* brush;
public:
	CMyMainWnd()
	{
		Create(NULL, L"Здравствуй");
	}
	afx_msg void OnTimer(UINT)
	{
		CClientDC dc(this);
		dc.SetTextColor(RGB(rand() % 255, rand() % 255, rand() % 255));
		dc.TextOutW(100, 100, L"Текст с таймера");
		counter++;
		if (counter == 10)
		{
			counter = 0;
			KillTimer(TimerID);
			statusOfTimer = 0;
			TimerID++;
		}
	}
	afx_msg void OnLButtonDown(UINT, CPoint)
	{
		key = -1;
		Invalidate(); 
	}
	afx_msg void OnRButtonDown(UINT, CPoint)
	{
		SetTimer(TimerID, 1000, NULL);
	}
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		switch (nChar) {
		case 49:
			key = 1;
			brush = new CBrush(RGB(10, 255, 255));
			Invalidate();
			break;
		case 50:
			key = 2;
			brush = new CBrush(RGB(220, 175, 15));
			Invalidate();
			break;
		case 51:
			key = 3;
			brush = new CBrush(RGB(150, 10, 10));
			Invalidate();
			break;
		case 52:
			key = 4;
			brush = new CBrush(RGB(75, 200, 200));
			Invalidate();
			break;
		case 53:
			key = 5;
			brush = new CBrush(RGB(255, 189, 99));
			Invalidate();
			break;
		case 54:
			key = 6;
			brush = new CBrush(RGB(200, 200, 100));
			Invalidate();
			break;
		}
	}
	afx_msg void OnPaint()
	{
		CPaintDC DC(this);
		DC.SelectObject(brush);
		switch (key) {
		case 1: 
			DC.Ellipse(80, 80, 200, 200);
			break;
		case 2: 
			DC.Ellipse(80, 80, 250, 250);
			break;
		case 3: 
			DC.Ellipse(150, 150, 350, 350);
			break;
		case 4: 
			DC.Ellipse(220, 220, 250, 250);
			break;
		case 5: 
			DC.Ellipse(230, 230, 100, 100);
			break;
		case 6:
			DC.Ellipse(100, 100, 50, 50);
			break;
		}
	}
	~CMyMainWnd()
	{
		if (!statusOfTimer)
			KillTimer(TimerID);
	}
	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CMyMainWnd, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

class CMyApp : public CWinApp
{
public:
	CMyApp() {};
	virtual BOOL InitInstance()
	{             
		m_pMainWnd = new CMyMainWnd(); 
		m_pMainWnd->ShowWindow(SW_SHOW); 
		return TRUE;
	}
};



CMyApp theApp;