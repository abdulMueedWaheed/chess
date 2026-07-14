#include "../include/board.h"
#include <cstdint>
#include <raylib.h>

board_t* setupPawns() {
    board_t* board = new board_t();

    board->black_pawns   = static_cast<std::uint64_t>(0b11111111) << 48;
    board->black_knights = static_cast<std::uint64_t>(0b01000010) << 56;
    board->black_kings   = static_cast<std::uint64_t>(0b00001000) << 56;
    board->black_queens  = static_cast<std::uint64_t>(0b00010000) << 56;
    board->black_bishops = static_cast<std::uint64_t>(0b00100100) << 56;
    board->black_rooks   = static_cast<std::uint64_t>(0b10000001) << 56;
    
    board->white_pawns   = static_cast<std::uint64_t>(0b11111111) << 8;
    board->white_knights = static_cast<std::uint64_t>(0b01000010);
    board->white_kings   = static_cast<std::uint64_t>(0b00001000);
    board->white_queens  = static_cast<std::uint64_t>(0b00010000);
    board->white_bishops = static_cast<std::uint64_t>(0b00100100);
    board->white_rooks   = static_cast<std::uint64_t>(0b10000001);

    return board;
}

void print_bits(std::uint64_t val) {
    std::bitset<64> bits(val);

    for (int i = 63; i >= 0; --i) {
        std::cout << bits[i];

        if (i % 8 == 0)
            std::cout << ' ';
    }

    std::cout << "\n";
}

piece_type_t getPieceAt(int x, int y, board_t* board) {
    std::uint64_t mask = static_cast<std::uint64_t>(1) << (y * 8 + x);

    if (board->black_pawns   & mask) return BLACK_PAWN;
    if (board->black_knights & mask) return BLACK_KNIGHT;
    if (board->black_bishops & mask) return BLACK_BISHOP;
    if (board->black_rooks   & mask) return BLACK_ROOK;
    if (board->black_queens  & mask) return BLACK_QUEEN;
    if (board->black_kings   & mask) return BLACK_KING;

    if (board->white_pawns   & mask) return WHITE_PAWN;
    if (board->white_knights & mask) return WHITE_KNIGHT;
    if (board->white_bishops & mask) return WHITE_BISHOP;
    if (board->white_rooks   & mask) return WHITE_ROOK;
    if (board->white_queens  & mask) return WHITE_QUEEN;
    if (board->white_kings   & mask) return WHITE_KING;

    return PIECE_NONE;
}

Vector2 screenToBoard(int x, int y, int board_size, int cell_width) {
    if (x < 0 || y < 0 || x >= board_size * cell_width || y >= board_size * cell_width) {
        return {0.0f, 0.0f};
    }

    int boardX = x / cell_width;
    int boardY = board_size - 1 - (y / cell_width);

    return Vector2({static_cast<float>(boardX), static_cast<float>(boardY)});
}