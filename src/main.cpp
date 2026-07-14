#include <cstdio>
#include <raylib.h>
#include "../include/game.h"
#include "../include/board.h"
#include "../include/rendering.h"
#include "../include/move_logic.h"

int main(void) {
    InitWindow(width, width, "A simple Chess Game");
    SetTargetFPS(45);
    bool piece_selected = false;
    Vector2 initial_position = {0, 0};
    Vector2 final_position = {0, 0};
    bool white_turn = true;

    loadPawnTextures();
    board_t* board = setupPawns();

    while ( ! WindowShouldClose() ) {
        BeginDrawing();
        drawBoard(board_cells, cell_width, board);

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (!piece_selected) {
                auto p = GetMousePosition();
                initial_position = screenToBoard(p.x, p.y, board_cells, cell_width);
                
                piece_type_t piece = getPieceAt(initial_position.x, initial_position.y, board);
                
                if (piece != PIECE_NONE) {
                    piece_selected = true;
                    std::printf("initial: %f, %f\n", initial_position.x, initial_position.y);
                    std::fflush(stdout);
                    
                }

                else {
                    piece_selected = false;
                }
            }

            else {
                piece_selected = false;
                auto p = GetMousePosition();
                final_position = screenToBoard(p.x, p.y, board_cells, cell_width);

                std::printf("final: %f, %f\n", final_position.x, final_position.y);
                std::fflush(stdout);
                
                makeMove(board, initial_position, final_position, white_turn);
            }

        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}