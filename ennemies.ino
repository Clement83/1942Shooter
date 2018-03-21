

boolean collideEnnemyAndBullets(Ennemies ennemy) 
{
  for(int i = 0 ; i< NB_PLAYER_BULLET; ++i){
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
  for(int i = 0 ; i< NB_MAX_ENNEMIES; ++i) {
    ennemies[i].life = 1;
    ennemies[i].x = gb.display.width() + random(0,10); //first time we add ennemei randomly
    ennemies[i].y = random(0,gb.display.height());
  }
}

void updateEnnemies()
{
  for(int i = 0 ; i< NB_MAX_ENNEMIES; ++i) {
   if(ennemies[i].life>0) {
    if(collideEnnemyAndBullets(ennemies[i])) {
      --ennemies[i].life; //we die
    }
    //la method attend un pointeur sur ennemy nous envoyons donc le pointeur et non l objet directement
      actionEnnemy(&ennemies[i]);
   }
  }
}

void drawEnnemies()
{
  gb.display.setColor(RED);
  for(int i = 0 ; i< NB_MAX_ENNEMIES; ++i) {
   if(ennemies[i].life>0) {
    gb.display.fillRect( ennemies[i].x , ennemies[i].y , 5 , 5);
   }
  }
}


void actionEnnemy(Ennemies *ennemy)//nous utilison un pointer sur l objet afin de pouvoir modifier ses valeurs dans une fonction séparé
{
   int nextAction = random(0,100);

   if(nextAction < 3) {
    //fire 
    createNewEnnemyBullet(*ennemy); //send value in this method
   } else if(nextAction < 30) {
    --ennemy->x; //on avance
   }
    
}

