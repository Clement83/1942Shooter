#include <Gamebuino-Meta.h>

#define STATE_SPASH_SCREEN 0
#define STATE_IN_GAME 1
#define STATE_GAME_OVER 2

uint8_t gameState = 0;
uint8_t oldGameState = 0;

boolean testGameStateChange() 
{
  boolean returnValue = (gameState != oldGameState);
  oldGameState = gameState;
  return returnValue;
}

void setup() {
  gb.begin();
  gameState = STATE_SPASH_SCREEN;
  oldGameState = -1;
}

void loop() {
  while (!gb.update());
  gb.display.clear();

  switch(gameState)
  {
    case STATE_SPASH_SCREEN:
    if(testGameStateChange()) {
      initSplashScreen();
    }
    updateSplashScreen();
    drawSplashScreen();
    
    break;
    case STATE_IN_GAME:
    if(testGameStateChange()) {
      initInGame();
    }
    updateInGame();
    drawInGame();
    
    break;
    case STATE_GAME_OVER:
    if(testGameStateChange()) {
      initGameOver();
    }
    updateGameOver();
    drawGameOver();
    break;
  }
}

