#ifndef BOARD_H
#define BOARD_H

#include <cstdint>
#include <bitset>
#include <iostream>
#include <raylib.h>

constexpr int board_cells = 8;
constexpr int cell_width = 96;
constexpr int width = board_cells * cell_width;

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

typedef struct {
    board_t* board;
    bool white_turn;
    bool piece_selected;
    Vector2 initial_position;
    Vector2 final_position;
    
} game_state_t;


#define COMPRESS(x, y) ((x) + ((8) * (y)))

board_t* setupPawns();
void print_bits(std::uint64_t val);
piece_type_t getPieceAt(int x, int y, board_t* board);
Vector2 screenToBoard(int x, int y, int board_size, int cell_width);
void handleMouseButtonPressed(game_state_t* game_state);


#endif