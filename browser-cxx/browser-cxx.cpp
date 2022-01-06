#include "stdafx.h"
#include <iostream>

#pragma comment(lib,"gdiplus.lib")

CAppModule _Module;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	_Module.Init(NULL, hInstance);

	Gdiplus::GdiplusStartupInput m_gdiplusStartupInput;
	ULONG_PTR m_gdiplusToken;
	Gdiplus::GdiplusStartup(&m_gdiplusToken, &m_gdiplusStartupInput, NULL);
	
	class CMainFrame : public CFrameWindowImpl<CMainFrame>
	{
		BEGIN_MSG_MAP(CMainFrame)

			MSG_WM_CLOSE(OnClose)

			CHAIN_MSG_MAP(CFrameWindowImpl<CMainFrame>)

		END_MSG_MAP()

		void OnClose()
		{
			PostQuitMessage(0);
			SetMsgHandled(FALSE);
		}
	};

	CMainFrame mainFrame;
	mainFrame.Create(NULL);
	mainFrame.CenterWindow();
	mainFrame.ShowWindow(SW_SHOWNORMAL);

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	_Module.Term();
	Gdiplus::GdiplusShutdown(m_gdiplusToken);
	return msg.wParam;
}
