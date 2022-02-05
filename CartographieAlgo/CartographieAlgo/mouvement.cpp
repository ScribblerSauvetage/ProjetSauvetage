#include "robot.h"
#include "mouvement.h"

void turn_right(Robot *robot)
{
  //scribbler_turn_by_deg(-90);
  //scribbler_wait_stop();
  robot->orientation-= 90;
  if(robot->orientation<0) { robot->orientation+= 360; }
  robot->orientation = robot->orientation%360;
  //print("%d \n", robot.orientation);
}

void turn_left(Robot *robot)
{
  //scribbler_turn_by_deg(90);
  //scribbler_wait_stop();
  robot->orientation+= 90;
  robot->orientation = robot->orientation%360;
  //print("%d \n", robot.orientation);
} 

void move_1_case(Robot *robot) // fais avancer le robot d'une case
{
  if(robot->orientation == 90)
    {
      //print("move_90");
      robot->posY-=1;
    }
  else if(robot->orientation == 0)
    {
      //print("move_0");
      robot->posX+=1;
    }
  else if(robot->orientation == 180)
    {
      //print("move_180");
      robot->posX-=1;
    }
  else
    {
      //print("move_270");
      robot->posY+=1;
    }
}    