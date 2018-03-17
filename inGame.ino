boolean isEndGame() 
{
   uint8_t dead = 0;
  for(uint8_t i = 0 ; i< NB_MAX_ENNEMIES; ++i) {
   if(ennemies[i].life>0) {
    if(ennemies[i].x< 2) {
      return true;
    }
   } else {
    ++dead;
   }
  }
  if(dead>=NB_MAX_ENNEMIES) {
    return true;
  }
  return false;
}

void initInGame()
{
  initPlayer();
  initEnnemies();
  initPlayerBullet();
}
void updateInGame()
{
  updatePlayer();
  updateEnnemies();
  updatePlayerBullet();
  if(isEndGame()) {
     gameState = STATE_GAME_OVER; 
  }

  
}
void drawInGame()
{
  drawPlayer();
  drawEnnemies();
  drawPlayerBullet();
}

