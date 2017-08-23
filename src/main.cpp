#include "FBG_Platform.h"
#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include <string>

int main(int argc, char** argv) {

  if (argc < 2) {
    exit(1);
  }

  Game oGame;

  std::string my_app_id("313416692430467");
  // Set app id here
  //if (oGame.init("523164037733626") != 0)
  if (oGame.init(my_app_id.c_str()))
  {
    fprintf(stderr, "Could not initialize Gameroom Platform\n");
    return 1;
  }
  oGame.gameLoop();
  return 0;
}
