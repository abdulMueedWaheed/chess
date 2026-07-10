#include <iostream>
#include <raylib.h>
#include "../include/game.h"
#include "../include/board.h"


int main(void) {
    std::cout << "Assalam o Alaikum!\n";
    InitWindow(width, width, "A simple Chess Game");
    SetTargetFPS(45);
    board_t* board = setupPawns();
    
    
    while ( ! WindowShouldClose() ) {
        BeginDrawing();
        drawBoard(board_cells, cell_width);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}