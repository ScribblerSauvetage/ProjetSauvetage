/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"
#include "scribbler.h"
#include "s3.h" 
#include "ping.h"                      // Include simple tools
#define Taille_grille 31

struct Robot{
  int posX;
  int posY;
  int vitesse; //vitesse entre 0 et 15
  int orientation;
} robot;  

void move_to_point(int x, int y)
{
  int X = (x-robot.posX)*400; //20cm/0.5mm = 400
  int Y = (y-robot.posY)*400;
  scribbler_here_is(0,0);
  scribbler_move_to(X, Y);
  robot.posX=x;
  robot.posY=y; 
} 

void turn_right()
{
  scribbler_turn_by_deg(-90);
  scribbler_wait_stop();
  robot.orientation-= 90;
  robot.orientation = robot.orientation%360;
  print("%d \n", robot.orientation);
}

void turn_left()
{
  scribbler_turn_by_deg(90);
  scribbler_wait_stop();
  robot.orientation+= 90;
  robot.orientation = robot.orientation%360;
  print("%d \n", robot.orientation);
} 

void move_1_case() // fais avancer le robot d'une case
{
  if(robot.orientation == 90)
    {
      print("move_90");
      move_to_point(robot.posX, robot.posY+1);
    }
  else if(robot.orientation == 0)
    {
      print("move_0");
      move_to_point(robot.posX+1, robot.posY);
    }
  else if(robot.orientation == 180)
    {
      print("move_180");
      move_to_point(robot.posX-1, robot.posY);
    }
  else
    {
      print("move_270");
      move_to_point(robot.posX, robot.posY-1);
    }
}    

void step_hand_right()
{
  int dist;
  turn_right();
  pause(100);
  dist=ping_cm(5);
  //print("%3.d", dist);
  if(dist>30)
  {
    //turn_left();
    move_1_case();                          
  }
  else
  {
    turn_left();
    pause(100);
    dist=ping_cm(5);
    //print("%3.d", dist);
    if(dist>30)
    {
      //print("on veut avancer\n");
      move_1_case();                          
    }
    else
    {
      turn_left();
      pause(100);
      dist=ping_cm(5);
      //print("%3.d", dist);
      if(dist>30)
      {
        move_1_case();                          
      }
    }        
  }              
}
int main()                                    // Main function
{
  // Add startup code here.
  int grille[Taille_grille][Taille_grille];
  
  //***********init grille************//
  for(int i=0; i<Taille_grille; i++)
  {
    for(int j=0; j<Taille_grille; j++)
    {
      grille[i][j] = 0;     //0 : pas d'obstacle, 1 : obstacle
    }
  }
  //*******************************//  
        
  s3_setup();
  pause(100);
  
  robot.posX = 0;
  robot.posY = 0;
  robot.orientation = 90;
  scribbler_set_speed(15);
  //int item;
  /*while(1)
  {
    // Add main loop code here.
    item = ping_cm(5);
    print("%3.d", item);
    pause(100);
  }*/
  while (1)
  {
    step_hand_right();
  }       
     
}

 