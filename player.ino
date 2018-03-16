
#define SOLDAT_X 3
#define SOLDAT_START_LIFE 100

void initPlayer()
{
  soldat.y = 40;
  soldat.life = SOLDAT_START_LIFE;
  soldat.fire = false;
}

void updatePlayer()
{
  if (gb.buttons.pressed(BUTTON_MENU)) {
    gameState = STATE_GAME_OVER;
  }
  
  if (gb.buttons.repeat(BUTTON_UP,0)) {
    soldat.y--;
  }
  
  if (gb.buttons.repeat(BUTTON_DOWN,0)) {
    soldat.y++;
  }
  
  if (gb.buttons.pressed(BUTTON_A)) {
    soldat.fire = true;
  }
}

void drawPlayer()
{
  gb.display.setColor(GREEN);
  gb.display.fillRect( SOLDAT_X , soldat.y , 5 , 5);
  if(soldat.fire) {
    gb.lights.fill(YELLOW);
  }
}