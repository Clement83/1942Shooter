void initGameOver()
{
  
}

void updateGameOver()
{
  if (gb.buttons.pressed(BUTTON_A)) {
    gameState = STATE_SPASH_SCREEN;
  }
}

void drawGameOver()
{
  gb.display.println("game over");
}

