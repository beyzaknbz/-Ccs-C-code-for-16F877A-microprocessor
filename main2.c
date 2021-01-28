#include <16f877A.h>
int i=0,m1=0,m0=0,m2=0,m3=0,m4=0,saniye1=0,saniye2=0,saniye3=0,saniye4=0;
int d1[]={18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,37,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18};
int d2[]={18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,37,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18};
int d3[]={18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,37,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18};
int d4[]={18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,37,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18};
#INT_TIMER1
void  TIMER1_isr(void) 
{
set_timer1(45117);
if(m1==10)
{
saniye1++;
m1=0;
if(saniye1==37)
{
saniye1=1;
}
}
if(m2==20)
{
saniye2++;
m2=0;
if(saniye2==37)
{
saniye2=1;
}
}
if(m3==30)
{
saniye3++;
m3=0;
if(saniye3==37)
{
saniye3=1;
}
}
if(m4==40){
saniye4++;
m4=0;
if(saniye4==37){
saniye4=1;
}
}
m1++;
m2++;
m3++;
m4++;
}

#INT_TIMER0
void  TIMER0_isr(void) 
{
set_timer0(138);
if(m0<=d1[saniye1])
{
output_high(PIN_B0);
}
else
output_low(PIN_B0);
if(m0<=d2[saniye2])
{
output_high(PIN_B1);
}
else
output_low(PIN_B1);

if(m0<=d3[saniye3])
{
output_high(PIN_B2);
}
else
output_low(PIN_B2);
if(m0<=d4[saniye4])
{
output_high(PIN_B3);
}
else
output_low(PIN_B3);
if(m0==40)
m0=0;
m0++;
}

void main()
{
 setup_timer_0(RTCC_INTERNAL|RTCC_DIV_2|RTCC_8_bit);      
setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);      
enable_interrupts(INT_TIMER1);
enable_interrupts(INT_TIMER0);
enable_interrupts(GLOBAL);
set_timer1(45117);
set_timer0(138);

while(TRUE)
{
}
}


