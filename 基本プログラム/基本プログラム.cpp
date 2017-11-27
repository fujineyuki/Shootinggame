#include"stdafx.h"
#include"��{�v���O����.h"
#include"InitDx.h"
#include "game.h"
#include <mmsystem.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib")

Game *game;

HINSTANCE hInst;

ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HWND hwndApp;

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPTSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	MSG msg;
	MyRegisterClass(hInstance);

	if (!InitInstance(hInstance, nCmdShow)){
		return FALSE;
	}

	//if (!InitDX()){//DirectX�̏�����
	//		return FALSE;
	//}

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _T("MYCLASS");
	wcex.hIconSm = NULL;
	return RegisterClassEx(&wcex);
}
// �֐�: InitInstance(HINSTANCE,int)
// �ړI: �C���X�^���X�n���h����ۑ����āA���C���E�B���h�E���쐬���܂��B
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; //�O���[�o���ϐ��ɃC���X�^���X�������i�[���܂��B
	hwndApp = CreateWindowA("MYCLASS", "�V���[�e�B���O�Q�[��", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, SCREEN_W, SCREEN_H, NULL, NULL, hInstance, NULL);
	if (!hwndApp)   return FALSE;
	ShowWindow(hwndApp, nCmdShow);

	InitDX::InitDev(hwndApp);

	game = new Game();
	return TRUE;
}

//�֐�: WndProc(HWND,UINT,WPARAM,LPARAM)
//�ړI: ���C���E�B���h�E�̃��b�Z�[�W���������܂��B

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 30, NULL);
		break;
	case WM_TIMER:
		game->GameControl();
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}