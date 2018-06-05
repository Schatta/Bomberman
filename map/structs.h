#include "defs.h"

typedef struct s_input    t_input;
typedef struct s_gestion  t_gestion;

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
