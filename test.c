#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDL/SDL.h"

int main()
{

SDL_Surface *ecran = NULL;
SDL_Event event;
int continuer = 1;

SDL_Init(SDL_INIT_VIDEO);


ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);

SDL_WM_SetCaption("coucou gestion ", NULL);

while(continuer){
SDL_WaitEvent(&event);

switch(event.type)
{
	case SDL_KEYDOWN:
	printf("bien joue %C", 'a');
	continuer = 0;
	break;
}
}
return 0;
}
