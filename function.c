#include <SDL/SDL.h>
#include "function.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 800

#define BACKGROUND_ANIMATION_SPEED 400

void animate(SDL_Surface *screen, SDL_Surface **background_frames, int num_frames, int *frame_index, Uint32 current_time, Uint32 *last_frame_time)
{
    int quit = 0;

    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
    {
        quit = 1;
    }

    if (current_time - *last_frame_time >= BACKGROUND_ANIMATION_SPEED)
    {
        *frame_index = (*frame_index + 1);
        *last_frame_time = current_time;
    }
    if (*frame_index >= num_frames)
    {
        *frame_index = 0;
    }

    SDL_BlitSurface(background_frames[*frame_index], NULL, screen, NULL);
    printf("%d\n", *frame_index);
    SDL_Flip(screen);

    // Delay to cap the framerateSDL_Delay(16);
}
void scrolling(Image *b, int direction, int pas)
{
    if (b->pos1.x > b->img->w - SCREEN_WIDTH)
    {
        b->pos1.x = 0;
    }
    else if (b->pos1.x < 0)
    {
        b->pos1.x = b->img->w - SCREEN_HEIGHT;
    }
    if (b->pos1.y > b->img->h - SCREEN_HEIGHT)
    {
        b->pos1.y = 0;
    }
    else if (b->pos1.y < 0)
    {
        b->pos1.y = b->img->h - SCREEN_HEIGHT;
    }
    if (direction == 0)
    {
        b->pos1.x += pas;
        if (b->scroll.x >= b->scroll.w - SCREEN_WIDTH)
            b->scroll.x = (b->scroll.w - SCREEN_WIDTH) / 2;
    }
    else if (direction == 1)
    {
        b->pos1.x -= pas;
        if (b->pos1.x <= 0)
            b->pos1.x = 0;
    }
    else if (direction == 2)
    {
        b->pos1.y = -pas;
    }
    else if (direction == 3)
    {
        b->pos1.y = +pas;
    }
}

void bestScore(char *fileName, scoreInfo t[])
{
    FILE *f = fopen(fileName, "rb");
    if (f == NULL)
    {
        printf("couldn't load file %s.\n", fileName);
        return;
    }
    scoreInfo s;
    int i = 0;
    while (fread(&s, sizeof(scoreInfo), 1, f) == 1 && i < 10)
    {
        t[i] = s;
        i++;
    }
    fclose(f);
    /*
    for (int j = 0; j < i; j++)
    {
        for (int k = j + 1; k < i; k++)
        {
            if (t[k].score > t[j].score)
            {
                scoreInfo temp = t[j];
                t[j] = t[k];
                t[k] = temp;
            }
        }
    }*/
}

void InitBG(Image *Backg, char name[])
{
    Backg->img = IMG_Load(name);
    if (Backg->img == NULL)
    {
        printf("Error loading the image background");
        return;
    }
    Backg->pos1.x = 0;
    Backg->pos1.y = 0;
    Backg->pos2.x = 0;
    Backg->pos2.y = 0;
}
void ShowBG(Image I, SDL_Surface *screen)
{
    SDL_BlitSurface(I.img, NULL, screen, &I.pos1);
}