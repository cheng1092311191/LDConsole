#include<iostream>
#include"LDConsole.h"
#pragma comment(lib,"LDConsole.lib")
using namespace std;



int main()
{
	CLDConsole ld("E:\\LeiDian\\LDPlayer4.0");
	cout << ld.Cmd("list2") << endl;
	//ld.Launch(0);
	ld.Launch("utfy97");
	ld.Launch(2);
	ld.Launch(3);

	ld.Quit("utfy97");
	ld.Quit(3);
	ld.QuitAll();


	return 0;
}