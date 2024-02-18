#include <Windows.h>

void main() {
	while (1){
        INPUT i = { 0 };
        i.type = INPUT_KEYBOARD;
        i.ki.wVk = 0x4A; // J
        //DOWN
        SendInput(1, &i, sizeof(INPUT));

        //UP
        i.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &i, sizeof(INPUT));

		Sleep(5000);
	}


}