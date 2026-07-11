#include "../include/board.h"
#include <cstdint>
#include <string>

board_t* setupPawns() {
    board_t* board = new board_t();

    board->black_pawns = static_cast<std::uint64_t>(0b11111111) << 48;
    board->black_knights = static_cast<std::uint64_t>(0b01000010) << 56;
    board->black_kings = static_cast<std::uint64_t>(0b00001000) << 56;
    board->black_queens = static_cast<std::uint64_t>(0b00010000) << 56;
    board->black_bishops = static_cast<std::uint64_t>(0b00100100) << 56;
    board->black_rooks = static_cast<std::uint64_t>(0b10000001) << 56;
    
    board->white_pawns = static_cast<std::uint64_t>(0b11111111) << 8;
    board->white_knights = static_cast<std::uint64_t>(0b01000010);
    board->white_kings = static_cast<std::uint64_t>(0b00001000);
    board->white_queens = static_cast<std::uint64_t>(0b00010000);
    board->white_bishops = static_cast<std::uint64_t>(0b00100100);
    board->white_rooks = static_cast<std::uint64_t>(0b10000001);

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

std::string getPieceAt(int x, int y, board_t* board) {
    std::uint64_t mask = static_cast<std::uint64_t>(1) << (y * 8 + x);

    if (board->black_pawns & mask) return "black_pawn";
    if (board->black_knights & mask) return "black_knight";
    if (board->black_bishops & mask) return "black_bishop";
    if (board->black_rooks & mask) return "black_rook";
    if (board->black_queens & mask) return "black_queen";
    if (board->black_kings & mask) return "black_king";

    if (board->white_pawns & mask) return "white_pawn";
    if (board->white_knights & mask) return "white_knight";
    if (board->white_bishops & mask) return "white_bishop";
    if (board->white_rooks & mask) return "white_rook";
    if (board->white_queens & mask) return "white_queen";
    if (board->white_kings & mask) return "white_king";

    return ".";
}