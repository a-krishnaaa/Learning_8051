#include <reg51.h>    

sfr ldata = 0x90;
sbit rs = P2^0;     // Connecting Register Select pin of lcd to P2.0
sbit rw = P2^1;     // Connecting RW pin of lcd to P2.1
sbit en = P2^2;     // Connecting Enable pin of lcd to P2.2

void MSDelay(unsigned int itime)        // delay function to provide some delay after each operation
{
   unsigned int i,j;
   for(i=0;i<itime;i++);
      for(j=0;j<1275;j++);
}

void lcdcmd(unsigned char value)     // function to send command to command register of lcd. to see command of 16*2 lcd please search '16*2 lcd commands" on google
{
   ldata = value;
   rs = 0;
   rw = 0;
   en = 1;
   MSDelay(1);
   en = 0;
   return;
}

void lcddata(unsigned char value)       // function to send data to lcd
{
   ldata = value;
   rs = 1;
   rw = 0;
   en = 1;
   MSDelay(1);
   en = 0;
   return;
}

void main ()
{
   lcdcmd(0x38);           // to set lcd in 2 lines and 5×7 matrix
   MSDelay(250);
   lcdcmd(0x0E);           // to turn on display and blink the cursor
   MSDelay(250);
   lcdcmd(0x01);           // to clear the screen
   MSDelay(250);
   lcdcmd(0x06);           // to Increment cursor (shift cursor to right)
   MSDelay(250);
   lcdcmd(0x86);           //
   MSDelay(250);
   lcddata('I');           // sending character I to lcd via data bus
   MSDelay(250);
   lcddata('L');
   MSDelay(250);
   lcddata('Y');
}
