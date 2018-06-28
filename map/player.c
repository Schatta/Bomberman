#include "player.h"


void initializePlayer(void)
{

  player.sprite = loadImage("walkright.png");
  player.direction = RIGHT;
  player.etat = WALK;
  player.frameNumber = 0;
  player.frameTimer = TIME_BETWEEN_2_FRAMES;

  player.x = 0;
  player.y = 0;
  player.w = PLAYER_WIDTH;
  player.h = PLAYER_HEIGTH;

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

void updatePlayer(void)
{

  player.dirX = 0;
  if (input.left == 1)
  {
    player.x -= PLAYER_SPEED;

    if (player.x < 0)
    {
      player.x = 0;
    }
    if(player.direction == RIGHT)
    {
      player.direction = LEFT;
      player.sprite = loadImage("walkleft.png");
    }
  }


  else if (input.right == 1)
  {
    player.x += PLAYER_SPEED;

    if (player.x + PLAYER_WIDTH >= map.maxX)
    {
      player.x = map.maxX - PLAYER_WIDTH;;
    }
    if(player.direction == LEFT)
    {
      player.direction =  RIGHT;
      player.sprite = loadImage("walkright.png");
    }
  }

else if (input.up == 1)
  {
    player.y -= PLAYER_SPEED;

    if (player.y < 0)
    {
      player.y = 0;
    }
    if(player.direction == LEFT)
    {
      player.direction =  RIGHT;
      player.sprite = loadImage("walkright.png");
    }
  }



else if (input.down == 1)
  {
    player.y += PLAYER_SPEED;

    if (player.y + PLAYER_WIDTH > map.maxY)
    {
      player.y = map.maxY - PLAYER_WIDTH*2;
    }
    if(player.direction == LEFT)
    {
      player.direction =  RIGHT;
      player.sprite = loadImage("walkright.png");
    }
  }

  mapCollision(&player);
  centerScrollingOnPlayer();

}

void centerScrollingOnPlayer(void)
{
  map.startX = player.x - (SCREEN_WIDTH / 2);

  if (map.startX < 0)
  {
    map.startX = 0;
  }

  else if (map.startX + SCREEN_WIDTH >= map.maxX)
  {
    map.startX = map.maxX - SCREEN_WIDTH;
  }

  map.startY = player.y - (SCREEN_HEIGHT / 2);

  if (map.startY < 0)
  {
    map.startY = 0;
  }

  else if (map.startY + SCREEN_HEIGHT >= map.maxY)
  {
    map.startY = map.maxY - SCREEN_HEIGHT;
  }
}
