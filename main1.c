#include <16F877A.h> 
#use delay(clock=4000000)
int16 dizi[13]={124,121,110,75,119,0,117,119,55,124,63,75,0};
int16 i=0,a1=0,a2,a3,a4,sayac=0;
#int_TIMER0
void  TIMER0_isr(void) 
{
   set_timer0(217);
   a2=a1+1; 
   if(a2==13)
   a2=0;
   a3=a2+1;
   if(a3==13)
   a3=0;
   a4=a3+1;
   if(a4==13)
   a4=0;
   if(i==0)
   {output_low(pin_d1);
   output_low(pin_d2);
   output_low(pin_d3);
   output_low(pin_d4);
   output_low(pin_d5);
   output_b(dizi[a1]);
   output_high(pin_d0);
   }
   if(i==1)
   {
   output_low(pin_d0);
   output_low(pin_d2);
   output_low(pin_d3);
   output_low(pin_d4);
   output_low(pin_d5);
   output_b(dizi[a2]);
   output_high(pin_d1);
   }
   if(i==2)
   {
   output_low(pin_d0);
   output_low(pin_d1);
   output_low(pin_d3);
   output_low(pin_d4);
   output_low(pin_d5);
   output_b(dizi[a3]);
   output_high(pin_d2);
   }
   if(i==3)
   {
   output_low(pin_d0);
   output_low(pin_d1);
   output_low(pin_d2);
   output_low(pin_d4);
   output_low(pin_d5);
   output_b(dizi[a4]);
   output_high(pin_d3);
   }
   i++;
   sayac++;
   if(sayac>=50)
   {
   a1++;
   sayac=0;
   if(a1>=13)
   a1=0;
   }
   if(i>3)
   i=0;
}
void main()
{
setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256|RTCC_8_bit);   
enable_interrupts(INT_TIMER0);
enable_interrupts(GLOBAL);
  while(TRUE)
   {
      
   }

}
