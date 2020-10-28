/* 
 * File:   AT24C1024.h
 * Author: Mojtaba
 *
 * Created on August 11, 2020, 5:19 PM
 */

#ifndef AT24C1024_H
#define	AT24C1024_H


#include <xc.h>
#include "../Peripheral/i2c.h"
#include "../Peripheral/delay.h"
class AT24C1024 : private i2c , delay
{
    public:
        void begin(unsigned long PBFrequency,double frequency);
        void write(unsigned int page,unsigned char bytePage,unsigned char data);
        uint8_t read(unsigned int page,unsigned char bytePage);    
};

#endif	/* AT24C1024_H */

