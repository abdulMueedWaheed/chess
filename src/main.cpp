#include <raylib.h>
#include "../include/board.h"
#include "../include/rendering.h"

int main(void) {
    InitWindow(width, width, "A simple Chess Game");
    SetTargetFPS(45);

    game_state_t game_state = {0};
    loadPawnTextures();


    game_state.board = setupPawns();
    game_state.white_turn = true;
    game_state.piece_selected = false;
    game_state.initial_position = {0, 0};
    game_state.final_position = {0, 0};

    while ( ! WindowShouldClose() ) {
        BeginDrawing();
        drawBoard(board_cells, cell_width, game_state.board);

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            handleMouseButtonPressed(&game_state);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}