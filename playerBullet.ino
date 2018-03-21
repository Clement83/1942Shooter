#define VELOCITY_SOLDAT_BULLET 3

int getNextBullet()
{
  for(int i = 0 ; i< NB_PLAYER_BULLET; ++i) {
    if(soldatBullet[i].life == 0) {
      return i;
    }
  }
  return -1;
}

void createNewSoldatBullet()
{
  int index = getNextBullet();

  if(index != -1) {
    soldatBullet[index].life = 1;
    soldatBullet[index].y = soldat.y+2;//todo real pos of gun
    soldatBullet[index].x = 4;
  }
  
}
void initPlayerBullet()
{
  //init state
  for(int i = 0 ; i< NB_PLAYER_BULLET; ++i) {
    soldatBullet[i].life = 0;
  }
}


void updatePlayerBullet()
{
 if(soldat.fire) {
  soldat.fire = false;
   createNewSoldatBullet();
 }
   for(int i = 0 ; i< NB_PLAYER_BULLET; ++i){
    if(soldatBullet[i].life>0) { //if bullet is alive
      if(soldatBullet[i].x > gb.display.width()) { //if bullet is out of screen
        soldatBullet[i].life = 0;
      } else {
        soldatBullet[i].x += VELOCITY_SOLDAT_BULLET;//go bullet go!
      }
    }
  }
}

void drawPlayerBullet()
{
  gb.display.setColor(YELLOW);
   for(int i = 0 ; i< NB_PLAYER_BULLET; ++i) {
     if(soldatBullet[i].life>0) {
        gb.display.fillRect( soldatBullet[i].x , soldatBullet[i].y , 1 , 1);
     }
  }
  
}


