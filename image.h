#ifndef Image_H
#define Image_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

struct Image{
    SDL_Rect pos1;
    SDL_Rect pos2;
    SDL_Surface *img;
};

typedef struct Image Image;

void InitBG (Image *Backg);
void InitImg(Image * imag, int x, int y , char name[]);
void ShowImg (Image i , SDL_Surface *Screen);
void ShowBG (Image i , SDL_Surface *Screen);
void InitAudio ();

#endif