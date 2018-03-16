
void initInGame()
{
  
}
void updateInGame()
{
  if (gb.buttons.pressed(BUTTON_A)) {
    gameState = STATE_GAME_OVER;
  }
}
void drawInGame()
{
  gb.display.println("in game");
}

