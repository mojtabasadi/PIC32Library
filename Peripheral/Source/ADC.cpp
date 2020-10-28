#include "ADC.h"
Analog::Analog(uint16_t pin,uint16_t FirstChannel,uint8_t Format,uint8_t SampleClockSource,uint8_t VoltageRef,
            uint8_t ScanMode,uint8_t NumberConversionPerInt,uint8_t ConversionClockSource)
{
    AD1PCFG=~pin;
    TRISB=pin;
    AD1CHS = FirstChannel<<12;
    AD1CON1bits.FORM  = Format;
    AD1CON1bits.SSRC  = SampleClockSource;
    AD1CON2bits.VCFG  = VoltageRef;
    AD1CON2bits.CSCNA = ScanMode;  
    AD1CSSL=0x300;
    AD1CON2bits.SMPI  = NumberConversionPerInt;
    AD1CON2bits.BUFM  = 0;//Buffer configured as one 16-word buffer ADC1BUF(15...0.)
    AD1CON2bits.ALTS  = 0;//Always use MUX A input multiplexer settings
    AD1CON3bits.ADRC  = ConversionClockSource;
    AD1CON3bits.SAMC  = 3;
    AD1CON3bits.ADCS  = 48;
    AD1CON1bits.ASAM  = 1;
}
void Analog::begin()
{
    AD1CON1bits.ADON=1;
    IFS1bits.AD1IF=0;
}
bool Analog::Available()
{
    if(IFS1bits.AD1IF==1)return 1;
    else return 0;
}
void Analog::Read(unsigned int* Buff0)
{
    *Buff0=ADC1BUF0;
    IFS1bits.AD1IF=0;
}
void Analog::Read(unsigned int* Buff0, unsigned int* Buff1)
{
    *Buff0=ADC1BUF0;
    *Buff1=ADC1BUF1;
    IFS1bits.AD1IF=0;
}
void Analog::Read(unsigned int* Buff0, unsigned int* Buff1, unsigned int* Buff2)
{
    *Buff0=ADC1BUF0;
    *Buff1=ADC1BUF1;
    *Buff2=ADC1BUF2;
    IFS1bits.AD1IF=0;
}
void Analog::Read(unsigned int* Buff0, unsigned int* Buff1, unsigned int* Buff2, unsigned int* Buff3)
{
    *Buff0=ADC1BUF0;
    *Buff1=ADC1BUF1;
    *Buff2=ADC1BUF2;
    *Buff3=ADC1BUF3;
    IFS1bits.AD1IF=0;
}
void Analog::Read(unsigned int* Buff0, unsigned int* Buff1, unsigned int* Buff2, unsigned int* Buff3, unsigned int* Buff4)
{
    *Buff0=ADC1BUF0;
    *Buff1=ADC1BUF1;
    *Buff2=ADC1BUF2;
    *Buff3=ADC1BUF3;
    *Buff4=ADC1BUF4;
    IFS1bits.AD1IF=0;
}
void Analog::Read(unsigned int* Buff0, unsigned int* Buff1, unsigned int* Buff2, unsigned int* Buff3, unsigned int* Buff4, unsigned int* Buff5)
{
    *Buff0=ADC1BUF0;
    *Buff1=ADC1BUF1;
    *Buff2=ADC1BUF2;
    *Buff3=ADC1BUF3;
    *Buff4=ADC1BUF4;
    *Buff5=ADC1BUF5;
    IFS1bits.AD1IF=0;
}
void Analog::Read(unsigned int* Buff0, unsigned int* Buff1, unsigned int* Buff2, unsigned int* Buff3, unsigned int* Buff4, unsigned int* Buff5, unsigned int* Buff6)
{
    *Buff0=ADC1BUF0;
    *Buff1=ADC1BUF1;
    *Buff2=ADC1BUF2;
    *Buff3=ADC1BUF3;
    *Buff4=ADC1BUF4;
    *Buff5=ADC1BUF5;
    *Buff6=ADC1BUF6;
    IFS1bits.AD1IF=0;
}
void Analog::Read(unsigned int* Buff0, unsigned int* Buff1, unsigned int* Buff2, unsigned int* Buff3, unsigned int* Buff4, unsigned int* Buff5, unsigned int* Buff6, unsigned int* Buff7)
{
    *Buff0=ADC1BUF0;
    *Buff1=ADC1BUF1;
    *Buff2=ADC1BUF2;
    *Buff3=ADC1BUF3;
    *Buff4=ADC1BUF4;
    *Buff5=ADC1BUF5;
    *Buff6=ADC1BUF6;
    *Buff7=ADC1BUF7;
    IFS1bits.AD1IF=0;
}
void Analog::Read(unsigned int* Buff0, unsigned int* Buff1, unsigned int* Buff2, unsigned int* Buff3, unsigned int* Buff4, unsigned int* Buff5, unsigned int* Buff6, unsigned int* Buff7, unsigned int* Buff8)
{
    *Buff0=ADC1BUF0;
    *Buff1=ADC1BUF1;
    *Buff2=ADC1BUF2;
    *Buff3=ADC1BUF3;
    *Buff4=ADC1BUF4;
    *Buff5=ADC1BUF5;
    *Buff6=ADC1BUF6;
    *Buff7=ADC1BUF7;
    *Buff8=ADC1BUF8;
    IFS1bits.AD1IF=0;
}
void Analog::Read(unsigned int* Buff0, unsigned int* Buff1, unsigned int* Buff2, unsigned int* Buff3, unsigned int* Buff4, unsigned int* Buff5, unsigned int* Buff6, unsigned int* Buff7, unsigned int* Buff8, unsigned int* Buff9)
{
    *Buff0=ADC1BUF0;
    *Buff1=ADC1BUF1;
    *Buff2=ADC1BUF2;
    *Buff3=ADC1BUF3;
    *Buff4=ADC1BUF4;
    *Buff5=ADC1BUF5;
    *Buff6=ADC1BUF6;
    *Buff7=ADC1BUF7;
    *Buff8=ADC1BUF8;
    *Buff9=ADC1BUF9;
    IFS1bits.AD1IF=0;
}
void Analog::Read(unsigned int* Buff0, unsigned int* Buff1, unsigned int* Buff2, unsigned int* Buff3, unsigned int* Buff4, unsigned int* Buff5, unsigned int* Buff6, unsigned int* Buff7, unsigned int* Buff8, unsigned int* Buff9, unsigned int* Buff10)
{
    *Buff0=ADC1BUF0;
    *Buff1=ADC1BUF1;
    *Buff2=ADC1BUF2;
    *Buff3=ADC1BUF3;
    *Buff4=ADC1BUF4;
    *Buff5=ADC1BUF5;
    *Buff6=ADC1BUF6;
    *Buff7=ADC1BUF7;
    *Buff8=ADC1BUF8;
    *Buff9=ADC1BUF9;
    *Buff10=ADC1BUFA;
    IFS1bits.AD1IF=0;
}
void Analog::Read(unsigned int* Buff0, unsigned int* Buff1, unsigned int* Buff2, unsigned int* Buff3, unsigned int* Buff4, unsigned int* Buff5, unsigned int* Buff6, unsigned int* Buff7, unsigned int* Buff8, unsigned int* Buff9, unsigned int* Buff10, unsigned int* Buff11)
{
    *Buff0=ADC1BUF0;
    *Buff1=ADC1BUF1;
    *Buff2=ADC1BUF2;
    *Buff3=ADC1BUF3;
    *Buff4=ADC1BUF4;
    *Buff5=ADC1BUF5;
    *Buff6=ADC1BUF6;
    *Buff7=ADC1BUF7;
    *Buff8=ADC1BUF8;
    *Buff9=ADC1BUF9;
    *Buff10=ADC1BUFA;
    *Buff11=ADC1BUFB;
    IFS1bits.AD1IF=0;
}
void Analog::Read(unsigned int* Buff0, unsigned int* Buff1, unsigned int* Buff2, unsigned int* Buff3, unsigned int* Buff4, unsigned int* Buff5, unsigned int* Buff6, unsigned int* Buff7, unsigned int* Buff8, unsigned int* Buff9, unsigned int* Buff10, unsigned int* Buff11, unsigned int* Buff12)
{
    *Buff0=ADC1BUF0;
    *Buff1=ADC1BUF1;
    *Buff2=ADC1BUF2;
    *Buff3=ADC1BUF3;
    *Buff4=ADC1BUF4;
    *Buff5=ADC1BUF5;
    *Buff6=ADC1BUF6;
    *Buff7=ADC1BUF7;
    *Buff8=ADC1BUF8;
    *Buff9=ADC1BUF9;
    *Buff10=ADC1BUFA;
    *Buff11=ADC1BUFB;
    *Buff12=ADC1BUFC;
    IFS1bits.AD1IF=0;
}
void Analog::Read(unsigned int* Buff0, unsigned int* Buff1, unsigned int* Buff2, unsigned int* Buff3, unsigned int* Buff4, unsigned int* Buff5, unsigned int* Buff6, unsigned int* Buff7, unsigned int* Buff8, unsigned int* Buff9, unsigned int* Buff10, unsigned int* Buff11, unsigned int* Buff12, unsigned int* Buff13)
{
    *Buff0=ADC1BUF0;
    *Buff1=ADC1BUF1;
    *Buff2=ADC1BUF2;
    *Buff3=ADC1BUF3;
    *Buff4=ADC1BUF4;
    *Buff5=ADC1BUF5;
    *Buff6=ADC1BUF6;
    *Buff7=ADC1BUF7;
    *Buff8=ADC1BUF8;
    *Buff9=ADC1BUF9;
    *Buff10=ADC1BUFA;
    *Buff11=ADC1BUFB;
    *Buff12=ADC1BUFC;
    *Buff13=ADC1BUFD;
    IFS1bits.AD1IF=0;
}
void Analog::Read(unsigned int* Buff0, unsigned int* Buff1, unsigned int* Buff2, unsigned int* Buff3, unsigned int* Buff4, unsigned int* Buff5, unsigned int* Buff6, unsigned int* Buff7, unsigned int* Buff8, unsigned int* Buff9, unsigned int* Buff10, unsigned int* Buff11, unsigned int* Buff12, unsigned int* Buff13, unsigned int* Buff14)
{
    *Buff0=ADC1BUF0;
    *Buff1=ADC1BUF1;
    *Buff2=ADC1BUF2;
    *Buff3=ADC1BUF3;
    *Buff4=ADC1BUF4;
    *Buff5=ADC1BUF5;
    *Buff6=ADC1BUF6;
    *Buff7=ADC1BUF7;
    *Buff8=ADC1BUF8;
    *Buff9=ADC1BUF9;
    *Buff10=ADC1BUFA;
    *Buff11=ADC1BUFB;
    *Buff12=ADC1BUFC;
    *Buff13=ADC1BUFD;
    *Buff14=ADC1BUFE;
    IFS1bits.AD1IF=0;
}
void Analog::Read(unsigned int* Buff0, unsigned int* Buff1, unsigned int* Buff2, unsigned int* Buff3, unsigned int* Buff4, unsigned int* Buff5, unsigned int* Buff6, unsigned int* Buff7, unsigned int* Buff8, unsigned int* Buff9, unsigned int* Buff10, unsigned int* Buff11, unsigned int* Buff12, unsigned int* Buff13, unsigned int* Buff14, unsigned int* Buff15)
{
    *Buff0=ADC1BUF0;
    *Buff1=ADC1BUF1;
    *Buff2=ADC1BUF2;
    *Buff3=ADC1BUF3;
    *Buff4=ADC1BUF4;
    *Buff5=ADC1BUF5;
    *Buff6=ADC1BUF6;
    *Buff7=ADC1BUF7;
    *Buff8=ADC1BUF8;
    *Buff9=ADC1BUF9;
    *Buff10=ADC1BUFA;
    *Buff11=ADC1BUFB;
    *Buff12=ADC1BUFC;
    *Buff13=ADC1BUFD;
    *Buff14=ADC1BUFE;
    *Buff15=ADC1BUFF;
    IFS1bits.AD1IF=0;
}
