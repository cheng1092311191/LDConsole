
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
enum keyboard 
{
	//���ؼ�
	back=1,
	//home��
	home,
	//�˵���
	menu,
	//����+
	volumeup,
	//����-
	volumedown,
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

	/*
	* ��������
	* --key "phone.imei" --value "auto"
	* --key "phone.imsi" --value "auto"
	* --key "phone.simserial" --value "auto"
	*/
	void setprop(int Index,const char * Key, const char* val);
	/*
	* ��������
	* --key "phone.imei" --value "auto"
	* --key "phone.imsi" --value "auto"
	* --key "phone.simserial" --value "auto"
	*/
	void setprop(const char * Name,const char * Key, const char* val);
	/*
	* ����ϵͳ����
	*/
	CString getprop(int Index, const char* Key);
	/*
	* ����ϵͳ����
	*/
	CString getprop(const char* Name, const char* Key);

	/*
	* ȫ������
	*	fps��ģ����֡��[0, 60]
	*	audio����Ƶ����=1���ر�=0
	*	fastpaly : ������ʾģʽ����=1���ر�=0
	*/
	void globalsetting(const char* Key, const char* val);

	/*
	* ����cpuռ��
	*  <0~100>
	*/
	void downcpu(int Index,UINT8 rate);
	/*
	* ����cpuռ��
	*/
	void downcpu(const char* Name, UINT8 rate);
	/*
	* ����ģ����
	*/
	void reboot(int Index);
	/*
	* ����ģ����
	*/
	void reboot(const char* Name);

	/*
	* ����
	* --key call.keyboard --value back
	* --key call.reboot --value com.android.settings
	* --key call.locate --value 12.3,45.6
	* --key call.shake --value null
	*/
	void action(int Index,const char * Key,const char* val);
	void action(const char* Name, const char* Key, const char* val);
	/*
	* ����-����
	*/
	void action_keyboard(int Index, enum keyboard type);
	void action_keyboard(const char* Name, enum keyboard type);
	/*
	* ����-ҡһҡ
	*/
	void action_shake(int Index);
	/*
	* ����-ҡһҡ
	*/
	void action_shake(const char* Name);

	/*
	* ����-����ģ����,������Ӧ��
	* PackageName: Ӧ�ð���
	*/
	void action_reboot(int Index,const char * PackageName);
	/*
	* ����-����ģ����,������Ӧ��
	* PackageName: Ӧ�ð���
	*/
	void action_reboot(const char* Name,const char * PackageName);
	/*
	* ����-��λ
	* val:  ���ù������꣨WGS84������ʽΪ����γ��,���ȡ������磺��39.908821,116.397469��
	*/
	void action_locate(int Index, const char* val);
	/*
	* ����-��λ
	* val:  ���ù������꣨WGS84������ʽΪ����γ��,���ȡ������磺��39.908821,116.397469��
	*/
	void action_locate(const char* Name, const char* val);
	/*
	* ����-��������
	*/
	void action_input(int Index, const char* val);
	/*
	* ����-��������
	*/
	void action_input(const char* Name, const char* val);

	/*
	* ����-��������/�Ͽ�
	* isConnect: true ����, false �Ͽ�
	*/
	void action_network(int Index, bool isConnect);
	/*
	* ����-��������/�Ͽ�
	* isConnect: true ����, false �Ͽ�
	*/
	void action_network(const char* Name, bool isConnect);
	/*
	* ����-������Ӧ
	*/
	void action_gravity(int Index, int x, int y, int z);
	void action_gravity(const char* Name, int x, int y, int z);

	/*
	* ɨ���ά��
	* file: �����ļ�·��
	*/
	void scan(int Index, const char* File);
	/*
	* ɨ���ά��
	* file: �����ļ�·��
	*/
	void scan(const char* Name, const char* File);

	/*
	* ����ģ����-���Զ�����Ӧ��
	* PackageName: Ӧ�ð���
	*/
	void launchex(int Index, const char* PackageName);
	/*
	* ����ģ����-���Զ�����Ӧ��
	* PackageName: Ӧ�ð���
	*/
	void launchex(const char* Name, const char* PackageName);
private:
	CString m_InstallDir;
	CString m_Path;
	 
};

