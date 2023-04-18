#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "function.h"
int main(int argc,char** argv) 
{



TTF_Init();
SDL_Surface *screen;
SDL_Event event;
perso p;
int continuer=1,droite=0,gauche=0,up=0,dir=2;
Uint32 dt, t_prev;
text t,s; 
Image Backg,vie;








screen=SDL_SetVideoMode (1024,768,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_Init(SDL_INIT_VIDEO);
atexit(SDL_Quit);
InitBG(&Backg);
initperso(&p);
InitImg(&vie ,0 , 0, "h3.png");
inittext(&t,5,100);
inittext(&s,125,100);







while (continuer)
{
t_prev=SDL_GetTicks();


while(SDL_PollEvent(&event))
{
    switch (event.type)
    {
    case SDL_QUIT:
        continuer=0;
        break;

    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                droite=1;
                break;
            case SDLK_LEFT:
                gauche=1;
                break;
            case SDLK_UP:
                up=1;
                break;        
        }
    break;

   case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                droite=0;
                dir=2;
                p.vitesse=0;
                break;
            case SDLK_LEFT:
                gauche=0;
                p.vitesse=0;
                dir=3;
                break;
            case SDLK_UP:
                up=0;
                break;        
        }
    break;
    
    }
}



if (droite==1)
{
    p.vitesse=5;
    p.acceleration+=0.5;
    p.direction=0;
}
if (gauche==1)
{
    p.vitesse=5;
    p.acceleration+=0.5;
    p.direction=1;
}
if (up==1)
{
 saut(&p);
}
p.acceleration -=0.3;

if (p.acceleration<0 )
 p.acceleration=0;
if (p.acceleration>4 )
 p.acceleration=4;
SDL_Delay(1.7);
dt = SDL_GetTicks() - t_prev;
   /* if (p.position.x>1024)
	{
		p.position.x=0;
	}
    if (p.position.x<1024)
	{
		p.position.x=0;
	}*/
moveperso(&p,dt);
animerperso(&p);

if ((p.vitesse==0)&&(p.acceleration==0))
{
    p.direction=dir;
}

p.position.y += p.vitesseV;
p.vitesseV += 10; 
if (p.position.y >= 600)
{
    p.vitesseV=0;
    p.position.y=600;
}

/*if (p.position.x=1024)
{
	p.position.x=0;
	
}*/








ShowBG( Backg,screen);
afficherperso(p,screen);
displaytext(t,screen);
displayscore(s,screen, p);
ShowImg(vie,screen);

SDL_Flip(screen);
SDL_Delay(50);





}





SDL_FreeSurface(Backg.img);
SDL_FreeSurface(vie.img);
freetext(t);
}

