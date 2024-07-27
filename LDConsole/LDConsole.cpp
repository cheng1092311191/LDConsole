// LDConsole.cpp : 定义静态库的函数。
//

#include "pch.h"
#include "framework.h"

#include"LDConsole.h"

#define EXECUTE_FILE	"ldconsole.exe"
#define PIPE_SIZE	0x1000
CLDConsole::CLDConsole()
{
}

CLDConsole::CLDConsole(const TCHAR* InstallDir)
	:m_InstallDir(InstallDir)
{

	if (m_InstallDir.IsEmpty()) throw "安装目录不正确";
	size_t size = m_InstallDir.GetLength();
	if (m_InstallDir.GetAt(size-1) != '\\') m_InstallDir.Append("\\");

	m_Path = m_InstallDir + EXECUTE_FILE;
	if (::GetFileAttributes(m_Path.GetBuffer()) == INVALID_FILE_ATTRIBUTES)
		throw "安装目录不正确";

}

CLDConsole::~CLDConsole()
{
}


CString CLDConsole::Cmd(CString command)
{
	STARTUPINFO Info = { 0 };
	Info.cb = sizeof(STARTUPINFO);
	HANDLE hReadPipe, hWritePipe;
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;
	CreatePipe(&hReadPipe, &hWritePipe, &sa, PIPE_SIZE);

	//CloseHandle(hReadPipe);
	Info.hStdError = hWritePipe;
	Info.hStdOutput = hWritePipe;
	//Info.hStdInput = hWritePipe;
	Info.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	Info.wShowWindow = SW_HIDE;

	PROCESS_INFORMATION p;
	CString cmd;
	cmd = m_Path + " " + command;
	
	BOOL ok =  ::CreateProcessA(NULL, (LPSTR)cmd.GetBuffer(), NULL, NULL, TRUE, NULL, NULL, NULL, &Info, &p);
	::WaitForSingleObject(p.hProcess, INFINITE);

	DWORD size=0;
	//char buf[PIPE_SIZE] = { 0 };
	ok = ::PeekNamedPipe(hReadPipe, NULL, NULL, NULL, &size, NULL);
	//分配 pipe_size  初始化 0
	CString out('\0', PIPE_SIZE + 1);

	if (size)
	{
		::ReadFile(hReadPipe, (PVOID)out.GetBuffer(), size, NULL,NULL);
	}


	::CloseHandle(p.hProcess);
	::CloseHandle(p.hThread);
	::CloseHandle(hWritePipe);
	::CloseHandle(hReadPipe);

	return out;
}

CString CLDConsole::List2()
{
	return Cmd("list2");
}

void CLDConsole::Launch(int Index)
{
	CString Param;
	Param.Format("launch --index %d", Index);
	this->Cmd(Param);
}

void CLDConsole::Launch(const TCHAR* Name)
{
	CString Param;
	Param.Format("launch --name %s", Name);
	this->Cmd(Param);
}
void CLDConsole::Quit(int Index)
{
	CString Param;
	Param.Format("Quit --index %d", Index);
	this->Cmd(Param);
}

void CLDConsole::Quit(const TCHAR* Name)
{
	CString Param;
	Param.Format("Quit --name %s", Name);
	this->Cmd(Param);
}

void CLDConsole::QuitAll()
{
	this->Cmd("quitall");
}
