bool Collision(uint8_t x1, uint8_t y1,uint8_t w1,uint8_t h1, uint8_t x2, uint8_t y2,uint8_t w2,uint8_t h2)
{
   if((x2 >= x1 + w1)      // trop à droite
  || (x2 + w2 <= x1) // trop à gauche
  || (y2 >= y1 + h1) // trop en bas
  || (y2 + h2 <= y1))  // trop en haut
          return false; 
   else
          return true; 
}

