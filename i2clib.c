/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "s3.h"
#include "simplei2c.h"
#include "simpletext.h"
#include "simpletools.h"
#include <math.h>

#define PinSDA 3
#define PinSCL 5

typedef unsigned char uchar;

void dly()
{
  ;  
}  

void start_i2c ()
{
  high(PinSDA);
  dly();
  high(PinSCL);
  dly();
  low(PinSDA);
  dly();
  low(PinSCL);
  dly();
}

void stop_i2c ()
{
  low(PinSDA);
  dly();
  high(PinSCL);
  dly();
  high(PinSDA);
  dly();
}

int Tx_i2c(char dat){
  for(int i = 0 ; i < 8 ; i++){
     (dat & 0x80 ) ? high(PinSDA) : low(PinSDA);
     dat <<=1;
     dly();
     high(PinSCL);
     dly();
     low(PinSCL);
     dly(); 
  }    
  high(PinSDA);
  high(PinSCL);
  dly();
  int ack = !input(PinSDA);
  low(PinSCL);
  return ack;
}  

char Rx_i2c(int ack){
  char dat=0;
  high(PinSDA);
  for(int i = 0 ; i < 8 ; i++){
    dat <<= 1;
    do{
      
    }while(input(PinSCL) == 0);
    dly();
    if(input(PinSDA)) dat |=1 ;
    dly();
    low(PinSCL);     
  }    
  ack ? low(PinSDA) : high(PinSDA);
  high(PinSCL);
  dly();
  low(PinSCL);
  high(PinSDA);
  
  return dat;
}

int i2c_write(char devAddr, char* data_write, int nb_char)
{
  start_i2c();
  if(!Tx_i2c(devAddr)){}// return 0;
  for (int i=0; i<nb_char; i++)
  {
    if(!Tx_i2c(data_write[i])) {}//return 0;
  } 
  stop_i2c();
  return 1;    
}

void i2c_read(char devAddr, char* read_data, int nb_char)
{
  start_i2c();
  int i = Tx_i2c(devAddr|=1);
  for(int i=0; i<nb_char-1; i++)
  {
    read_data[i] = Rx_i2c(0);
  }
  read_data[i] = Rx_i2c(1);
  stop_i2c();  
  return; 
}   

unsigned int readRegister16 (unsigned int regaddr)
{
  unsigned int data;
  uchar data_low;
  uchar data_high;
  
  char data_write[2];
  char data_read[2];
  
  data_write[0] = (regaddr >> 8) & 0xFF;
  data_write[1] = regaddr & 0xFF;
  
  int i = i2c_write(0x52, data_write, 2);
  i2c_read(0x52, data_read, 2);
  
  data_high = data_read[0];
  data_low = data_read[1];
  data = (data_high <<8) | data_low;
  return data;
  
}    

int main()                                    // Main function
{
  // Add startup code here.
  while(1)
  {
    char data[2];
    int i = readRegister16(0x010F);
    print("%.4x \n", i);
    
    pause(1000);
  }
      
  
  return 0;    
}