#define POS_BARRICADE_X 10
#define BARRICADE_W 4
#define BARRICADE_H 12

void initBarricade()
{
  int interval = gb.display.height()/ (NB_BARRICADE +1);
  for(int i=0; i<NB_BARRICADE; i++){
    barricades[i].y = interval * (i +1); 
    barricades[i].life = LIFE_BARRICADE; 
  }
}

void updateBarricade()
{
  for(int i=0; i<NB_BARRICADE; i++){
    for(int y = 0 ; y< NB_ENNEMY_BULLET; ++y){
      if(Collision(POS_BARRICADE_X, barricades[i].y, BARRICADE_W, BARRICADE_H, ennemyBullet[y].x, ennemyBullet[y].y, ENNEMIE_W, ENNEMIE_H)){
        --barricades[i].life; 
        ennemyBullet[y].life = 0; 
      }
    }
  }
}

void drawBarricade()
{
  for(int i=0; i<NB_BARRICADE; i++){
   
    if(barricades[i].life == 3) {
      gb.display.setColor(DARKBLUE);
    } else if (barricades[i].life == 2) {
      gb.display.setColor(BLUE);
    } else if (barricades[i].life == 1) {
      gb.display.setColor(YELLOW);
    } else {
       gb.display.setColor(RED);
    }
    gb.display.fillRect(POS_BARRICADE_X ,barricades[i].y, BARRICADE_W, BARRICADE_H);
  }
}

