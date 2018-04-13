#include <Gamebuino-Meta.h>

// all possible game state
#define STATE_SPLASH_SCREEN 0
#define STATE_IN_GAME 1
#define STATE_GAME_OVER 2

//save the curent state
int gameState = 0;
int oldGameState = -1;


struct Ennemies {
  int y;
  int x;
  int life;
  int damage;
  int fire;
  boolean isRun;
};

struct Bullet {
  int y;
  int x;
  int life;
  int damage;
};

struct Player {
  int y;
  int life;
  int fire;
  boolean isRun;
};

Player soldat;

#define NB_PLAYER_BULLET 10
Bullet soldatBullet[NB_PLAYER_BULLET];

#define NB_FRAME_FIRE_ANIM 3
#define NB_ENNEMY_BULLET 10
Bullet ennemyBullet[NB_ENNEMY_BULLET];

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

