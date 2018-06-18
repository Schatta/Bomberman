#include "main.h"

int main(int  argc, char *argv[]){
  unsigned int frameLimit = SDL_GetTicks()+16;
  int go;
  init("MainMap");
  initializePlayer();
  loadGame();
  atexit(cleanup);

  go = 1;

  while(go==1){
    getInput();
    //fonction update pour scroll
    updatePlayer();

    draw();
    delay(frameLimit);
    frameLimit = SDL_GetTicks()+16;
  }
  exit(0);
}
