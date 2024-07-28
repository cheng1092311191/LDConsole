
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
enum SimulatorAttribute
{
	// �Զ���ֱ��� ��: ֵ=  600,360,160 ��ʾ 600*300 160pdi
	resolution = 1,

	// cpu����<1 | 2 | 3 | 4>] 
	cpu = 2,

	// �ڴ����� <512 | 1024 | 2048 | 4096 | 8192>]
	memory = 4,

	// �ֻ�����
	manufacturer = 8,

	// �ֻ��ͺ�
	model = 0x10,

	//�ֻ���
	pnumber = 0x20,

	// imei���ã�auto���Զ��������
	imei = 0x40,
	//ʶ����
	imsi = 0x80,

	simserial = 0x100,

	androidid = 0x200,
	//12λm16����mac��ַ
	mac = 0x400,
	//<1 | 0>
	autorotate = 0x800,
	//<1 | 0>
	lockwindow = 0x1000,
};
/*
* ���� ldconsole.exe
*/
class CLDConsole
{
public:
	CLDConsole();
	CLDConsole(const char* InstallDir);
	~CLDConsole();

	CString Cmd(CString command);

public:
	CString List2();
	/*
	* ����ģ���� index
	*/
	void Launch(int Index);
	/*
	* ����ģ���� name
	*/
	void Launch(const char* Name);
	/*
	* �ر�ģ���� index
	*/
	void Quit(int Index);
	/*
	* �ر�ģ���� name
	*/
	void Quit(const char* Name);
	/*
	* �ر�����ģ����
	*/
	void QuitAll();
	/*
	* �޸�ģ�������� ���� index
	*/
	void Modify(int Index ,SimulatorAttribute Flag, const char* val);
	/*
	* �޸�ģ�������� ���� name
	*/
	void Modify(const char * Name ,SimulatorAttribute Flag, const char* val);

	/*
	* ����ģ����
	*/
	void Add(const char* Name);

	/*
	* ����ģ����
	* from�����ȿ���������Ҳ�������������жϹ���Ϊ���ȫ���־���Ϊ������������������
	*/
	void Copy(const char* Name, const char * From);
	/*
	* ɾ��ģ����
	*/
	void Remove(int Index);
	/*
	* ɾ��ģ����
	*/
	void Remove(const char* Name);
	/*
	* ���� ģ����
	* �����ļ�������������·�����ļ�������Ϊ *.ldbk
	*/
	void Backup(int Index,const char * File);
	/*
	* ���� ģ����
	* �����ļ�������������·�����ļ�������Ϊ *.ldbk
	*/
	void Backup(const char* Name,const char * File);


	/*
	* ��ԭģ����
	* �����ļ�������������·�����ļ�������Ϊ *.ldbk 
	*/
	void Restore(int Index, const char* FileRestore);
	/*
	* ��ԭģ����
	* �����ļ�������������·�����ļ�������Ϊ *.ldbk 
	*/
	void Restore(const char* Name, const char* FileRestore);

	/*
	* ������ģ����
	*/
	void Rename(int Index, const char* Title);
	/*
	* ������ģ����
	*/
	void Rename(const char* Name, const char* Title);


	/* 
	* ��װӦ��  �ļ�
	* apk��װ��������·�������磺C:\Users\Administrator\Documents\test.apk
	*/
	void installapp(int Index, const char* File);
	/*
	* ��װӦ��  �ļ�
	* apk��װ��������·�������磺C:\Users\Administrator\Documents\test.apk
	*/
	void installapp(const char* Name, const char* File);
	/*
	* ��װӦ��  ����
	* ���׵�Ӧ���̵������ذ�װ
	*/
	void installapp2(int Index, const char* PackageName);
	/*
	* ��װӦ��  ����
	* ���׵�Ӧ���̵������ذ�װ
	*/
	void installapp2(const char* Name, const char* PackageName);

	/*
	* ж��Ӧ��
	*/
	void uninstallapp(int Index, const char* PackageName);
	void uninstallapp(const char* Name, const char* PackageName);
	/*
	* ����Ӧ��
	*/
	void runapp(int Index, const char* PackageName);
	void runapp(const char* Name, const char* PackageName);
	/*
	* ����Ӧ��
	*/
	void killapp(int Index, const char* PackageName);
	/*
	* ����Ӧ��
	*/
	void killapp(const char* Name, const char* PackageName);
	/*
	* �޸�ģ�����е�GPS��λ��Ϣ������������ģ��������Ч�������Ҫ������Ч����ʹ�� action
	*  val = ����,γ��
	*/
	void locate(int Index, const char* val);
	/*
	* �޸�ģ�����е�GPS��λ��Ϣ������������ģ��������Ч�������Ҫ������Ч����ʹ�� action
	*  val = ����,γ��
	*/
	void locate(const char* Name, const char* val);
private:
	CString m_InstallDir;
	CString m_Path;
	 
};

