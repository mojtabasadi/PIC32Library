/* 
 * File:   delay.h
 * Author: Mojtaba
 *
 * Created on August 11, 2020, 1:39 PM
 */

#ifndef DELAY_H
#define	DELAY_H

#include <xc.h>
class delay
{
public:
    delay(unsigned long PBFrequency){Frequency=PBFrequency;}
    void us(unsigned int us);
    void ms(unsigned int ms);
    void s(unsigned int s);
private:
    unsigned long Frequency;
};


#endif	/* DELAY_H */

