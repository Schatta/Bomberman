#include "player.h"


void initializePlayer(void)
{

  player.sprite = loadImage("walkright.png");

  player.x = 20;
  player.y = 304;

}

void drawplayer()
{
  SDL_Rect dest;

  dest.x = player.x - map.startX;
  dest.y = player.y - map.startY;
  dest.w = PLAYER_WIDTH;
  dest.h = PLAYER_HEIGTH;

  SDL_Rect src;

  src.x = player.frameNumber * PLAYER_WIDTH;
  src.y = 0;
  src.w = PLAYER_WIDTH;
  src.h = PLAYER_HEIGTH;

  SDL_BlitSurface(player.sprite, &src, jeu.screen, &dest);

}
