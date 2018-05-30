#include "structure.h"

int main()
{

SDL_Surface *ecran = NULL;
int continuer = 1;

SDL_Init(SDL_INIT_VIDEO);


ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);

SDL_WM_SetCaption("coucou gestion ", NULL);

while(continuer){
continuer = action(continuer);
}
return 0;
}
