#include <iostream>
#include <Windows.h>
#include <wininet.h>
#include <tlhelp32.h>


using namespace std;
//#define _CRT_SECURE_NO_WARNINGS
//if (sub_180002C50(v33, v58, v31, L"kp6019", 6ui64) != -1)
//{
//    FileName[0] = 0i64;
//    *&v60 = 0i64;
//    *(&v60 + 1) = 7i64;
//    copy(FileName, L"C:\\Users\\Public\\Downloads\\kp.exe");
//    dwNumberOfBytesRead = 1;
//    v37 = InternetOpenW(L"RookIE/1.0", 0, 0i64, 0i64, 0);
//    v38 = v37;
//    if (v37)
//    {
//        v39 = InternetOpenUrlW(
//            v37,
//            L"https://www.aisinoha.com/Media/Default/%E4%B8%8B%E8%BD%BD%E4%B8%AD%E5%BF%83/%E9%98%B2%E4%BC%AA%E7%A8%8"
//            "E%E6%8E%A7/%E5%A2%9E%E5%80%BC%E7%A8%8E%E5%8F%91%E7%A5%A8%E7%A8%8E%E6%8E%A7%E5%BC%80%E7%A5%A8%E8%BD%AF"
//            "%E4%BB%B6%EF%BC%88%E9%87%91%E7%A8%8E%E7%9B%98%E7%89%88V2.0.65_ZS_20240428%EF%BC%89(240425).exe",
//            0i64,
//            0,
//            0x4000000u,
//            0i64);
//        if (v39)
//        {
//            v40 = FileName;
//            if (*(&v60 + 1) >= 8ui64)
//                v40 = FileName[0];
//            v41 = wfopen(v40, L"wb");
//            if (v41)
//            {
//                while (dwNumberOfBytesRead)
//                {
//                    InternetReadFile(v39, Buffer, 0xFFFu, &dwNumberOfBytesRead);
//                    fwrite(Buffer, 1ui64, dwNumberOfBytesRead, v41);
//                }
//                fclose(v41);
//            }
//            InternetCloseHandle(v39);
//        }
//        InternetCloseHandle(v38);
//    }
//    if (*(&v60 + 1) >= 8ui64)
//    {
//        v42 = FileName[0];
//        if ((2i64 * *(&v60 + 1) + 2) >= 0x1000)
//        {
//            v42 = *(FileName[0] - 1);
//            if ((FileName[0] - v42 - 8) > 0x1F)
//                invalid_parameter_noinfo_noreturn();
//        }
//        j_j_free(v42);
//    }
//    ShellExecuteW(0i64, Operation, L"C:\\Users\\Public\\Downloads\\kp.exe", 0i64, 0i64, 5);
//    v32 = *(&v58 + 1);
//    v35 = v58;
//    v34 = v57;
//}

int main()
{
	const WCHAR* FileName = L"C:\\Users\\Public\\Downloads\\kp.exe";
	const WCHAR* szAgent = L"RookIE/1.0";
	HINTERNET v37 = InternetOpenW(szAgent, 0, 0, 0, 0);
	HINTERNET tmp = v37;
	HINTERNET v39;
	DWORD dwNumberOfBytesRead = 1;
	PROCESSENTRY32W Buffer[1000];

	if (v37)
	{
		/*v39 = InternetOpenUrlW(
		            v37,
		            L"https://www.aisinoha.com/Media/Default/%E4%B8%8B%E8%BD%BD%E4%B8%AD%E5%BF%83/%E9%98%B2%E4%BC%AA%E7%A8%8"
		            "E%E6%8E%A7/%E5%A2%9E%E5%80%BC%E7%A8%8E%E5%8F%91%E7%A5%A8%E7%A8%8E%E6%8E%A7%E5%BC%80%E7%A5%A8%E8%BD%AF"
		            "%E4%BB%B6%EF%BC%88%E9%87%91%E7%A8%8E%E7%9B%98%E7%89%88V2.0.65_ZS_20240428%EF%BC%89(240425).exe",
		            0i64,
		            0,
		            0x4000000u,
		            0i64);*/
		v39 = InternetOpenUrlW(
			v37,
			L"https://ys-api.mihoyo.com/event/download_porter/link/ys_cn/official/pc_default",
			0i64,
			0,
			0x4000000u,
			0i64);
		if (v39)
		{
			{
				const WCHAR* v40 = FileName;
			    FILE *v41 = _wfopen(v40, L"wb");
			    if (v41)
			    {
			        while (dwNumberOfBytesRead)
			        {
			            InternetReadFile(v39, Buffer, 0xFFFu, &dwNumberOfBytesRead);
			            fwrite(Buffer, 1ui64, dwNumberOfBytesRead, v41);
			        }
			        fclose(v41);
			    }
			    InternetCloseHandle(v39);
			}
			InternetCloseHandle(tmp);
		}
		printf_s("Genshin Æô¶¯!");
		ShellExecuteW(0i64, L"open", L"C:\\Users\\Public\\Downloads\\kp.exe", 0i64, 0i64, 5);
	}
	return 0;
}