/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"  
#include "scribbler.h"
#include "s3.h"                    // Include simple tools

int main()                                    // Main function
{
  // Add startup code here.
  s3_setup();
  pause(100);
  
  scribbler_set_speed(15);
  scribbler_here_is(0,0);
  scribbler_move_to(-400, -400);
 
}
