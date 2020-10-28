#include "AT24C1024.h"
void AT24C1024::begin(unsigned long PBFrequency,double frequency)
{
    I2C2_init(PBFrequency,frequency);
}
void AT24C1024::write(unsigned int page,unsigned char bytePage,unsigned char data)
{
    unsigned int byte_adress;  // byte address 
    byte_adress=(page*16)+bytePage;  // generates  16 bit byte address from page num and byte number
    I2C2_start();  // start I2C
    I2C2_write(0xA0|((byte_adress>>7)&0x0E),0);  // access in write mode
    I2C2_write((byte_adress>>8)&0xff,0);
    I2C2_write(byte_adress&0xff,0);  // LSB of byte address(data word address)
    I2C2_write(data,0);  // input character to eeprom
    I2C2_stop();  // stops I2C
    ms(10);
}

uint8_t AT24C1024::read(unsigned int page,unsigned char bytePage)
{
    unsigned int byte_adress;  // byte address 
    unsigned char data;
    byte_adress=(page*16)+bytePage;  // generates  16 bit byte address from page num and byte number
    I2C2_start();
    I2C2_write(0xA0|((byte_adress>>7)&0x0E),1);  // access in write mode
    I2C2_write((byte_adress>>8)&0xff,1);
    I2C2_write(byte_adress&0xff,1);  // LSB of byte address(data word address)
    I2C2_start();
    I2C2_write(0xA1|((byte_adress>>7)&0x0E),1);  // access in read mode
    I2C2_read(&data,0);  // read with NACK
    I2C2_stop();  // stops I2C                              // writes the data to uart - for debugging
    return data;
}
