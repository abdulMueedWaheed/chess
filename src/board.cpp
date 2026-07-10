#include "../include/board.h"
#include <cstdint>

std::uint64_t board_state;

board_t* setupPawns() {
    board_t* board = new board_t();

    board->black_bishops = static_cast<std::uint64_t>(0b11111111) << 48;
    board->black_kings = static_cast<std::uint64_t>(0b01000010) << 56;
    board->black_knights = static_cast<std::uint64_t>(0b00001000) << 56;
    board->black_pawns = static_cast<std::uint64_t>(0b00010000) << 56;
    board->black_queens = static_cast<std::uint64_t>(0b00100100) << 56;
    board->black_rooks = static_cast<std::uint64_t>(0b10000001) << 56;
    
    board->white_bishops = static_cast<std::uint64_t>(0b11111111) << 8;
    board->white_kings = static_cast<std::uint64_t>(0b01000010);
    board->white_knights = static_cast<std::uint64_t>(0b00001000);
    board->white_pawns = static_cast<std::uint64_t>(0b00010000);
    board->white_queens = static_cast<std::uint64_t>(0b00100100);
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