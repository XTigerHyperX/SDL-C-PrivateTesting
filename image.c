#include <SDL/SDL.h>
#include "image.h"
#include <SDL/SDL_image.h>

void InitImg(Image *imag , int x , int y , char name[]){
    imag -> img = IMG_Load(name);
    
    if (imag -> img == NULL){
        printf("Error loading the image background");
        return;
    }
    imag-> pos1.x= x;
    imag-> pos1.y= y;
    imag-> pos1.w=imag->img->w;
    imag-> pos1.h= imag->img->h;

    imag-> pos2.x= 0;
    imag-> pos2.y= 0;
    imag-> pos2.w=imag->img->w;
    imag-> pos2.h= imag->img->h;
}

void InitBG(Image *Backg){
    Backg -> img = IMG_Load("mm.jpg");
    if (Backg -> img == NULL){
        printf("Error loading the image background");
        return;
    }
    Backg-> pos1.x=0;
    Backg-> pos1.y=0;
    Backg-> pos2.x=0;
    Backg-> pos2.y=0;

    Backg->pos2.w = 0;
    Backg->pos2.w = 0;
}

void ShowImg(Image I , SDL_Surface *Screen){
    SDL_BlitSurface(I.img,&I.pos2,Screen,&I.pos1);
}