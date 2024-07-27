
#pragma once
#include<iostream>
#include<cstring>
#include<Windows.h>
#include<atlstr.h>
#include<cstringt.h>
using namespace std;

struct SimulatorInfo_t
{
	int	Index;
	char Name[1024];
	HWND TophWnd;
	HWND BindhWnd;
	bool InAndroid;
	DWORD Pid;
	DWORD VBoxPid;
};

/*
* ²Ù×÷ ldconsole.exe
*/
class CLDConsole
{
public:
	CLDConsole();
	CLDConsole(const TCHAR* InstallDir);
	~CLDConsole();

	CString Cmd(CString command);

public:
	CString List2();
	void Launch(int Index);
	void Launch(const TCHAR* Name);
	void Quit(int Index);
	void Quit(const TCHAR* Name);
	void QuitAll();
private:
	CString m_InstallDir;
	CString m_Path;
	 
};

