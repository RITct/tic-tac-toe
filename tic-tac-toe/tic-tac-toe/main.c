//
//  main.c
//  tic-tac-toe
//
//  Created by Sherin Ann Thomas on 15/06/17.
//  Copyright © 2017 Sherin Ann Thomas. All rights reserved.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include "interface.h"
#include "game.h"



#define true 1
#define false 0

const int WIDTH=750,HEIGHT=750;

int quit=false;



int main(int argc, const char * argv[]) {
    
    
    SDL_Surface* xSurface=NULL;
    SDL_Surface* circleSurface=NULL;
   // SDL_Surface* playSurface= NULL;
    SDL_Surface* windowSurface =NULL;
   // SDL_Surface* quitSurface= NULL;
    //SDL_Surface* headSurface= NULL;
    SDL_Surface* boardSurface= NULL;
    
    /*SDL_Rect DestPlay;
    
    DestPlay.x = 750;
    DestPlay.y = 300;

    
    
    SDL_Rect DestQuit;
    
    DestQuit.x = 750;
    DestQuit.y = 500;
    
    SDL_Rect DestHead;
    
    DestHead.x = 5;
    DestHead.y = 10;
    DestHead.w = 100;
    DestHead.h = 100;*/

    
    
    SDL_Rect DestBoard;
    
    DestBoard.x = 0;
    DestBoard.y = 0;
    //DestBoard.w = 300;
    //DestBoard.h=400;
    
    
   // SDL_Rect Destnew;
    
    //DestBoard.x = 10;
    //DestBoard.y = 10;
    
    
    SDL_Rect DestCircle;
    DestCircle.x=0;
    DestCircle.y=0;
    
    
    SDL_Rect DestX;
    DestX.x=250;
    DestX.y=0;
    
    if( SDL_Init(SDL_INIT_EVERYTHING)<0){
        printf("error %s",SDL_GetError());
    }
    
    SDL_Window *window= SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    
    windowSurface= SDL_GetWindowSurface(window);
    
    if(NULL==window){
        printf("error %s",SDL_GetError());
        return EXIT_FAILURE;
    }
    
    SDL_Event windowEvent;
    
    
    
    //headSurface=initialise("tictactoe.bmp");
    
    boardSurface=initialise("board.bmp");
    
    //playSurface=initialise("play.bmp");
    
    //quitSurface=initialise("quit.bmp");
    
    circleSurface=initialise("c15.bmp");
    
    xSurface=initialise("x3.bmp");
    
    
    
    while (1) {
        
        SDL_FillRect( windowSurface, NULL, SDL_MapRGB( windowSurface->format, 0x66, 0x66, 0x99) );
        
        if(SDL_PollEvent(& windowEvent)){
            
            if(SDL_QUIT==windowEvent.type){
                break;
            }
        
        }
        
        
        SDL_BlitScaled(circleSurface,NULL,boardSurface,&DestCircle);
        
        //SDL_BlitSurface(headSurface,NULL,windowSurface,&DestHead);
        
        
        //SDL_BlitSurface(playSurface,NULL,windowSurface,&DestPlay);
        
        
        //SDL_BlitSurface(quitSurface,NULL,windowSurface,&DestQuit);
        
        SDL_BlitSurface(circleSurface,NULL,boardSurface,&DestCircle);
        
        
        SDL_BlitSurface(boardSurface,NULL,windowSurface,&DestBoard);
        
        
        SDL_BlitSurface(xSurface,NULL,boardSurface,&DestX);
        
        int x,y;
        SDL_UpdateWindowSurface(window);
        
        if(SDL_MOUSEBUTTONDOWN && SDL_GetMouseState(&x,&y)){
            if(x>0&& y>0){
                main_sec();
            }
        }
        

    }
    
    //SDL_FreeSurface(headSurface);
    //SDL_FreeSurface(playSurface);
    SDL_FreeSurface(windowSurface);
    //SDL_FreeSurface(quitSurface);
    SDL_FreeSurface(boardSurface);
    SDL_FreeSurface(circleSurface);
    SDL_FreeSurface(xSurface);
    
    //playSurface=NULL;
    windowSurface=NULL;
    //quitSurface=NULL;
    //headSurface=NULL;
    boardSurface=NULL;
    circleSurface=NULL;
    xSurface=NULL;
    
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;

    }
