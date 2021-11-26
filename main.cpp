#include <iostream>
#include "game.hpp"
#include "player.hpp"

using namespace std;

int main() {
  Game* DownSystem = new Game();
  DownSystem->runGame();
  delete DownSystem;
} 
