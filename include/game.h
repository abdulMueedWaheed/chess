#ifndef GAME_H
#define GAME_H
#include <raylib.h>
#include <string>

const int board_cells = 8;
const int cell_width = 96;

const int width = board_cells * cell_width;

void drawLetterInRect(Rectangle r, std::string str);

#endif