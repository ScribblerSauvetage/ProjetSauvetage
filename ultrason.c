/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "s3.h"
#include "ping.h"


int item;

void main()                                    // Main function
{
  // Add startup code here.
  s3_setup();
  pause(100);
  simpleterm_reopen(31,30,0,9600);
  
  while(1)
  {
    // Add main loop code here.
    item = ping_cm(5);
    print("%3.d", item);
    pause(500);
  }  
}
