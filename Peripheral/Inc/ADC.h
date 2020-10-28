/* 
 * File:   ADC.h
 * Author: Mojtaba
 *
 * Created on August 11, 2020, 1:31 PM
 */

#ifndef ADC_H
#define	ADC_H
#include <xc.h>
#define AN0  0
#define AN1  1
#define AN2  2
#define AN3  4
#define AN4  8
#define AN5  16
#define AN6  32
#define AN7  64
#define AN8  128
#define AN9  256
#define AN10 512
#define AN11 1024
#define AN12 2048
#define AN13 4096
#define AN14 8192
#define AN15 16384         
#define ADC_FORMAT_SIGN_FRACT16   0b011//16bit
#define ADC_FORMAT_FRACT16       0b010//16bit
#define ADC_FORMAT_SIGN_INT16     0b001//16bit
#define ADC_FORMAT_INTG16        0b000//16bit
/*#define ADC_FORMAT_SIGN_FRACT32   0b111//32bit
#define ADC_FORMAT_FRACT32       0b110//32bit
#define ADC_FORMAT_SIGN_INT32     0b101//32bit
#define ADC_FORMAT_INTG32        0b100//32bit*/
#define ADC_CLK_AUTO   0b111
#define ADC_CLK_TMR    0b010
#define ADC_CLK_INT0   0b001
#define ADC_CLK_MANUAL  0
#define ADC_VREF_AVDD_AVSS  0
#define ADC_VREF_EXT_AVSS   1
#define ADC_VREF_AVDD_EXT   2
#define ADC_VREF_EXT_EXT    3
#define ADC_SCAN_ON     1
#define ADC_SCAN_OFF    0
#define ADC_CONV_CLK_INTERNAL_RC    1
#define ADC_CONV_CLK_SYSTEM        0
class Analog{
public:
    Analog(uint16_t pin,uint16_t FirstChannel,uint8_t Format,uint8_t SampleClockSource,uint8_t VoltageRef,
            uint8_t ScanMode,uint8_t NumberConversionPerInt,uint8_t ConversionClockSource);
    void begin();
    bool Available();
    void Read(unsigned int *Buff0);
    void Read(unsigned int *Buff0,unsigned int *Buff1);
    void Read(unsigned int *Buff0,unsigned int *Buff1,unsigned int *Buff2);
    void Read(unsigned int *Buff0,unsigned int *Buff1,unsigned int *Buff2
        ,unsigned int *Buff3);
    void Read(unsigned int *Buff0,unsigned int *Buff1,unsigned int *Buff2
        ,unsigned int *Buff3,unsigned int *Buff4);
    void Read(unsigned int *Buff0,unsigned int *Buff1,unsigned int *Buff2
        ,unsigned int *Buff3,unsigned int *Buff4,unsigned int *Buff5);
    void Read(unsigned int *Buff0,unsigned int *Buff1,unsigned int *Buff2
        ,unsigned int *Buff3,unsigned int *Buff4,unsigned int *Buff5
        ,unsigned int *Buff6);
    void Read(unsigned int *Buff0,unsigned int *Buff1,unsigned int *Buff2
        ,unsigned int *Buff3,unsigned int *Buff4,unsigned int *Buff5
        ,unsigned int *Buff6,unsigned int *Buff7);
    void Read(unsigned int *Buff0,unsigned int *Buff1,unsigned int *Buff2
        ,unsigned int *Buff3,unsigned int *Buff4,unsigned int *Buff5
        ,unsigned int *Buff6,unsigned int *Buff7,unsigned int *Buff8);
    void Read(unsigned int *Buff0,unsigned int *Buff1,unsigned int *Buff2
        ,unsigned int *Buff3,unsigned int *Buff4,unsigned int *Buff5
        ,unsigned int *Buff6,unsigned int *Buff7,unsigned int *Buff8,unsigned int *Buff9);
    void Read(unsigned int *Buff0,unsigned int *Buff1,unsigned int *Buff2
        ,unsigned int *Buff3,unsigned int *Buff4,unsigned int *Buff5
        ,unsigned int *Buff6,unsigned int *Buff7,unsigned int *Buff8,unsigned int *Buff9
        ,unsigned int *Buff10);
    void Read(unsigned int *Buff0,unsigned int *Buff1,unsigned int *Buff2
        ,unsigned int *Buff3,unsigned int *Buff4,unsigned int *Buff5
        ,unsigned int *Buff6,unsigned int *Buff7,unsigned int *Buff8,unsigned int *Buff9
        ,unsigned int *Buff10,unsigned int *Buff11);
    void Read(unsigned int *Buff0,unsigned int *Buff1,unsigned int *Buff2
        ,unsigned int *Buff3,unsigned int *Buff4,unsigned int *Buff5
        ,unsigned int *Buff6,unsigned int *Buff7,unsigned int *Buff8,unsigned int *Buff9
        ,unsigned int *Buff10,unsigned int *Buff11,unsigned int *Buff12);
    void Read(unsigned int *Buff0,unsigned int *Buff1,unsigned int *Buff2
        ,unsigned int *Buff3,unsigned int *Buff4,unsigned int *Buff5
        ,unsigned int *Buff6,unsigned int *Buff7,unsigned int *Buff8,unsigned int *Buff9
        ,unsigned int *Buff10,unsigned int *Buff11,unsigned int *Buff12
        ,unsigned int *Buff13);
    void Read(unsigned int *Buff0,unsigned int *Buff1,unsigned int *Buff2
        ,unsigned int *Buff3,unsigned int *Buff4,unsigned int *Buff5
        ,unsigned int *Buff6,unsigned int *Buff7,unsigned int *Buff8,unsigned int *Buff9
        ,unsigned int *Buff10,unsigned int *Buff11,unsigned int *Buff12
        ,unsigned int *Buff13,unsigned int *Buff14);
    void Read(unsigned int *Buff0,unsigned int *Buff1,unsigned int *Buff2
        ,unsigned int *Buff3,unsigned int *Buff4,unsigned int *Buff5
        ,unsigned int *Buff6,unsigned int *Buff7,unsigned int *Buff8,unsigned int *Buff9
        ,unsigned int *Buff10,unsigned int *Buff11,unsigned int *Buff12
        ,unsigned int *Buff13,unsigned int *Buff14,unsigned int *Buff15);
    
};

#endif	/* ADC_H */

