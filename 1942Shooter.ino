#include <Gamebuino-Meta.h>

// all possible game state
#define STATE_SPLASH_SCREEN 0
#define STATE_IN_GAME 1
#define STATE_GAME_OVER 2

//save the curent state
uint8_t gameState = 0;
uint8_t oldGameState = -1;


struct Ennemies {
  uint8_t y;
  uint8_t x;
  uint8_t life;
  uint8_t damage;
};

struct Bullet {
  uint8_t y;
  uint8_t x;
  uint8_t life;
  uint8_t damage;
};

struct Player {
  uint8_t y;
  uint8_t life;
  boolean fire;
};

Player soldat;

#define NB_PLAYER_BULLET 10
Bullet soldatBullet[NB_PLAYER_BULLET];

#define NB_MAX_ENNEMIES 10
Ennemies ennemies[NB_MAX_ENNEMIES];

boolean testGameStateChange() 
{
  boolean returnValue = (gameState != oldGameState);
  oldGameState = gameState;
  return returnValue;
}

void setup() {
  gb.begin();
  gameState = STATE_SPLASH_SCREEN;
  oldGameState = -1; //first time oldGameState != gameState
}

void loop() {
  while (!gb.update()); //only one time in the programe
  gb.display.clear();
  gb.lights.clear();

// switch for manage state
  switch(gameState)
  {
    case STATE_SPLASH_SCREEN:
    if(testGameStateChange()) { //if state change init the state
      initSplashScreen();
    }
    updateSplashScreen(); //update state
    drawSplashScreen(); // draw state
    
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

