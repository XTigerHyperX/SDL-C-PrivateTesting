#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "function.h"
void initperso(perso *p)
{
    p->spritesheet=IMG_Load("perso.png");
    p->position.x=00;
    p->position.y=600;
    p->direction=2;
    p->acceleration=0;
    p->vitesse=5;
    p->vitesseV=0;
    p->pos_sprite.x= 0;
    p->pos_sprite.y=200;
    p->pos_sprite.h=100;
    p->pos_sprite.w=100;
   // p->life=3;
    p->score=0;
}
void afficherperso (perso p,SDL_Surface *screen)
{
	SDL_BlitSurface(p.spritesheet,&p.pos_sprite,screen,&p.position);
}
void saut (perso* p)
{
    if (p->position.y==600)
    {
        p->vitesseV=-50;
    }
}
void animerperso (perso* p){
    p->pos_sprite.x += 100;
    if (p->pos_sprite.x >= 1500)
    { 
	p->pos_sprite.x = 0;
    }
    p->pos_sprite.y = p->direction * 100 ;
}


void moveperso (perso *p, Uint32  dt)
{
    double dx;
    dx = 0.5 * p->acceleration * dt *dt + p->vitesse * dt ; 
    if ((p->direction==0))
    {
        p->position.x += dx ;
    }
    else if ((p->direction==1))
    p->position.x -= dx ;
  
}
void InitBG(Image *Backg)
{
    Backg -> img = IMG_Load("background.jpg");
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

void ShowBG(Image I , SDL_Surface *Screen)
{
    SDL_BlitSurface(I.img,NULL,Screen,&I.pos1);
}
void ShowImg(Image I , SDL_Surface *Screen)
{
    SDL_BlitSurface(I.img,&I.pos2,Screen,&I.pos1);
}
void InitImg(Image *imag , int x , int y , char name[])
{
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
void inittext(text *a,int x, int y)
{
a->position.x=x;
a->position.y=y;
a->textcolor.r=0;
a->textcolor.g=0;
a->textcolor.b=0;

a->font = TTF_OpenFont("avocado.ttf",30);
}
void freetext(text a)
{
SDL_FreeSurface(a.surfacetext);
}
void displaytext(text t, SDL_Surface *screen)
{
t.surfacetext=TTF_RenderText_Solid(t.font,"score : ",t.textcolor);
SDL_BlitSurface(t.surfacetext,NULL,screen,&t.position);
}
void displayscore(text t, SDL_Surface *screen,perso p)
{
t.surfacetext=TTF_RenderText_Solid(t.font,"0",t.textcolor);
SDL_BlitSurface(t.surfacetext,NULL,screen,&t.position);
}
