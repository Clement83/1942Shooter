
void updateEffectBullet()
{
  for(int i=0;i<NB_MAX_EFFECTS_BULLETS; i++){
    effectBullets[i].x -= VITESSE_EFFECTS_BULLETS;
    if(effectBullets[i].x < 0) {
      effectBullets[i].x = random(80,100);
      effectBullets[i].y = random(10,50);
    }
  }
}
void drawEffectBullet()
{
  gb.display.setColor(YELLOW);
  for(int i=0;i<NB_MAX_EFFECTS_BULLETS; i++){
        gb.display.fillRect( effectBullets[i].x , effectBullets[i].y , 4 , 1);
    // gb.display.drawPixel(effectBullets[i].x, effectBullets[i].y, YELLOW);
  }
}

void initEffectBullet()
{
  for(int i=0;i<NB_MAX_EFFECTS_BULLETS; i++){
      effectBullets[i].x = random(80,100);
      effectBullets[i].y = random(10,50);
  }
}


// TODO search angle between user and ennemy to draw the correct mitraill line
void drawMitraille(int xTir, int yTir, int xDest, int yDest)
{
    //for(int8_t i=-1;i<2;i++) {
    //  int8_t taille = random(1,6);
    //  gb.display.drawLine(dist + (i*2), 46, dist + (i*2), 46 - taille);
    //}
    
    //if(gb.frameCount%3==0){
      gb.display.drawLine(xTir, yTir, (xDest + random(-5,5)) , (yDest + random(-5,5)));
    //}
}


void drawCheckedImage(int x, int y, Image image)
{
  gb.display.drawImage(x - cameraX, y- cameraY, image);
}

void drawCheckedBackground(int x, int y, Image image)
{
  //gb.display.drawImage( 0 , gb.display.height(), image, x - cameraX, y - cameraY , gb.display.width() , gb.display.height());
}

void shakeScreen(){
  if(shakeTimeLeft){
    shakeTimeLeft--;
    cameraX += random(-shakeMagnitude,shakeMagnitude+1);
    cameraY += random(-shakeMagnitude,shakeMagnitude+1);
    //byte backlightStep = gb.backlight.backlightMax / 4;
    //gb.backlight.set(gb.backlight.backlightValue-random(0,backlightStep*shake_magnitude));
  }
  else 
  {
    cameraX = 0;
    cameraY = 0;
  }
}

