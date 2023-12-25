#include <Windows.h>

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
	wc.lpfnWndProc = DefWindowProc;		//Function tha handles all the messages we will use default for now
	wc.cbClsExtra = 0;					//Alows allocate extra bites for the window class structure
	wc.cbWndExtra = 0;					//Alows allocate extra bites for each window
	wc.hInstance = hInstance;			//Instance
	wc.hIcon = nullptr;					//Custom icons
	wc.hCursor = nullptr;				//Custom cursor
	wc.hbrBackground = nullptr;			//Brush for background will use dx3d
	wc.lpszMenuName = nullptr;			//Menu name (Wont use for now)
	wc.lpszClassName = pClassName;		//Name that we will use to register class
	wc.hIconSm = nullptr;				//Custom icon for app
	RegisterClassEx(&wc);

	//Create Window
	HWND hWnd = CreateWindowExW(
		0, pClassName,
		L"Happy Hard Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, // Styles, cool stuff
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr
	);
	ShowWindow(hWnd, SW_SHOW);



	while (true);

	return 0;
}