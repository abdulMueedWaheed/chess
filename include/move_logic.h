#ifndef MOVES_H
#define MOVES_H

#include "board.h"


#include <algorithm>
#include <cstdint>
#include <iterator>
#include <raylib.h>
#include <vector>

typedef struct {
    int x, y;
} position_t;

std::uint64_t* getPossibleMoves(board_t* board, int x, int y);
std::vector<std::uint64_t> getPawnMoves(std::uint64_t pieces, Vector2 current_position, bool white_turn);
void makeMove(game_state_t* game_state);

#endif
