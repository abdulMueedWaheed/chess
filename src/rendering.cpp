#include "../include/rendering.h"
#include "../include/board.h"

#include <cstdlib>
#include <iostream>
#include <lunasvg/lunasvg.h>
#include <raylib.h>
#include <string>

std::array<Texture2D, 12> pieceTextures{};

Texture2D loadSVG(const std::string& file_path, int width, int height) {
    auto doc = lunasvg::Document::loadFromFile(file_path);
    if(doc == nullptr) {
        std::cerr << "Given file couldn't be found: " << file_path << "\n";
        std::exit(EXIT_FAILURE);
    }

    auto bitmap = doc->renderToBitmap(width, height);

    Image image{};
    image.data = bitmap.data();
    image.width = bitmap.width();
    image.height = bitmap.height();
    image.mipmaps = 1;
    image.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;

    Texture2D texture = LoadTextureFromImage(image);

    return texture;
}

void loadPawnTextures() {
    pieceTextures[BLACK_BISHOP] = loadSVG("pieces/bB.svg", 256, 256);
    pieceTextures[BLACK_KING]   = loadSVG("pieces/bK.svg", 256, 256);
    pieceTextures[BLACK_KNIGHT] = loadSVG("pieces/bN.svg", 256, 256);
    pieceTextures[BLACK_PAWN]   = loadSVG("pieces/bP.svg", 256, 256);
    pieceTextures[BLACK_QUEEN]  = loadSVG("pieces/bQ.svg", 256, 256);
    pieceTextures[BLACK_ROOK]   = loadSVG("pieces/bR.svg", 256, 256);

    pieceTextures[WHITE_BISHOP] = loadSVG("pieces/wB.svg", 256, 256);
    pieceTextures[WHITE_KING]   = loadSVG("pieces/wK.svg", 256, 256);
    pieceTextures[WHITE_KNIGHT] = loadSVG("pieces/wN.svg", 256, 256);
    pieceTextures[WHITE_PAWN]   = loadSVG("pieces/wP.svg", 256, 256);
    pieceTextures[WHITE_QUEEN]  = loadSVG("pieces/wQ.svg", 256, 256);
    pieceTextures[WHITE_ROOK]   = loadSVG("pieces/wR.svg", 256, 256);
}

void drawPiece(Rectangle r, Texture2D tex) {
    if (tex.id == 0) {
        return;
    }

    float desiredSize = r.width * 0.78f;
    float scale = desiredSize / static_cast<float>(tex.width);

    float x = r.x + (r.width - (tex.width * scale)) / 2.0f;
    float y = r.y + (r.height - (tex.height * scale)) / 2.0f;

    DrawTextureEx(tex, (Vector2){x, y}, 0.0f, scale, WHITE);
}

void drawBoard(int board_size, int cell_width, board_t* board) {
    Color lightSquare = {230, 205, 165, 255};
    Color darkSquare = {140, 85, 40, 255};
    Color borderColor = {95, 55, 25, 255};

    for (int screenY = 0; screenY < board_size; ++screenY) {
        for (int screenX = 0; screenX < board_size; ++screenX) {

            bool isBlack = ((screenX + screenY) % 2 != 0);
            Rectangle rect = {
                .x = static_cast<float>(screenX * cell_width),
                .y = static_cast<float>(screenY * cell_width),
                .width = static_cast<float>(cell_width),
                .height = static_cast<float>(cell_width),
            };

            DrawRectangleRec(rect, isBlack ? darkSquare : lightSquare);
            DrawRectangleLinesEx(rect, 2, borderColor);

            int boardX = screenX;
            int boardY = board_size - 1 - screenY;
            piece_type_t pieceType = getPieceAt(boardX, boardY, board);
            if (pieceType != PIECE_NONE) {
                drawPiece(rect, pieceTextures[pieceType]);
            }
        }
    }
}