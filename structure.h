#ifndef H__STRUCTURE__
#define H__STRUCTURE__

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDL/SDL.h"

typedef struct s_client_request t_client_request;
typedef struct s_game t_game;
typedef struct s_player_infos t_player_infos;

struct s_client_request
{
unsigned int magic;
int x_pos;
int y_pos;
int dir;
int command;
int speed;
int checksum;
};

struct s_game
{
// t_player_infos player_infos[MAX_PLAYERS];
// t_map map;
// t_other infos;
};

struct s_player_infos
{
char connected;
char alive;
int x_pos;
int y_pos;
int current_dir;
int current_speed;
int bombs_left;
int bombs_capacity;
int frags;
};

int main();
int action(int continuer);

#endif
