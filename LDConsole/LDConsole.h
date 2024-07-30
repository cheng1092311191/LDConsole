
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
	// 自定义分辨率 例: 值=  600,360,160 表示 600*300 160pdi
	resolution = 1,

	// cpu设置<1 | 2 | 3 | 4>] 
	cpu = 2,

	// 内存设置 <512 | 1024 | 2048 | 4096 | 8192>]
	memory = 4,

	// 手机厂商
	manufacturer = 8,

	// 手机型号
	model = 0x10,

	//手机号
	pnumber = 0x20,

	// imei设置，auto就自动随机生成
	imei = 0x40,
	//识别码
	imsi = 0x80,

	simserial = 0x100,

	androidid = 0x200,
	//12位m16进制mac地址
	mac = 0x400,
	//<1 | 0>
	autorotate = 0x800,
	//<1 | 0>
	lockwindow = 0x1000,
};
enum keyboard 
{
	//返回键
	back=1,
	//home键
	home,
	//菜单键
	menu,
	//音量+
	volumeup,
	//音量-
	volumedown,
};
/*
* 操作 ldconsole.exe
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
	* 启动模拟器 index
	*/
	void Launch(int Index);
	/*
	* 启动模拟器 name
	*/
	void Launch(const char* Name);
	/*
	* 关闭模拟器 index
	*/
	void Quit(int Index);
	/*
	* 关闭模拟器 name
	*/
	void Quit(const char* Name);
	/*
	* 关闭所有模拟器
	*/
	void QuitAll();
	/*
	* 修改模拟器属性 重载 index
	*/
	void Modify(int Index ,SimulatorAttribute Flag, const char* val);
	/*
	* 修改模拟器属性 重载 name
	*/
	void Modify(const char * Name ,SimulatorAttribute Flag, const char* val);

	/*
	* 新增模拟器
	*/
	void Add(const char* Name);

	/*
	* 复制模拟器
	* from参数既可以是名字也可以是索引，判断规则为如果全数字就认为是索引，否则是名字
	*/
	void Copy(const char* Name, const char * From);
	/*
	* 删除模拟器
	*/
	void Remove(int Index);
	/*
	* 删除模拟器
	*/
	void Remove(const char* Name);
	/*
	* 备份 模拟器
	* 备份文件名，包含完整路径，文件名必须为 *.ldbk
	*/
	void Backup(int Index,const char * File);
	/*
	* 备份 模拟器
	* 备份文件名，包含完整路径，文件名必须为 *.ldbk
	*/
	void Backup(const char* Name,const char * File);


	/*
	* 还原模拟器
	* 备份文件名，包含完整路径，文件名必须为 *.ldbk 
	*/
	void Restore(int Index, const char* FileRestore);
	/*
	* 还原模拟器
	* 备份文件名，包含完整路径，文件名必须为 *.ldbk 
	*/
	void Restore(const char* Name, const char* FileRestore);

	/*
	* 重命名模拟器
	*/
	void Rename(int Index, const char* Title);
	/*
	* 重命名模拟器
	*/
	void Rename(const char* Name, const char* Title);


	/* 
	* 安装应用  文件
	* apk安装包的完整路径，比如：C:\Users\Administrator\Documents\test.apk
	*/
	void installapp(int Index, const char* File);
	/*
	* 安装应用  文件
	* apk安装包的完整路径，比如：C:\Users\Administrator\Documents\test.apk
	*/
	void installapp(const char* Name, const char* File);
	/*
	* 安装应用  包名
	* 从雷电应用商店里下载安装
	*/
	void installapp2(int Index, const char* PackageName);
	/*
	* 安装应用  包名
	* 从雷电应用商店里下载安装
	*/
	void installapp2(const char* Name, const char* PackageName);

	/*
	* 卸载应用
	*/
	void uninstallapp(int Index, const char* PackageName);
	void uninstallapp(const char* Name, const char* PackageName);
	/*
	* 运行应用
	*/
	void runapp(int Index, const char* PackageName);
	void runapp(const char* Name, const char* PackageName);
	/*
	* 结束应用
	*/
	void killapp(int Index, const char* PackageName);
	/*
	* 结束应用
	*/
	void killapp(const char* Name, const char* PackageName);
	/*
	* 修改模拟器中的GPS定位信息。此命令重启模拟器后生效，如果需要立即生效，请使用 action
	*  val = 经度,纬度
	*/
	void locate(int Index, const char* val);
	/*
	* 修改模拟器中的GPS定位信息。此命令重启模拟器后生效，如果需要立即生效，请使用 action
	*  val = 经度,纬度
	*/
	void locate(const char* Name, const char* val);

	/*
	* 设置属性
	* --key "phone.imei" --value "auto"
	* --key "phone.imsi" --value "auto"
	* --key "phone.simserial" --value "auto"
	*/
	void setprop(int Index,const char * Key, const char* val);
	/*
	* 设置属性
	* --key "phone.imei" --value "auto"
	* --key "phone.imsi" --value "auto"
	* --key "phone.simserial" --value "auto"
	*/
	void setprop(const char * Name,const char * Key, const char* val);
	/*
	* 设置系统属性
	*/
	CString getprop(int Index, const char* Key);
	/*
	* 设置系统属性
	*/
	CString getprop(const char* Name, const char* Key);

	/*
	* 全局设置
	*	fps：模拟器帧率[0, 60]
	*	audio：音频，打开=1，关闭=0
	*	fastpaly : 快速显示模式，打开=1，关闭=0
	*/
	void globalsetting(const char* Key, const char* val);

	/*
	* 降低cpu占用
	*  <0~100>
	*/
	void downcpu(int Index,UINT8 rate);
	/*
	* 降低cpu占用
	*/
	void downcpu(const char* Name, UINT8 rate);
	/*
	* 重启模拟器
	*/
	void reboot(int Index);
	/*
	* 重启模拟器
	*/
	void reboot(const char* Name);

	/*
	* 动作
	* --key call.keyboard --value back
	* --key call.reboot --value com.android.settings
	* --key call.locate --value 12.3,45.6
	* --key call.shake --value null
	*/
	void action(int Index,const char * Key,const char* val);
	void action(const char* Name, const char* Key, const char* val);
	/*
	* 动作-按键
	*/
	void action_keyboard(int Index, enum keyboard type);
	void action_keyboard(const char* Name, enum keyboard type);
	/*
	* 动作-摇一摇
	*/
	void action_shake(int Index);
	/*
	* 动作-摇一摇
	*/
	void action_shake(const char* Name);

	/*
	* 动作-重启模拟器,并启动应用
	* PackageName: 应用包名
	*/
	void action_reboot(int Index,const char * PackageName);
	/*
	* 动作-重启模拟器,并启动应用
	* PackageName: 应用包名
	*/
	void action_reboot(const char* Name,const char * PackageName);
	/*
	* 动作-定位
	* val:  采用国际坐标（WGS84），格式为：“纬度,经度”。例如：“39.908821,116.397469”
	*/
	void action_locate(int Index, const char* val);
	/*
	* 动作-定位
	* val:  采用国际坐标（WGS84），格式为：“纬度,经度”。例如：“39.908821,116.397469”
	*/
	void action_locate(const char* Name, const char* val);
	/*
	* 动作-文字输入
	*/
	void action_input(int Index, const char* val);
	/*
	* 动作-文字输入
	*/
	void action_input(const char* Name, const char* val);

	/*
	* 动作-网络连接/断开
	* isConnect: true 连接, false 断开
	*/
	void action_network(int Index, bool isConnect);
	/*
	* 动作-网络连接/断开
	* isConnect: true 连接, false 断开
	*/
	void action_network(const char* Name, bool isConnect);
	/*
	* 动作-重力感应
	*/
	void action_gravity(int Index, int x, int y, int z);
	void action_gravity(const char* Name, int x, int y, int z);

	/*
	* 扫描二维码
	* file: 完整文件路径
	*/
	void scan(int Index, const char* File);
	/*
	* 扫描二维码
	* file: 完整文件路径
	*/
	void scan(const char* Name, const char* File);

	/*
	* 启动模拟器-并自动运行应用
	* PackageName: 应用包名
	*/
	void launchex(int Index, const char* PackageName);
	/*
	* 启动模拟器-并自动运行应用
	* PackageName: 应用包名
	*/
	void launchex(const char* Name, const char* PackageName);
private:
	CString m_InstallDir;
	CString m_Path;
	 
};

