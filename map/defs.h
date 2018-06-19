#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDL/SDL.h"

#define SCREEN_WIDTH 635
#define SCREEN_HEIGHT 635

#define TRANS_R 255
#define TRANS_G 0
#define TRANS_B 255

#define MAX_MAP_X 20
#define MAX_MAP_Y 20

#define TILE_SIZE 32

#define PLAYER_WIDTH 40
#define PLAYER_HEIGTH 80

#define TIME_BETWEEN_2_FRAMES 8

#define PLAYER_SPEED 4
#define WALK 1
#define IDLE 2
#define JUMP 3
#define RIGHT 1
#define LEFT 2

#define BLANK_TILE 5
