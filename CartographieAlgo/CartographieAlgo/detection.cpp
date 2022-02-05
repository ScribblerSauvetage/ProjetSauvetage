#include "robot.h"
int detectionEnLigne(Robot robot, int grille[Taille_grille][Taille_grille], int veriteTerrain[Taille_grille][Taille_grille]){
  int distance=1,vx=0,vy=0,x,y;
  if(robot.orientation==0){
    vx=1;
  }
  switch( robot.orientation ){
    case 0:
      vx=1;
      break;
    case 90:
      vy=-1;
      break;
    case 180:
      vx=-1;
      break;
    case 270:
      vy=1;
      break;
  }
  x = robot.posX+vx;
  y = robot.posY+vy;
  do{
    if(veriteTerrain[x][y]==1){
      grille[x][y] = 1;
      return distance;
    }
    distance++;
    x+=vx;
    y+=vy;
  }while(x>0 && y>0 && x<Taille_grille && y<Taille_grille);
  return -1;
}