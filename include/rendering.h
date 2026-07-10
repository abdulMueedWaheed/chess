#ifndef RENDERING_H
#define RENDERING_H

#include <raylib.h>
#include <string>
#include <unordered_map>

void loadPawnTextures();
void drawPiece(Rectangle r, Texture2D tex);

extern std::unordered_map<std::string, Texture2D> pawnTextures;

#endif
