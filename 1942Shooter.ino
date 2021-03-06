#include <Gamebuino-Meta.h>

// all possible game state
#define STATE_SPLASH_SCREEN 0
#define STATE_IN_GAME 1
#define STATE_GAME_OVER 2

//Shake the screen Rodot Code
byte shakeMagnitude;
byte shakeTimeLeft;
int cameraX = 0;
int cameraY = 0;

//save the curent state
int gameState = 0;
int oldGameState = -1;

#define ENNEMIE_W 5
#define ENNEMIE_H 5
struct Ennemies {
  int y;
  int x;
  int destX;
  int life;
  int damage;
  int fire;
  boolean isRun;
  int cadence = 12;
  int cptCadence = 0;
  int vx = 1;
};

struct Barricade {
  int y;
  int life;
};

struct Player {
  int x;
  int y;
  int life;
  int fire;
  boolean isRun;
};

Player soldat;

#define NB_BARRICADE 3
#define LIFE_BARRICADE 5
Barricade barricades[NB_BARRICADE];

#define NB_FRAME_FIRE_ANIM 3

#define NB_MAX_ENNEMIES 4
Ennemies ennemies[NB_MAX_ENNEMIES];

// effet de balle au dessus du monde
#define VITESSE_EFFECTS_BULLETS 15
struct EffectBullets {
  int x;
  int y;
};
#define NB_MAX_EFFECTS_BULLETS 4
EffectBullets effectBullets[NB_MAX_EFFECTS_BULLETS];

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
  shakeScreen();
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

