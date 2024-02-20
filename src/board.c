#include "board.h"

snake_board snake_board_init(size_t width, size_t height) {
    snake_board this = calloc(width*height, sizeof(board_piece));
    memset(this, PIECE_EMPTY, width*height);

    return this;
}

void snake_board_destroy(snake_board this) {
    free(this);
}
