#ifndef EVENTOTECLADO
#define EVENTOTECLADO

#include <SDL2/SDL.h>
#include <iostream>

int checkKeys(SDL_Event ev) {

    if (ev.type == SDL_KEYDOWN) {
        switch(ev.key.keysym.sym)
        {
            case SDLK_UP:
                // std::cout << "UP" << std::endl;
                return 1;
                break;

            case SDLK_RIGHT:
                // std::cout << "RIGHT" << std::endl;
                return 2;
                break;

            case SDLK_DOWN:
                // std::cout << "DOWN" << std::endl;
                return 3;
                break;

            case SDLK_LEFT:
                // std::cout << "LEFT" << std::endl;
                return 4;
                break;
        }
    }

    return 0;
}

bool keyLeft(SDL_Event ev) {
    if(ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_LEFT) {
        // std::cout << "Apertou Left" << std::endl;
        return true;
    }
    else {
        return false;
    }
}
bool keyRight(SDL_Event ev) {
    if(ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_RIGHT) {
        // std::cout << "Apertou RIGHT" << std::endl;
        return true;
    }
    else {
        return false;
    }
}
bool keyDown(SDL_Event ev) {
    if(ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_DOWN) {
        // std::cout << "Apertou DOWN" << std::endl;
        return true;
    }
    else {
        return false;
    }
}
bool keyUp(SDL_Event ev) {
    if(ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_UP) {
        // std::cout << "Apertou UP" << std::endl;
        return true;
    }
    else {
        return false;
    }
}


#endif