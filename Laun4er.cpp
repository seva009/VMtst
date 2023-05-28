#include <windows.h>
#include <shellapi.h>

LPCSTR File = "FlashKiller.exe";
LPCSTR Parameters = "parameters";
LPCSTR run = "runas";


int main()
{
   SHELLEXECUTEINFO shInfo = { 0 };
   shInfo.cbSize = sizeof(SHELLEXECUTEINFO);
   shInfo.fMask = SEE_MASK_FLAG_NO_UI | SEE_MASK_FLAG_DDEWAIT;
   shInfo.lpVerb = run;
   shInfo.lpFile = File;
   shInfo.lpParameters = Parameters;
   shInfo.nShow = SW_SHOW;

   ShellExecuteEx(&shInfo);
}