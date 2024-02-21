#ifndef CONSOLE_H_INCLUDED_
#define CONSOLE_H_INCLUDED_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

bool clear_console(HANDLE, CONSOLE_SCREEN_BUFFER_INFO);
void restore_console(HANDLE, CONSOLE_SCREEN_BUFFER_INFO);

#endif  //CONSOLE_H_INCLUDED_
