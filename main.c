#include <16f877A.h>
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD
#use delay(clock=4000000)
#use fast_io(b)
#use fast_io(d)
#define buton pin_D0
int i=30;

void main()
{
setup_psp(PSP_DISABLED);
setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
setup_timer_1(T1_DISABLED);
setup_timer_2(T2_DISABLED,0,1);
setup_adc_ports(NO_ANALOGS);
setup_adc(ADC_CLOCK_DIV_2);
setup_comparator(NC_NC_NC_NC);
setup_spi(SPI_SS_DISABLED);
setup_vref(FALSE);
set_tris_d(0x01);
set_tris_b(0x00);
output_b(0x00);   

  while(1)
  {
 if(input(buton))
  {
 
 output_b(i);
 i--;
 while(input(buton));
if(i==0)
{
i=30;
 }
}
}
}


 
  

  

