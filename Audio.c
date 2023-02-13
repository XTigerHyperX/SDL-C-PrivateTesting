#include <SDL/SDL_mixer.h>

void InitAudio(){
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT , MIX_DEFAULT_CHANNELS , 2048)==-1){
        printf("Error loading audio");
    }
    Mix_Music *music;
    music = Mix_LoadMUS("Images/music.mp3");
    Mix_PlayMusic(music,-1);
}