/* 
 * File:   Timer.h
 * Author: Mojtaba
 *
 * Created on August 11, 2020, 1:47 PM
 */

#ifndef TIMER_H
#define	TIMER_H
#include <xc.h>
#define InternalClock   0
#define ExternalClock   1
#define IntEnableTimer    1
#define IntDisableTimer   0
#define PS_1_1   0
#define PS_1_2   1
#define PS_1_4   2
#define PS_1_8   3
#define PS_1_16  4
#define PS_1_32  5
#define PS_1_64  6
#define PS_1_256 7
enum channel
{
    Timer1=1,
    Timer2,
    Timer3,
    Timer4,
    Timer5,
    Timer2va3,
    Timer4va5       
};
class Timer
{
public: 
    Timer(uint8_t channel,bool ClockSource,uint8_t PreScaler,bool IntEn,uint8_t priority,uint8_t Subpriority);
    Timer(uint8_t channel,bool ClockSource,uint8_t PreScaler);
    void On();
    void Off();
    bool getFlag();
    void setTimer(unsigned long TMR);
    void setPeriod(unsigned long PR);
    uint8_t TimerChannel;
};


#endif	/* TIMER_H */

