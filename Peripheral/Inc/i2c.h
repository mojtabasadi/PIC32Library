/* 
 * File:   i2c.h
 * Author: Mojtaba
 *
 * Created on August 11, 2020, 1:33 PM
 */

#ifndef I2C_H
#define	I2C_H
#include <xc.h>
#include <p32xxxx.h>

class i2c{
public:
    //i2c 1
    void I2C1_init(unsigned long PBFrequency,double frequency);
    void I2C1_wait_for_idle(void);
    void I2C1_start();
    void I2C1_stop();
    void I2C1_restart();
    void I2C1_ack(void);
    void I2C1_nack(void);
    void I2C1_write(unsigned char address, char wait_ack);
    void I2C1_read(unsigned char *value, char ack_nack); 
    //i2c 2
    void I2C2_init(double frequency,unsigned long PBFrequency);
    void I2C2_wait_for_idle(void);
    void I2C2_start();
    void I2C2_stop();
    void I2C2_restart();
    void I2C2_ack(void);
    void I2C2_nack(void);
    void I2C2_write(unsigned char address, char wait_ack);
    void I2C2_read(unsigned char *value, char ack_nack); 
};


#endif	/* I2C_H */

