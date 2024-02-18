#include <iostream>
#include <Windows.h>
HHOOK hhk;
LRESULT CALLBACK KeyboardHandler(
	_In_ int    code,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
) {

    KBDLLHOOKSTRUCT* s = (KBDLLHOOKSTRUCT*)lParam;

    if (s->flags & LLKHF_LOWER_IL_INJECTED || s->flags & LLKHF_INJECTED) {
        std::cout << "Keyboard press was emulated\n"; 
    }

	return CallNextHookEx(hhk, code, wParam, lParam);

}

void main() {
	hhk = SetWindowsHookExA(13, &KeyboardHandler, 0, 0);
    struct tagMSG Msg;
    if (hhk)
    {
        while (GetMessageA(&Msg, 0, 0, 0))
        {
            TranslateMessage(&Msg);
            DispatchMessageA(&Msg);
        }
        UnhookWindowsHookEx(hhk);
        hhk = 0;
        return;
    }
}