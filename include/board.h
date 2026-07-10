#ifndef BOARD_H
#define BOARD_H

#include <cstdint>
#include <bitset>
#include <iostream>

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

void drawBoard(int cells, int cell_width);
board_t* setupPawns();
void print_bits(std::uint64_t val);

extern std::uint64_t board_state;

#endif