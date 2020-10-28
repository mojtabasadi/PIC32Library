/* 
 * File:   SPI.h
 * Author: Mojtaba
 *
 * Created on August 11, 2020, 1:35 PM
 */

#ifndef SPI_H
#define	SPI_H

#include <xc.h>
//==============================================================================
#define MasterSPI   1
#define SlaveSPI    0
#define IntEnableSPI    1
#define IntDisableSPI   0
#define EnhncedBuffer   1
#define StandardBuffer  0
//==============================================================================
class spi
{
	public:
        void begin1(unsigned long PBFrequency,unsigned long FSCK,bool Master,bool IntEn,bool EnhBuf);
        unsigned char transfer1(unsigned char value);
};

#endif	/* SPI_H */

