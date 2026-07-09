#ifndef BOARD_H
#define BOARD_H

#include <cstdint>
#include <raylib.h>

struct board {
    uint64_t white_pawns;
    uint64_t white_knights;
    uint64_t white_kings;
    uint64_t white_queens;
    uint64_t white_bishop;
    uint64_t white_rooks;

    uint64_t black_pawns;
    uint64_t black_knights;
    uint64_t black_kings;
    uint64_t black_queens;
    uint64_t black_bishop;
    uint64_t black_rooks;
};

void drawBoard(int cells, int cell_width);
#endif