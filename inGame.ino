boolean isEndGame() 
{
   int dead = 0;
  for(int i = 0 ; i< NB_MAX_ENNEMIES; ++i) {
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
  initWorld();
  initBarricade();
}
void updateInGame()
{
  updatePlayer();
  updateEnnemies();
  updatePlayerBullet();
  updateEnnemiesBullet();
  updateWorld();
  updateBarricade();
  if(isEndGame()) {
     gameState = STATE_GAME_OVER; 
  }
}
void drawInGame()
{
  drawWorld();
  drawPlayer();
  drawEnnemies();
  drawBarricade();
  drawPlayerBullet();
  drawEnnemiesBullet();
}

