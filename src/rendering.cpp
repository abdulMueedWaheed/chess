#include "../include/rendering.h"
#include "../include/board.h"

#include <raylib.h>

std::unordered_map<std::string, Texture2D> pawnTextures;

void loadPawnTextures() {
    pawnTextures["black_bishop"] = LoadTexture("pieces/black_bishop.png");
    pawnTextures["black_king"] = LoadTexture("pieces/black_king.png");
    pawnTextures["black_knight"] = LoadTexture("pieces/black_knight.png");
    pawnTextures["black_pawn"] = LoadTexture("pieces/black_pawn.png");
    pawnTextures["black_queen"] = LoadTexture("pieces/black_queen.png");
    pawnTextures["black_rook"] = LoadTexture("pieces/black_rook.png");

    pawnTextures["white_bishop"] = LoadTexture("pieces/white_bishop.png");
    pawnTextures["white_king"] = LoadTexture("pieces/white_king.png");
    pawnTextures["white_knight"] = LoadTexture("pieces/white_knight.png");
    pawnTextures["white_pawn"] = LoadTexture("pieces/white_pawn.png");
    pawnTextures["white_queen"] = LoadTexture("pieces/white_queen.png");
    pawnTextures["white_rook"] = LoadTexture("pieces/white_rook.png");
}

void drawPiece(Rectangle r, Texture2D tex) {
    float x = (r.x + (r.width - tex.width) / 2.0f);
    float y = (r.y + (r.height - tex.height) / 2.0f);
    // DrawTexture(tex, x, y, WHITE);
    float desiredHeight = 64.0f;
    DrawTextureEx(tex, (struct Vector2){x, y}, 0, desiredHeight/tex.height, WHITE);
}

void drawBoard(int board_size, int cell_width, board_t* board) {
    
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            
            bool isBlack = ((i + j) % 2 != 0);
            Rectangle rect = {
                .x = static_cast<float>(i * cell_width),
                .y = static_cast<float>(j * cell_width),
                .width = static_cast<float>(cell_width),
                .height = static_cast<float>(cell_width),
            };
            DrawRectangleRec(rect, isBlack ? BLACK : WHITE);
            drawPiece(rect, pawnTextures[getPieceAt(i, j, board)]);
        }
    }

}