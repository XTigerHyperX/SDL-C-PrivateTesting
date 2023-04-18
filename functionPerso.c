#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "functionPerso.h"


void initperso(perso *p)
{
    p->spritesheet=IMG_Load("Perso/perso.png");
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

void inittext(text *a,int x, int y)
{
a->position.x=x;
a->position.y=y;
a->textcolor.r=0;
a->textcolor.g=0;
a->textcolor.b=0;

a->font = TTF_OpenFont("Perso/avocado.ttf",30);
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
