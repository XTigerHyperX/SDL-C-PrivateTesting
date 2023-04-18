#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


typedef struct {
    SDL_Rect pos1;
    SDL_Rect pos2;
    SDL_Rect scroll;
    SDL_Surface *img;
}Image;

typedef struct {
    char player_name[50];
    int score;
}scoreInfo;

void animate(SDL_Surface* screen, SDL_Surface** background_frames, int num_frames , int *frame_index, Uint32 current_time, Uint32 *last_frame_time);
void ShowBG (Image i , SDL_Surface *Screen);
void InitBG (Image *Backg , char name[]);
void scrolling (Image * b, int direction, int pas);
void InitImg(Image *imag , int x , int y , char name[]);