#ifndef BOARD_H
#define BOARD_H

#include <cstdint>
#include <bitset>
#include <iostream>
#include <raylib.h>

#include "game.h"

struct board_t {
    std::uint64_t black_bishops;
    std::uint64_t black_kings;
    std::uint64_t black_knights;
    std::uint64_t black_pawns;
    std::uint64_t black_queens;
    std::uint64_t black_rooks;
    
    std::uint64_t white_bishops;
    std::uint64_t white_kings;
    std::uint64_t white_knights;
    std::uint64_t white_pawns;
    std::uint64_t white_queens;
    std::uint64_t white_rooks;
};

typedef enum {
    PIECE_NONE = -1,
    WHITE_PAWN,
    WHITE_KNIGHT,
    WHITE_BISHOP,
    WHITE_ROOK,
    WHITE_QUEEN,
    WHITE_KING,

    BLACK_PAWN,
    BLACK_KNIGHT,
    BLACK_BISHOP,
    BLACK_ROOK,
    BLACK_QUEEN,
    BLACK_KING,
} piece_type_t;

#define COMPRESS(x, y) ((x) + ((8) * (y)))

board_t* setupPawns();
void print_bits(std::uint64_t val);
piece_type_t getPieceAt(int x, int y, board_t* board);
Vector2 screenToBoard(int x, int y, int board_size, int cell_width);

#endif