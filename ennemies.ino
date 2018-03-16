

boolean collideEnnemyAndBullets(Ennemies ennemy) 
{
  for(uint8_t i = 0 ; i< NB_PLAYER_BULLET; ++i){
    if(soldatBullet[i].life>0) {
      if(Collision(soldatBullet[i].x, soldatBullet[i].y, 2, 2, ennemy.x, ennemy.y, 5, 5)) {
        soldatBullet[i].life = 0;
        return true;
      }
    }
  }
  return false;
}

void initEnnemies()
{
   //init state
  for(uint8_t i = 0 ; i< NB_MAX_ENNEMIES; ++i) {
    ennemies[i].life = 3;
    ennemies[i].x = gb.display.width() + random(0,10); //first time we add ennemei randomly
    ennemies[i].y = random(0,gb.display.height());
  }
}

void updateEnnemies()
{
  uint8_t dead = 0;
  for(uint8_t i = 0 ; i< NB_MAX_ENNEMIES; ++i) {
   if(ennemies[i].life>0) {
    if(collideEnnemyAndBullets(ennemies[i])) {
      --ennemies[i].life; //we die
    }
    --ennemies[i].x; //on avance
    if(ennemies[i].x< 2) {
      gameState = STATE_GAME_OVER; 
    }
   } else {
    ++dead;
   }
  }

  if(dead>=NB_MAX_ENNEMIES) {
    gameState = STATE_GAME_OVER;
  }
}

void drawEnnemies()
{
  gb.display.setColor(RED);
  for(uint8_t i = 0 ; i< NB_MAX_ENNEMIES; ++i) {
   if(ennemies[i].life>0) {
    gb.display.fillRect( ennemies[i].x , ennemies[i].y , 5 , 5);
   }
  }
}
