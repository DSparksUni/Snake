#include "board.h"

snake_board* snake_board_init(size_t width, size_t height) {
    snake_board* this = malloc(sizeof(snake_board));

    this->board = calloc(width*height, sizeof(board_piece));
    memset(this->board, PIECE_EMPTY, width*height);

    this->width = width;
    this->height = height;

    return this;
}

void snake_board_print(snake_board* this) {
    for(size_t y = 0; y < this->height; y++) {
        for(size_t x = 0; x < this->width; x++) switch(snake_board_at(this, x, y)) {
            case PIECE_EMPTY: {
                printf("\x1b[40m ");
            } break;
            case PIECE_SNAKE: {
                printf("\x1b[41m ");
            } break;
            case PIECE_FOOD: {
                printf("\x1b[43m ");
            } break;
        }
        printf("\x1b[49m\n");
    }
}

void snake_board_destroy(snake_board* this) {
    free(this->board);
    free(this);
}
