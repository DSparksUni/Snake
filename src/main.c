#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include <board.h>
#include <console.h>

int main(int argc, char** argv) {
    //Create game board
    snake_board* board = snake_board_init((size_t)(25 * 16/9), 25);

    //Obtain console handle
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if(hconsole == INVALID_HANDLE_VALUE) {
        fputs("[ERROR] Failed to retrieve console handle...\n", stderr);
        goto fail;
    }
    
    //Obtain console info, mainly to restore its state when the game is done
    CONSOLE_SCREEN_BUFFER_INFO console_info;
    if(!GetConsoleScreenBufferInfo(hconsole, &console_info)) {
        fputs("[ERROR] Failed to retrieve console buffer info...\n", stderr);
        goto fail;
    }

    //Set up performance counter variables for timing
    LARGE_INTEGER frequency, time_last;
    QueryPerformanceFrequency(&frequency);

    double clear_timer = 0.0;

    bool running = true;
    while(running) {
        LARGE_INTEGER time_now;
        QueryPerformanceCounter(&time_now);
        double delta_time = (double)(time_now.QuadPart - time_last.QuadPart) / (double)frequency.QuadPart;

        clear_timer += delta_time;
        if(clear_timer >= 1.0) {
            clear_console(hconsole, console_info);
            snake_board_print(board);
            clear_timer = 0.0;
        }

        if((GetAsyncKeyState('q') & 0x8000) || (GetAsyncKeyState('Q') & 0x8000)) running = false;

        time_last = time_now;
    }

    restore_console(hconsole, console_info);
    snake_board_destroy(board);
    return 0;
fail:
    restore_console(hconsole, console_info);
    if(board) snake_board_destroy(board);
    return -1;
}
