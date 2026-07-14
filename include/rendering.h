#ifndef RENDERING_H
#define RENDERING_H

#include <array>
#include <raylib.h>
#include <string>

#include "game.h"
#include "board.h"
#include <lunasvg/lunasvg.h>

Texture2D loadSVG(const std::string& file_path, int width, int height);
void loadPawnTextures();
void drawPiece(Rectangle r, Texture2D tex);
void drawBoard(int cells, int cell_width, board_t* board);

extern std::array<Texture2D, 12> pieceTextures;

#endif
