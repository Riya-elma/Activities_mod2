#include <avr/io.h>
#include<util/delay.h>
void InitAdc()
{
    ADMUX|=(1<<REFS0);
    ADCSRA|=(1<<ADEN)|(7<<ADPS0);
}
uint16_t ReadAdc(uint8_t ch)
{
    ADMUX&=0xF8;
    ch=ch&0b00000111;
    ADMUX|=ch;
    ADCSRA|=(1<<ADSC);
    while(!(ADCSRA&(1<<ADIF)));
    ADCSRA|(1<<ADIF);
    return(ADC);
}
int main(void)
{
    InitAdc();
    uint16_t temp;
    while(1)
    {
        temp=ReadAdc(0);
        _delay_ms(200);
    }


    return 0;
}
