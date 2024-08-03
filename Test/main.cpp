#include<iostream>
#include"LDConsole.h"
#pragma comment(lib,"LDConsole.lib")
using namespace std;

int main()
{
	CLDConsole ld("E:\\LeiDian\\LDPlayer9");
	//cout << ld.List2() << endl;
	//ld.Launch(0);
	//ld.Launch("utfy97");
	//ld.Launch(2);
	//ld.Launch(3);
	//ld.Quit("utfy97");
	//ld.Quit(3);
	//Sleep(500);
	//ld.QuitAll();
	//ld.Modify(1, SimulatorAttribute::resolution, "900,1600,320");
	//ld.Modify(1, SimulatorAttribute::cpu, "2");
	//ld.Modify(1, SimulatorAttribute::pnumber, "12345678911");

	//ld.Copy("new", "lvjiezao");
	//ld.Remove("new");
	//ld.Backup(1, "G:\\backup.ldbk");
	//ld.Add("new1");
	//ld.Restore(6, "G:\\backup.ldbk");
	//ld.Rename("newTitle", "newTitle22");
	
	//ld.Launch(6);
	//ld.installapp(6, "H:\\¶ÉÑ»2\\chouma.apk");
	//ld.runapp(6, "com.neowiz.playstudio.slot.casino");
	//Sleep(100);
	//ld.killapp(6, "com.neowiz.playstudio.slot.casino");
	//ld.uninstallapp(6, "com.neowiz.playstudio.slot.casino");
	//ld.Quit(6);
	//ld.locate(6, "118.8091619999999,32.04241000000003");
	//ld.setprop(6, "phone.imei", "auto");
	//cout << ld.getprop(6, "phone.imsi") << endl;
	//ld.globalsetting("audio", "0");
	//ld.reboot(6);
	//ld.Launch(5);
	//ld.action_shake(5);
	//ld.action_keyboard(5, keyboard::volumeup);
	//ld.action_reboot(5, "com.android.settings");
	//ld.action_input(5, "ÎÒÊÇÎÄ×Ö");
	//ld.action_network(5, false);
	//ld.action_network(5, true);
	//ld.launchex(5, "com.android.settings");
	//ld.action_gravity(5, 50, 30, 20);
	//CString str =ld.packages(6,"-f");
	//adb --index 6 --command "shell pm list packages -f"
	//cout << str << endl;
	//str.Replace("package:", "");
	//ld.clear(6, "com.android.browser");
	
	cout << ld.path(6, "com.android.browser") << endl;
	cout << ld.devices() << endl;
	cout << ld.pid(6, "com.android.browser") << endl;
	
	return 0;
}