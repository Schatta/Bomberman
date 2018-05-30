#include "structure.h"

int action(int continuer)
{
	SDL_Event event;
	SDL_WaitEvent(&event);

	switch(event.type)
	{
		case SDL_QUIT:
		continuer = 0;
		break;
		case SDL_KEYDOWN:
		switch(event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
		continuer = 0;
		break;
		case SDLK_UP:
		printf("up \n");
		break;
		case SDLK_DOWN:
		printf("down \n");
		break;
		case SDLK_RIGHT:
		printf("right \n");
		break;
		case SDLK_LEFT:
		printf("left \n");
		break;
		case SDLK_b:
		printf("bombe \n");
		break;
		}
	}
return continuer;
}
