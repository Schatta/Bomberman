#include "defs.h"

typedef struct s_input    t_input;
typedef struct s_gestion  t_gestion;
typedef struct s_map      t_map;
typedef struct s_hero     t_hero;

struct s_input{
  int left;
  int right;
  int down;
  int up;
  int bomb;
  int pause;
};

struct s_gestion{
  SDL_Surface *screen;
};

struct s_map{
  SDL_Surface *background;
  SDL_Surface *tileSet;
  int         startX;
  int         startY;
  int         maxX;
  int         maxY;
  int         tile[MAX_MAP_Y][MAX_MAP_X];
};

struct s_hero{
  SDL_Surface *sprite;
  int         x;
  int         y;
  int         frameNumber;
  int         frameTimer;
};
