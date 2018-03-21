bool Collision(int x1, int y1,int w1,int h1, int x2, int y2,int w2,int h2)
{
   if((x2 >= x1 + w1)      // trop à droite
  || (x2 + w2 <= x1) // trop à gauche
  || (y2 >= y1 + h1) // trop en bas
  || (y2 + h2 <= y1))  // trop en haut
          return false; 
   else
          return true; 
}

