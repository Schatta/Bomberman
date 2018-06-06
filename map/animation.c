#include "animation.h"


void drawanimatedplayer()
{


  if (player.frameTimer <= 0)
  {

    player.frameTimer = TIME_BETWEEN_2_FRAMES;

    player.frameNumber++;

    if(player.frameNumber >= player.sprite->w / PLAYER_WIDTH)
    player.frameNumber = 0;

  }
  else
  player.frameTimer--;
  drawplayer();


}
