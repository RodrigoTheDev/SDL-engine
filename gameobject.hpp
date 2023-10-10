#ifndef GAMEOBJECT
#define GAMEOBJECT

#include <SDL2/SDL.h>
#include <iostream>

class GameObject {
public:
    int IMGWIDTH = 64;
    int IMGHEIGHT = 64;
    int moveSpeed = 64;
    std::string imgPath = "";
    SDL_Rect srcRect = {0,0,IMGWIDTH,IMGHEIGHT};
    SDL_Rect dstRect = {0,0,IMGWIDTH,IMGHEIGHT};

    GameObject(std::string filePath, int xpos, int ypos) {
        this->imgPath = filePath;
        this->dstRect.x = xpos;
        this->dstRect.y = ypos;

    }
};


#endif