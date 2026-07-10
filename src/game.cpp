#include "../include/game.h"
#include <raylib.h>

void loadPawnImages(std::array<Image,12>& imgs){

    imgs[0]  = LoadImage("pieces/bB.png");
    imgs[1]  = LoadImage("pieces/bK.png");
    imgs[2]  = LoadImage("pieces/bN.png");
    imgs[3]  = LoadImage("pieces/bp.png");
    imgs[4]  = LoadImage("pieces/bQ.png");
    imgs[5]  = LoadImage("pieces/bR.png");
    imgs[6]  = LoadImage("pieces/wB.png");
    imgs[7]  = LoadImage("pieces/wK.png");
    imgs[8]  = LoadImage("pieces/wN.png");
    imgs[9]  = LoadImage("pieces/wp.png");
    imgs[10] = LoadImage("pieces/wQ.png");
    imgs[11] = LoadImage("pieces/wR.png");
}

void drawPNG() {

}