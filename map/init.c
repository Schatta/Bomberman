#include "init.h"

void init(char  *title){
  if (SDL_Init(SDL_INIT_VIDEO ) < 0)
    {
      printf("Could not initialize SDL: %s\n", SDL_GetError());
      exit(1);
    }

  jeu.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);
  if (jeu.screen == NULL)
    {
      printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
      exit(1);
    }
  SDL_WM_SetCaption(title, NULL);
  SDL_ShowCursor(SDL_DISABLE);

}

void cleanup(){
  SDL_Quit();
}