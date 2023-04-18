#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "function.h"

typedef struct
	{
	SDL_Surface *spritesheet;
	SDL_Rect position;
	SDL_Rect pos_sprite; 
	int direction,vitesseV;;
	char score;
	double vitesse , acceleration;
	}perso;
	
	typedef struct text
{
         SDL_Rect position;
         TTF_Font *font;
         SDL_Surface *surfacetext;
	 SDL_Color textcolor;
	 char texte[20];
}text;

	void initperso(perso *p);
	void afficherperso (perso p,SDL_Surface *screen);
	void moveperso(perso *p,Uint32 dt);
	void animerperso (perso *p);
	void saut (perso *p);
	void ShowImg (Image i , SDL_Surface *Screen);
	void inittext(text *a,int x, int y);
	void freetext(text a);
	void displaytext(text t, SDL_Surface *screen);
	void displayscore(text t, SDL_Surface *screen,perso p);
 #endif

