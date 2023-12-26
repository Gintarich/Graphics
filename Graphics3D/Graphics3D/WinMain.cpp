#include <Windows.h>
#include <string>
#include <sstream>


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	case WM_CHAR:
		{
			static std::wstring title;
			title.push_back((char)wParam);
			SetWindowTextW(hWnd, title.c_str());
		}
		break;
	case WM_LBUTTONDOWN:
		{
			const POINTS pt = MAKEPOINTS(lParam);
			std::ostringstream oss;
			oss << "(" << pt.x << "," << pt.y << ")";
			SetWindowTextA(hWnd, oss.str().c_str());
		}
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}


int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	  lpCmdLine,
	int		  nCmdShow)
{

	const auto pClassName = L"hw3dbutts";

	// register window class
	WNDCLASSEXW wc = { 0 };
	wc.cbSize = sizeof(wc);				//Size of the structure
	wc.style = CS_OWNDC;				//Class style CS_OWNDC every window will have separete device context
	wc.lpfnWndProc = WndProc;		//Function tha handles all the messages we will use default for now
	wc.cbClsExtra = 0;					//Alows allocate extra bites for the window class structure
	wc.cbWndExtra = 0;					//Alows allocate extra bites for each window
	wc.hInstance = hInstance;			//Instance
	wc.hIcon = nullptr;					//Custom icons
	wc.hCursor = nullptr;				//Custom cursor
	wc.hbrBackground = nullptr;			//Brush for background will use dx3d
	wc.lpszMenuName = nullptr;			//Menu name (Wont use for now)
	wc.lpszClassName = pClassName;		//Name that we will use to register class
	wc.hIconSm = nullptr;				//Custom icon for app
	RegisterClassExW(&wc);

	//Create Window
	HWND hWnd = CreateWindowExW(
		0, pClassName,
		L"Happy Hard Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, // Styles, cool stuff
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr
	);
	ShowWindow(hWnd, SW_SHOW);

	//Handle messages
	MSG msg;
	BOOL gResult;//Get message returns -1 if something wrong

	while ((gResult = GetMessageW(&msg,nullptr,0,0))>0)
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
	if (gResult == -1)
	{
		return -1;
	}
	else return msg.wParam;
}