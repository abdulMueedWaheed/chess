#include "../include/moves.h"
#include <cstdlib>
#include <vector>

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

std::vector<move_t> getKnightMoves(board_t* board, int x, int y) {
    std::vector<move_t> moves_list;
    int arr[] = {-1, 1, -2, 2};

    int dx, dy;
    for (int i = 0; i < 4; i++) {
        dx = arr[i];
        for (int j = 0; j < 4; j++) {
            dy = arr[j];

            if (abs(dx) != abs(dy)) {
                moves_list.push_back({
                    .from = static_cast<Square>(compressCoordinates(x, y)),
                    .to = static_cast<Square>(compressCoordinates(x + dx, y + dy)),
                });
            }
        }
    }
    return moves_list;
}

std::vector<move_t> getBishopMoves(board_t* board, int x, int y) {
    std::vector<move_t> moves_list;

    return moves_list;
}