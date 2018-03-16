
void initSplashScreen()
{
  
}
void updateSplashScreen()
{
  if (gb.buttons.pressed(BUTTON_A)) {
    gameState = STATE_IN_GAME;
  }
}
void drawSplashScreen()
{
  gb.display.println("splash screen");
  
}

