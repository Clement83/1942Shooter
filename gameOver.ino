void initGameOver()
{
  //init state
}

void updateGameOver()
{
  //only the state know how he can change this state 
  if (gb.buttons.pressed(BUTTON_A)) { 
    gameState = STATE_SPLASH_SCREEN;
  }
}

void drawGameOver()
{
  gb.display.println("game over"); //Draw state
}

