#include "console.h"

bool clear_console(HANDLE hconsole, CONSOLE_SCREEN_BUFFER_INFO console_info) {
    COORD topleft = {0, 0};
    DWORD console_size = (DWORD)(console_info.dwSize.X * console_info.dwSize.Y);
    DWORD written;

    if(!FillConsoleOutputCharacter(
        hconsole, ' ', console_size, topleft, &written 
    )) return false;

    SetConsoleCursorPosition(hconsole, topleft);
    return true;
}

void restore_console(HANDLE hconsole, CONSOLE_SCREEN_BUFFER_INFO console_info) {
    SetConsoleTextAttribute(hconsole, console_info.wAttributes);
}
