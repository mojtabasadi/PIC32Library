/* 
 * File:   DS3231.h
 * Author: Mojtaba
 *
 * Created on August 11, 2020, 5:12 PM
 */

#ifndef DS3231_H
#define	DS3231_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#define DS3231_ADDRESS  0x68

#include <xc.h>
#include "../Peripheral/i2c.h"

class RTCC : private i2c
{
public:    
    RTCC(unsigned long PBFrequency,double freq);
    void setRTCC(unsigned char h,unsigned char m,unsigned char s);
    unsigned char*  getRTCC(unsigned char time[]);
    void setDate(unsigned char yy,unsigned char mm,unsigned char dd);
    unsigned char*  getDate(unsigned char date[]);
    long* gregorianTOjalali(long gy,long gm,long gd,long out[]);
    long* jalaliTOgregorian(long jy,long jm,long jd,long out[]);
private:
    enum DS3231
    {
        SecAddress=0,
        MinAddress,
        HourAddress,
        DayAddress,//1~7
        DateAddress,
        MonthAddress,
        YearAddress           
    };
    uint8_t DS3231Init(unsigned long PBFrequency,double freq);
    unsigned char DS3231Read(unsigned char reg_address, unsigned char *value);
    void DS3231Write(unsigned char reg_address, unsigned char value);
};

#endif	/* DS3231_H */

