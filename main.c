#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#include "image.h"

int main(int argc, char **argv[]){
    SDL_Surface *Screen =NULL;
    SDL_Surface *menu =NULL;
    int done =1;
    Image Backg , Play , Options , Exit;

    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);

    Screen = SDL_SetVideoMode(1100,600,32 ,SDL_HWSURFACE | SDL_DOUBLEBUF);

    InitBG(&Backg);
    ShowImg(Backg,Screen);    

    InitImg(&Play , 400 , 50 , "Images/Play1.png");
    ShowImg(Play,Screen); 

    InitImg(&Options , 400 , 200, "Images/Options1.png");
    ShowImg(Options,Screen); 

    InitImg(&Exit , 400 , 350, "Images/Exit1.png");
    ShowImg(Exit,Screen); 
    
    InitAudio();

    SDL_Flip(Screen); 
    SDL_PollEvent(&event);
    while (SDL_WaitEvent(&event))
    {
        if(event.type == SDL_MOUSEMOTION){
            int x = event.motion.x;
            int y = event.motion.y;

            if (x >= Play.pos1.x && x <= Play.pos1.x + Play.img->w && y >= Play.pos1.y && y<= Play.pos1.y + Play.img->h){
                InitImg(&Play , 400 , 50 , "Images/Play.png");
                ShowImg(Play,Screen); 
            }
            else {
                InitImg(&Play , 400 , 50 , "Images/Play1.png");
                ShowImg(Play,Screen); 
            }

            if (x >= Options.pos1.x && x <= Options.pos1.x + Options.img->w && y >= Options.pos1.y && y<= Options.pos1.y + Options.img->h){
                InitImg(&Options , 400 , 200 , "Images/Options.png");
                ShowImg(Options,Screen); 
            }
            else {
                InitImg(&Options , 400 , 200 , "Images/Options1.png");
                ShowImg(Options,Screen); 
            }

            if (x >= Exit.pos1.x && x <= Exit.pos1.x + Exit.img->w && y >= Exit.pos1.y && y<= Exit.pos1.y + Exit.img->h){
                InitImg(&Exit , 400 , 350 , "Images/Exit.png");
                ShowImg(Exit,Screen); 
            }
            else {
                InitImg(&Exit , 400 , 350 , "Images/Exit1.png");
                ShowImg(Exit,Screen); 
            }
            SDL_UpdateRect(Screen,0,0,0,0);
        }
        if (event.type == SDL_MOUSEBUTTONUP){
            int x = event.motion.x;
            int y = event.motion.y;
            if (x >= Exit.pos1.x && x <= Exit.pos1.x + Exit.img->w && y >= Exit.pos1.y && y<= Exit.pos1.y + Exit.img->h){
                SDL_Quit();
            }
        }

        if(event.type == SDL_QUIT){
            break;
        }

    }
        SDL_FreeSurface(Backg.img);
        SDL_FreeSurface(Play.img);
        SDL_Quit();



    return 0;
}