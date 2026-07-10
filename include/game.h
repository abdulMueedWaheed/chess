#ifndef GAME_H
#define GAME_H
#include <raylib.h>
#include <string>
#include <raylib.h>
#include <array>

#define NUM_IMAGES 12
const int board_cells = 8;
const int cell_width = 96;

const int width = board_cells * cell_width;


void loadPawnImages(std::array<Image,12>& imgs);
void drawLetterInRect(Rectangle r, std::string str);

#endif