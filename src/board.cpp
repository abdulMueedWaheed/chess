#include "../include/board.h"

void drawBoard(int board_size, int cell_width) {
    
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            
            bool isBlack = ((i + j) % 2 != 0);
            DrawRectangle(i * cell_width, j * cell_width, cell_width, cell_width, isBlack ? BLACK : WHITE);
        }
    }

}