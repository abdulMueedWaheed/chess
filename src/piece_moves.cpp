#include "../include/moves.h"
#include <cstdlib>
#include <vector>


std::vector<move_t> getPawnMoves(board_t* board, int x, int y, bool white_turn) {
    std::vector<move_t> moves_list;

    if (white_turn) {
        moves_list.push_back({static_cast<Square>(compressCoordinates(x, y)), static_cast<Square>(compressCoordinates(x, y + 1))});
        moves_list.push_back({static_cast<Square>(compressCoordinates(x, y)), static_cast<Square>(compressCoordinates(x, y + 2))});
    }

    else {
        moves_list.push_back({static_cast<Square>(compressCoordinates(x, y)), static_cast<Square>(compressCoordinates(x, y - 1))});
        moves_list.push_back({static_cast<Square>(compressCoordinates(x, y)), static_cast<Square>(compressCoordinates(x, y - 2))});
    }

    return moves_list;
}

std::vector<move_t> getKnightMoves(int x, int y) {
    std::vector<move_t> moves_list;
    int arr[] = {-1, 1, -2, 2};

    int dx, dy;
    for (int i = 0; i < 4; i++) {
        dx = arr[i];
        for (int j = 0; j < 4; j++) {
            dy = arr[j];

            if ((abs(dx) != abs(dy)) && withinBounds(x + dx, y + dy)) {
                moves_list.push_back({
                    .from = static_cast<Square>(compressCoordinates(x, y)),
                    .to = static_cast<Square>(compressCoordinates(x + dx, y + dy)),
                });
            }
        }
    }
    return moves_list;
}

std::vector<move_t> getSlidingMoves(int x, int y, const int directions[][2], int directionCount) {
    std::vector<move_t> slidingMoves;
    int dx, dy;
    for (int i = 0; i < directionCount; i++) {
        dx = directions[i][0];
        dy = directions[i][1];

        int nx = x + dx;
        int ny = y + dy;

        while (withinBounds(nx, ny)) {
            slidingMoves.push_back({
                .from = static_cast<Square>(compressCoordinates(x, y)),
                .to = static_cast<Square>(compressCoordinates(nx, ny))
            });

            nx += dx;
            ny += dy;
        }
    }

    return slidingMoves;
}

std::vector<move_t> getRookMoves(int x, int y) {
    const int rookDirs[4][2] = {
        { 1,  0},
        {-1,  0},
        { 0,  1},
        { 0, -1}
    };
    
    return getSlidingMoves(x, y, rookDirs, 4);
}

std::vector<move_t> getBishopMoves(int x, int y) {
    const int bishopDirs[4][2] = {
        { 1, -1},
        { 1,  1},
        {-1, -1},
        {-1,  1}
    };
    
    return getSlidingMoves(x, y, bishopDirs, 4);
}

std::vector<move_t> getQueenMoves(int x, int y) {
    const int queenDirs[8][2] = {
        { 1, -1},
        { 1,  1},
        {-1, -1},
        {-1,  1},
        { 1,  0},
        {-1,  0},
        { 0,  1},
        { 0, -1}
    };
    
    return getSlidingMoves(x, y, queenDirs, 8);
}
