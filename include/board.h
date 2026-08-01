#ifndef BOARD_H
#define BOARD_H

#include <cstdint>
#include <bitset>
#include <iostream>
#include <raylib.h>

using Square = std::uint8_t;

constexpr int board_cells = 8;
constexpr int cell_width = 96;
constexpr int width = board_cells * cell_width;

typedef struct {
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
} board_t;

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
    Square selected_square;
    piece_type_t selected_piece;
    bool is_white_turn;
    bool is_piece_selected;
    
} game_state_t;




board_t* setupPawns();
void print_bits(std::uint64_t val);
piece_type_t getPieceAt(int x, int y, board_t* board);
Vector2 screenToBoard(int x, int y, int board_size, int cell_width);
std::uint64_t boardToUInt64(int x, int y);
void handleMouseButtonPressed(game_state_t* game_state);


#endif
