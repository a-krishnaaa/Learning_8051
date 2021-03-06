#include<reg51.h>

sbit RD = P2^5;
sbit WR = P2^6;
sbit INTR = P2^7;
sfr MYDATA = P1;

void main()
{
  unsigned char value;
  MYDATA = 0xFF;
  INTR = 1;
  RD = 1;
  WR = 1;
  while(1)
  {
    WR = 0;
    RD = 1;
    while(INTR == 1)
      RD =  0;
    value = MYDATA;
    ConvertAndDisplay (value);
    RD = 1;
  }
}
