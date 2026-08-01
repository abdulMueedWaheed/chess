#include "../include/moves.h"

std::vector<move_t> getPawnMoves(board_t* board, int x, int y, bool white_turn) {
    std::vector<move_t> moves_list;

    if (white_turn) {
        moves_list.push_back({static_cast<Square>(compressCoordinates(x, y)), static_cast<Square>(compressCoordinates(x, y + 1)), MoveType::Quiet});
        moves_list.push_back({static_cast<Square>(compressCoordinates(x, y)), static_cast<Square>(compressCoordinates(x, y + 2)), MoveType::DoublePawnPush});
    }

    else {
        moves_list.push_back({static_cast<Square>(compressCoordinates(x, y)), static_cast<Square>(compressCoordinates(x, y - 1)), MoveType::Quiet});
        moves_list.push_back({static_cast<Square>(compressCoordinates(x, y)), static_cast<Square>(compressCoordinates(x, y - 2)), MoveType::DoublePawnPush});
    }

    return moves_list;
}
