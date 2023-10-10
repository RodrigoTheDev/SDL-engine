#ifndef RENDER
#define RENDER

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "gameobject.hpp"



SDL_Texture *loadTexture(std::string filePath, SDL_Renderer *renderTarget) {
    SDL_Texture *texture = nullptr;
    SDL_Surface *surface = SDL_LoadBMP(filePath.c_str());

    if (surface == NULL) {
        std::cout << "Error" << std::endl;
    }
    else {
        texture = SDL_CreateTextureFromSurface(renderTarget, surface);
        if(texture == NULL) {
            std::cout << "Error" << std::endl;
        }
    }

    SDL_FreeSurface(surface);

    return texture;
}

void drawObject(GameObject obj, SDL_Renderer *renderTarget) {
    SDL_Texture *img = loadTexture(obj.imgPath, renderTarget);
    SDL_RenderCopy(renderTarget, img, &obj.srcRect, &obj.dstRect);

    SDL_DestroyTexture(img);
    img = nullptr;

}

void drawAll(const std::vector<GameObject>& vetor, SDL_Renderer *renderTarget) {
    // Use o vetor normalmente
    for (GameObject valor : vetor) {
        drawObject(valor, renderTarget);
    }
}

#endif