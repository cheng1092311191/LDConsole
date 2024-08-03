#include"pch.h"
#include"help.h"

using namespace std;
 vector<CString> Split(CString str, CString splitText)
{
	 int i;
	 int start = 0;
	 int subLen = splitText.GetLength();
	 vector<CString> out;
	 if (str.IsEmpty())
	 {
		 goto _ret;
	 }
	 i = str.Find(splitText, start);
	 if (i ==-1)
	 {
		 goto _ret;
	 }
	 do
	 {
		 CString sub;
		 int count = i - start;
		 sub = str.Mid(start, count);
		 start = i + subLen;
		 if (sub.GetLength())
		 {
			 out.push_back(sub);
		 }
		 i = str.Find(splitText, start);
	 } while (i!=-1);
	 //È¡Î²²¿
	 if (start <str.GetLength())
	 {
		 CString sub  = str.Mid(start);
		 if (sub.GetLength())
		 {
			 out.push_back(sub);
		 }

	 }



 _ret:
	 return out;

}