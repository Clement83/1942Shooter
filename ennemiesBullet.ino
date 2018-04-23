#define VELOCITY_ENNEMY_BULLET 4

//TODO this method is same as player bullet
int getNextEnnemyBullet()
{
  for(int i = 0 ; i< NB_ENNEMY_BULLET; ++i) {
    if(ennemyBullet[i].life == 0) {
      return i;
    }
  }
  return -1;
}

void createNewEnnemyBullet(Ennemies ennemy)
{
  int index = getNextEnnemyBullet();

  if(index != -1) {
    ennemyBullet[index].life = 1;
    ennemyBullet[index].y = ennemy.y+2;//todo real pos of gun
    ennemyBullet[index].x = ennemy.x;
  }
  
}

//TODO duplicqted method
void initEnnemiesBullet()
{
  //init state
  for(int i = 0 ; i< NB_ENNEMY_BULLET; ++i) {
    ennemyBullet[i].life = 0;
  }
}


void updateEnnemiesBullet()
{
   for(int i = 0 ; i< NB_ENNEMY_BULLET; ++i){
    if(ennemyBullet[i].life>0) { //if bullet is alive
      if(ennemyBullet[i].x < 0) { //if bullet is out of screen
        ennemyBullet[i].life = 0;
      } else {
        ennemyBullet[i].x -= VELOCITY_ENNEMY_BULLET;//go bullet go!
      }
    }
  }
}

void drawEnnemiesBullet()
{
  gb.display.setColor(RED);
   for(int i = 0 ; i< NB_ENNEMY_BULLET; ++i) {
     if(ennemyBullet[i].life>0) {
        gb.display.fillRect( ennemyBullet[i].x , ennemyBullet[i].y , 1 , 1);
     }
  }
  
}
