#include "main.h"

int main(int  argc, char *argv[]){
  unsigned int frameLimit = SDL_GetTicks()+16;
  int go;
  init("MainMap");
  loadGame();
  atexit(cleanup);

  go = 1;

  while(go==1){
    getInput();
    //fonction update pour scroll
    //update();
    draw();
    delay(frameLimit);
    frameLimit = SDL_GetTicks()+16;
  }
  exit(0);
}
