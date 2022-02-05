#include "robot.h"
#include "algo.h"
#include "mouvement.h"
#include "detection.h"
#include <stdio.h>

void algo_v1(Robot *robot, int grille[Taille_grille][Taille_grille], int veriteTerrain[Taille_grille][Taille_grille]){
  //scan 4 direction + maj obstacle
  //if(un cote opp == 3m)
  //  on pose limite salle
  //recherche case suivante()
  //while(pas fini){
  //  -deplacement en diagonale
  //  -scan 4 direction + maj obstacle
  //  -recherche case suivante()
  detectionEnLigne(*robot,grille,veriteTerrain); // pour  90°
  turn_left(robot);
  detectionEnLigne(*robot,grille,veriteTerrain); // pour 180°
  turn_left(robot);
  detectionEnLigne(*robot,grille,veriteTerrain); // pour 270°
  turn_left(robot);
  detectionEnLigne(*robot,grille,veriteTerrain); // pour   0°

  showGrille(veriteTerrain,*robot);
  printf("\n");
  showGrille(grille,*robot);

  /*while(i>0){
    move_1_case(robot);
    showGrille(grille,*robot);
    getchar();
    i--;
  }*/

}

void showGrille(int grille[Taille_grille][Taille_grille], Robot robot){
  int x,y;
  for(y=0 ; y < Taille_grille ; y++){
    for(x=0 ; x < Taille_grille ; x++){
      if(robot.posX==x && robot.posY==y){
        setcolor(Red);
        printf("X ");
        setcolor(White);
      }else if(grille[x][y]==1){
        setcolor(Blue);
        printf("%d ",grille[x][y]);
        setcolor(White);
      }else{
        printf("%d ",grille[x][y]);
      }
    }
    printf("\n");
  }
}