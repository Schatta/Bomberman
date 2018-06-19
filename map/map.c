#include "map.h"

void loadMap(char *name)
{
  int x, y;
  FILE *fp;

  fp = fopen(name, "rb");

  if (fp == NULL)
  {
    printf("Failed to open map %s\n", name);
    exit(1);
  }

  map.maxX = map.maxY = 0;

  for (y = 0; y < MAX_MAP_Y; y++)
  {
    for (x = 0; x < MAX_MAP_X; x++)
    {
      fscanf(fp, "%d", &map.tile[y][x]);


      if (map.tile[y][x] > 0)
      {
        if (x > map.maxX)
        {
          map.maxX = x;
        }

        if (y > map.maxY)
        {
          map.maxY = y;
        }
      }
    }
  }


  map.maxX = (map.maxX + 1) * TILE_SIZE;
  map.maxY = (map.maxY + 1) * TILE_SIZE;
  map.startX = map.startY = 0;


  fclose(fp);

}




void drawMap(void)
{
  int x, y, mapX, x1, x2, mapY, y1, y2, xsource, ysource, a;

  /* Ces calculs compliqués serviront à calculer l'affichage de l'écran pendant le scrolling*/

  mapX = map.startX / TILE_SIZE;
  x1 = (map.startX % TILE_SIZE) * -1;
  x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);

  mapY = map.startY / TILE_SIZE;
  y1 = (map.startY % TILE_SIZE) * -1;
  y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);


  mapX = 0;
  x1 = 0;
  x2 = SCREEN_WIDTH;

  mapY = 0;
  y1 = 0;
  y2 = SCREEN_HEIGHT;

  for (y = y1; y < y2; y += TILE_SIZE)
  {
    mapX = map.startX / TILE_SIZE;


    for (x = x1; x < x2; x += TILE_SIZE)
    {
      a = map.tile[mapY][mapX];

      ysource = a / 10 * TILE_SIZE;


      xsource = a % 10 * TILE_SIZE;

      drawTile(map.tileSet, x, y, xsource, ysource);

      mapX++;
    }

    mapY++;
  }
}

void mapCollision(t_hero *entity){
  int i;
  int x1;
  int x2;
  int y1;
  int y2;

  if(entity->h >TILE_SIZE)
  i = TILE_SIZE;
  else
  i = entity->h;

  for(;;){
    x1 = (entity->x + entity->dirX) / TILE_SIZE;
    x2 = (entity->x + entity->dirX + entity->w-1)/TILE_SIZE;
    y1 = (entity->y)/TILE_SIZE;
    y2 = (entity->y+i-1)/TILE_SIZE;

    if(x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y){
      if (entity->dirX > 0){
        if(map.tile[y1][x2] > BLANK_TILE || map.tile[y2][x2] > BLANK_TILE){
          entity->x = x2 * TILE_SIZE;
          entity->x -= entity->w+1;
          entity->dirX = 0;
        }
      }
      else if(entity->dirX < 0){
        if(map.tile[y1][x1] > BLANK_TILE || map.tile[y2][x1] > BLANK_TILE){
          entity->x = (x1 + 1) * TILE_SIZE;
          entity->dirX = 0;
        }
      }
    }
    if(i == entity->h){
      break;
    }

    i += TILE_SIZE;
    if( i> entity->h){
      i = entity->h;
    }
  }

  if(entity->w > TILE_SIZE)
    i = TILE_SIZE;
  else
    i = entity->w;

    for(;;){
      x1 = (entity->x)/TILE_SIZE;
      x2 = (entity->x+i)/TILE_SIZE;
      y1 = (entity->y + entity->dirY)/TILE_SIZE;
      y2 = (entity->y + entity->dirY+entity->h)/TILE_SIZE;

      if(x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y){
        if(entity->dirY > 0){
          if(map.tile[y2][x1] > BLANK_TILE || map.tile[y2][x2] > BLANK_TILE){
            entity->y = y2*TILE_SIZE;
            entity->y -= entity->h;
            entity->dirY = 0;
          }
        }
        else if (entity->dirY < 0){
          if(map.tile[y1][x1] > BLANK_TILE || map.tile[y1][x2] > BLANK_TILE){
            entity->y = (y1 + 1) * TILE_SIZE;
            entity->dirY = 0;
          }
        }
      }

      if(i == entity->w){
        break;
      }

      i += TILE_SIZE;
      if(i>entity->w){
        i = entity->w;
      }

    }
    entity->x += entity->dirX;
    entity->y += entity->dirY;

    if(entity->x < 0){
      entity->x = 0;
    }
    else if(entity->x + entity->w >= map.maxX){
      entity->x = map.maxX - entity->w-1;
    }
  }
