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

CLDConsole::CLDConsole(const char* InstallDir)
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
	DWORD WaitRet;
	WaitRet = ::WaitForSingleObject(p.hProcess, INFINITE);
	//WaitRet =::WaitForInputIdle(p.hProcess, 5 * 1000);
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
/*
* 启动模拟器 index
*/
void CLDConsole::Launch(int Index)
{
	CString Param;
	Param.Format("launch --index %d", Index);
	this->Cmd(Param);
}
/*
* 启动模拟器 name
*/
void CLDConsole::Launch(const char* Name)
{
	CString Param;
	Param.Format("launch --name %s", Name);
	this->Cmd(Param);
}
/*
* 关闭模拟器 index
*/
void CLDConsole::Quit(int Index)
{
	CString Param;
	Param.Format("Quit --index %d", Index);
	this->Cmd(Param);
}
/*
* 关闭模拟器 name
*/
void CLDConsole::Quit(const char* Name)
{
	CString Param;
	Param.Format("Quit --name %s", Name);
	this->Cmd(Param);
}
/*
* 关闭所有模拟器
*/
void CLDConsole::QuitAll()
{
	this->Cmd("quitall");
}
/*
* 修改模拟器属性 重载 index
*/
void CLDConsole::Modify(int Index,SimulatorAttribute Flag,const char* val)
{
	CString Param;
	Param.Format("modify --index %d ", Index);
	switch (Flag)
	{
	case resolution:
		Param.Append("--resolution");
		break;
	case cpu:
		Param.Append("--cpu");
		break;
	case memory:
		Param.Append("--memory");
		break;
	case manufacturer:
		Param.Append("--manufacturer");
		break;
	case model:
		Param.Append("--model");
		break;
	case pnumber:
		Param.Append("--pnumber");
		break;
	case imei:
		Param.Append("--imei");
		break;
	case imsi:
		Param.Append("--imsi");
		break;
	case simserial:
		Param.Append("--simserial");
		break;
	case androidid:
		Param.Append("--androidid");
		break;
	case mac:
		Param.Append("--mac");
		break;
	case autorotate:
		Param.Append("--autorotate");
		break;
	case lockwindow:
		Param.Append("--lockwindow");
		break;
	default:
		return;
		break;
	}
	Param.AppendFormat(" %s", val);
	this->Cmd(Param);
}
/*
* 修改模拟器属性 重载 name
*/
void CLDConsole::Modify(const char* Name, SimulatorAttribute Flag, const char* val)
{
	CString Param;
	Param.Format("modify --name %s ", Name);
	switch (Flag)
	{
	case resolution:
		Param.Append("--resolution");
		break;
	case cpu:
		Param.Append("--cpu");
		break;
	case memory:
		Param.Append("--memory");
		break;
	case manufacturer:
		Param.Append("--manufacturer");
		break;
	case model:
		Param.Append("--model");
		break;
	case pnumber:
		Param.Append("--pnumber");
		break;
	case imei:
		Param.Append("--imei");
		break;
	case imsi:
		Param.Append("--imsi");
		break;
	case simserial:
		Param.Append("--simserial");
		break;
	case androidid:
		Param.Append("--androidid");
		break;
	case mac:
		Param.Append("--mac");
		break;
	case autorotate:
		Param.Append("--autorotate");
		break;
	case lockwindow:
		Param.Append("--lockwindow");
		break;
	default:
		return;
		break;
	}
	Param.AppendFormat(" %s", val);
	this->Cmd(Param);
}
/*
* 新增模拟器
*/
void CLDConsole::Add(const char* Name)
{
	//add [--name mnq_name]

	CString Param;
	Param.Format("add --name %s", Name);
	this->Cmd(Param);
}
/*
* 复制模拟器
*/
void CLDConsole::Copy(const char* Name, const char* From)
{
	//copy [--name mnq_name] --from
	//注意：from参数既可以是名字也可以是索引，判断规则为如果全数字就认为是索引，否则是名字
	CString Param;
	Param.Format("copy --name %s  --from %s", Name, From);
	this->Cmd(Param);
}

/*
* 删除模拟器
*/
void CLDConsole::Remove(int Index)
{
	//remove <--name mnq_name | --index mnq_idx>
	CString Param;
	Param.Format("remove --index %d", Index);
	this->Cmd(Param);
}
/*
* 删除模拟器
*/
void CLDConsole::Remove(const char* Name)
{
	//remove <--name mnq_name | --index mnq_idx>
	CString Param;
	Param.Format("remove --name %s", Name);
	this->Cmd(Param);
}
/*
* 备份 模拟器
* 备份文件名，包含完整路径，文件名必须为 *.ldbk
*/
void CLDConsole::Backup(int Index, const char* File)
{
	//backup <--name mnq_name | --index mnq_idx> --file

	CString Param;
	Param.Format("backup --index %d --file %s", Index, File);

	this->Cmd(Param);
}

void CLDConsole::Backup(const char* Name, const char* File)
{
	//backup <--name mnq_name | --index mnq_idx> --file

	CString Param;
	Param.Format("backup --name %s --file %s", Name, File);
	this->Cmd(Param);
}

void CLDConsole::Restore(int Index, const char* FileRestore)
{
	//restore <--name mnq_name | --index mnq_idx> --file

	CString Param;
	Param.Format("restore --index %d --file %s", Index, FileRestore);

	this->Cmd(Param);
}

void CLDConsole::Restore(const char* Name, const char* FileRestore)
{
	//restore <--name mnq_name | --index mnq_idx> --file

	CString Param;
	Param.Format("restore --name %s --file %s", Name, FileRestore);

	this->Cmd(Param);
}
/*
* 重命名模拟器
*/
void CLDConsole::Rename(int Index, const char* Title)
{
	//rename <--name mnq_name | --index mnq_idx> --title
	CString Param;
	Param.Format("rename --index %d --title %s", Index, Title);

	this->Cmd(Param);
}
void CLDConsole::Rename(const char* Name, const char* Title)
{
	//rename <--name mnq_name | --index mnq_idx> --title
	CString Param;
	Param.Format("rename --name %s --title %s", Name, Title);

	this->Cmd(Param);
}
/*
* 安装应用 文件
*/
void CLDConsole::installapp(int Index, const char* File)
{
	//installapp <--name mnq_name | --index mnq_idx> --filename
	CString Param;
	Param.Format("installapp --index %d --filename %s", Index, File);

	this->Cmd(Param);
}
void CLDConsole::installapp(const char* Name, const char* File)
{
	//installapp <--name mnq_name | --index mnq_idx> --filename
	CString Param;
	Param.Format("installapp --name %s --filename %s", Name, File);

	this->Cmd(Param);
}
/*
* 从雷电应用商店中下载安装
*/
void CLDConsole::installapp2(int Index, const char* PackageName)
{
	//installapp <--name mnq_name | --index mnq_idx> --packagename <apk_package_name>
	CString Param;
	Param.Format("installapp --index %d --packagename %s", Index, PackageName);

	this->Cmd(Param);
}

void CLDConsole::installapp2(const char* Name, const char* PackageName)
{
	//installapp <--name mnq_name | --index mnq_idx> --packagename <apk_package_name>
	CString Param;
	Param.Format("installapp --name %s --packagename %s", Name, PackageName);

	this->Cmd(Param);
}
/*
* 卸载应用
* 
*/
void CLDConsole::uninstallapp(int Index, const char* PackageName)
{
	//uninstallapp <--name mnq_name | --index mnq_idx> --packagename
	CString Param;
	Param.Format("uninstallapp --index %d --packagename %s", Index, PackageName);

	this->Cmd(Param);
}

void CLDConsole::uninstallapp(const char* Name, const char* PackageName)
{
	//uninstallapp <--name mnq_name | --index mnq_idx> --packagename
	CString Param;
	Param.Format("uninstallapp --name %s --packagename %s", Name, PackageName);

	this->Cmd(Param);
}
/*
* 运行应用
*/
void CLDConsole::runapp(int Index, const char* PackageName)
{
	//runapp <--name mnq_name | --index mnq_idx> --packagename
	CString Param;
	Param.Format("runapp --index %d --packagename %s", Index, PackageName);

	this->Cmd(Param);
}
void CLDConsole::runapp(const char* Name, const char* PackageName)
{
	//runapp <--name mnq_name | --index mnq_idx> --packagename
	CString Param;
	Param.Format("runapp --name %s --packagename %s", Name, PackageName);

	this->Cmd(Param);
}
/*
* 结束应用
*/
void CLDConsole::killapp(int Index, const char* PackageName)
{
	//killapp <--name mnq_name | --index mnq_idx> --packagename
	CString Param;
	Param.Format("killapp --index %d --packagename %s", Index, PackageName);

	this->Cmd(Param);
}
void CLDConsole::killapp(const char* Name, const char* PackageName)
{
	//killapp <--name mnq_name | --index mnq_idx> --packagename
	CString Param;
	Param.Format("killapp --name %s --packagename %s", Name, PackageName);

	this->Cmd(Param);
}
/*
* 修改模拟器中的GPS定位信息。此命令重启模拟器后生效，如果需要立即生效，请使用 action
*/
void CLDConsole::locate(int Index, const char* val)
{
	//locate <--name mnq_name | --index mnq_idx> --LLI

	CString Param;
	Param.Format("locate --index %d --LLI %s", Index, val);

	this->Cmd(Param);
}

void CLDConsole::locate(const char* Name, const char* val)
{
	//locate <--name mnq_name | --index mnq_idx> --LLI

	CString Param;
	Param.Format("locate --name %s --LLI %s", Name, val);

	this->Cmd(Param);
}
