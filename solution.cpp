#include <iostream>
#include <Windows.h>
#pragma comment (lib, "imm32.lib")
#define IMC_GETOPENSTATUS 0x0005
using namespace std;

void pressVK15();

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
) {
    while (true) {
        HWND hIME = ImmGetDefaultIMEWnd(GetForegroundWindow());
        LRESULT ZeroifKorean = SendMessage(hIME, WM_IME_CONTROL, IMC_GETOPENSTATUS, 0);
        LRESULT ZeroIfA = SendMessage(hIME, WM_IME_CONTROL, 0x01, 0);

        if (ZeroifKorean == 0 && ZeroIfA == 0) {
            pressVK15();  
            Sleep(1000);
        }
        Sleep(100);
    }
    return 0;
}

void pressVK15() {
    INPUT inputs[2] = {};

    // Pressing VK 0x15
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = 0x15;

    // Releasing VK 0x15
    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = 0x15;
    inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(2, inputs, sizeof(INPUT));
}
