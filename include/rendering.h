#ifndef RENDERING_H
#define RENDERING_H

#include <raylib.h>
#include <string>
#include <unordered_map>

#include "game.h"
#include "board.h"

void loadPawnTextures();
void drawPiece(Rectangle r, Texture2D tex);
void drawBoard(int cells, int cell_width, board_t* board);

extern std::unordered_map<std::string, Texture2D> pawnTextures;

#endif
