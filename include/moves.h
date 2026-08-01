#ifndef MOVES_H
#define MOVES_H

#include "board.h"

#include <algorithm>
#include <cstdint>
#include <iterator>
#include <raylib.h>
#include <vector>

enum class MoveType {
    Quiet,
    Capture,
    DoublePawnPush,
    EnPassant,
    Castle,
    Promotion,
    PromotionCapture
};

enum class PromotionPiece {
    Queen,
    Rook,
    Bishop,
    Knight
};

typedef struct Move {
    Square from;
    Square to;
    MoveType type;
} move_t;


inline Square compressCoordinates(int x, int y) {
    return static_cast<Square>(x + (8 * y));
}

inline void decompressCoordinates(Square square, int& x, int& y) {
    x = square % 8;
    y = square / 8;
}

void handleCapture(board_t* board, Square final_position);
std::vector<move_t> getPossibleMoves(board_t* board, int initial_x, int initial_y, piece_type_t piece, bool white_turn);
void makeMove(game_state_t* game_state, std::vector<move_t> possible_moves, Square final_position);
void setFinalPosition(board_t* board, Square initial_position, Square final_position, piece_type_t piece);

// Various piece move generation functions
std::vector<move_t> getPawnMoves(board_t* board, int x, int y, bool white_turn);


#endif
