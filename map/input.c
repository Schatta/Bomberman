#include "input.h"

//fonction update pour scroll
/*void update(void)
{

  if (input.left == 1)
  {
    map.startX -= TILE_SIZE;

    if (map.startX < 0)
    {
      map.startX = 0;
    }
  }

  else if (input.right == 1)
  {
    map.startX += TILE_SIZE;

    if (map.startX + SCREEN_WIDTH >= map.maxX)
    {
      map.startX = map.maxX - SCREEN_WIDTH;
    }
  }

  if (input.up == 1)
  {
    map.startY -= TILE_SIZE;

    if (map.startY < 0)
    {
      map.startY = 0;
    }
  }

  else if (input.down == 1)
  {
    map.startY += TILE_SIZE;

    if (map.startY + SCREEN_HEIGHT >= map.maxY)
    {
      map.startY = map.maxY - SCREEN_HEIGHT;
    }
  }

}*/

void getInput()
{
  SDL_Event event;

  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {

      case SDL_QUIT:
      exit(0);
      break;

      case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
      {
        case SDLK_ESCAPE:
        exit(0);
        break;

        case SDLK_c:
        input.bomb = 1;
        break;

        case SDLK_LEFT:
        input.left = 1;
        break;

        case SDLK_RIGHT:
        input.right = 1;
        break;

        case SDLK_DOWN:
        input.down = 1;
        break;

        case SDLK_UP:
        input.up = 1;
        break;

        default:
        break;
      }
      break;

      case SDL_KEYUP:
      switch (event.key.keysym.sym)
      {
        case SDLK_c:
        input.bomb = 0;
        break;

        case SDLK_LEFT:
        input.left = 0;
        break;

        case SDLK_RIGHT:
        input.right = 0;
        break;

        case SDLK_DOWN:
        input.down = 0;
        break;

        case SDLK_UP:
        input.up = 0;
        break;

        default:
        break;
      }
      break;

    }

  }
}
