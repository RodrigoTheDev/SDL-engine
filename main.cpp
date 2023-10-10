#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "gameobject.hpp"
#include "render.hpp"
#include "eventos_teclado.hpp"

#define WSCREEN 640
#define HSCREEN 448

using namespace std;


//instanciando os objetos
GameObject bloco = GameObject("block.bmp",0,0);




int main(int argc, char *argv[]) {
    int ymove=0;
    int xmove=0;


    SDL_Window *window = nullptr; //instanciando a janela
    SDL_Renderer *renderTarget = nullptr; //alvo renderer da textura

    // cria a janela
    window = SDL_CreateWindow("tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WSCREEN, HSCREEN, SDL_WINDOW_SHOWN); //cria a janela propriamente dita
    renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); //cria o renderer para a janela



    //eventos e variáveis
    bool isRunning = true;
    SDL_Event ev;

    //loop principal do jogo
    while(isRunning) {
        // int ymove=keyDown - keyUp;


        while(SDL_PollEvent(&ev) != 0) {
            //saindo do programa
            if(ev.type == SDL_QUIT) {
                isRunning = false;
            }


             ymove = keyDown(ev) - keyUp(ev);
             xmove = keyRight(ev) - keyLeft(ev);

            cout << bloco.dstRect.x << endl;
            cout << bloco.dstRect.y << endl;
            
            if(bloco.dstRect.x == WSCREEN-64 && keyRight(ev)) {
                xmove = 0;
            }
            if(bloco.dstRect.x == 0 && keyLeft(ev)) {
                xmove = 0;
            }
            if(bloco.dstRect.y == 0 && keyUp(ev)) {
                ymove = 0;
            }
            if(bloco.dstRect.y == HSCREEN-64 && keyDown(ev)) {
                ymove = 0;
            }

            bloco.dstRect.y += bloco.moveSpeed * ymove;
            bloco.dstRect.x += bloco.moveSpeed * xmove;


        }
        SDL_RenderClear(renderTarget);

        drawObject(bloco,renderTarget);

        SDL_RenderPresent(renderTarget);

    }

    SDL_DestroyRenderer(renderTarget);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}