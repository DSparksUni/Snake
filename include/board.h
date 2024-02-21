#ifndef BOARD_H_INCLUDED_
#define BOARD_H_INCLUDED_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define snake_board_size(board) sizeof(board) / sizeof(board_piece)
#define snake_board_at(sb, x, y) sb->board[y*sb->width + x]

typedef enum board_piece_t {
    PIECE_EMPTY,
    PIECE_SNAKE,
    PIECE_FOOD
} board_piece;

typedef struct snake_board_t {
    size_t width, height;
    board_piece* board;
} snake_board;

snake_board* snake_board_init(size_t, size_t);

void snake_board_print(snake_board*);

void snake_board_destroy(snake_board*);

#endif  //BOARD_H_INCLUDED_
