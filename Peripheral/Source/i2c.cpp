#include "i2c.h"
// I2C_init() initialises I2C1 at at frequency of [frequency]Hz  
void i2c::I2C1_init(unsigned long PBFrequency,double frequency)
{
    double BRG;

    I2C1CON = 0;            // Turn off I2C1 module
    I2C1CONbits.DISSLW = 1; // Disable slew rate for 100kHz

    BRG = (1 / (2 * frequency)) - 0.000000104;
    BRG *= (PBFrequency / 2) - 2;    

    I2C1BRG = (int)BRG;     // Set baud rate
    I2C1CONbits.ON = 1;     // Turn on I2C1 module
}
// I2C_wait_for_idle() waits until the I2C peripheral is no longer doing anything  
void i2c::I2C1_wait_for_idle(void)
{
    while(I2C1CON & 0x1F); // Acknowledge sequence not in progress
                                // Receive sequence not in progress
                                // Stop condition not in progress
                                // Repeated Start condition not in progress
                                // Start condition not in progress
    while(I2C1STATbits.TRSTAT); // Bit = 0 ? Master transmit is not in progress
}

// I2C_start() sends a start condition  
void i2c::I2C1_start()
{
    I2C1_wait_for_idle();
    I2C1CONbits.SEN = 1;
    while (I2C1CONbits.SEN == 1);
}

// I2C_stop() sends a stop condition  
void i2c::I2C1_stop()
{
    I2C1_wait_for_idle();
    I2C1CONbits.PEN = 1;
}

// I2C_restart() sends a repeated start/restart condition
void i2c::I2C1_restart()
{
    I2C1_wait_for_idle();
    I2C1CONbits.RSEN = 1;
    while (I2C1CONbits.RSEN == 1);
}

// I2C_ack() sends an ACK condition
void i2c::I2C1_ack(void)
{
    I2C1_wait_for_idle();
    I2C1CONbits.ACKDT = 0; // Set hardware to send ACK bit
    I2C1CONbits.ACKEN = 1; // Send ACK bit, will be automatically cleared by hardware when sent  
    while(I2C1CONbits.ACKEN); // Wait until ACKEN bit is cleared, meaning ACK bit has been sent
}

// I2C_nack() sends a NACK condition
void i2c::I2C1_nack(void) // Acknowledge Data bit
{
    I2C1_wait_for_idle();
    I2C1CONbits.ACKDT = 1; // Set hardware to send NACK bit
    I2C1CONbits.ACKEN = 1; // Send NACK bit, will be automatically cleared by hardware when sent  
    while(I2C1CONbits.ACKEN); // Wait until ACKEN bit is cleared, meaning NACK bit has been sent
}
// address is I2C slave address, set wait_ack to 1 to wait for ACK bit or anything else to skip ACK checking  
void i2c::I2C1_write(unsigned char address, char wait_ack)
{
    I2C1TRN = address | 0;              // Send slave address with Read/Write bit cleared
    while (I2C1STATbits.TBF == 1);      // Wait until transmit buffer is empty
    I2C1_wait_for_idle();                // Wait until I2C bus is idle
    if (wait_ack) while (I2C1STATbits.ACKSTAT == 1); // Wait until ACK is received  
}
// value is the value of the data we want to send, set ack_nack to 0 to send an ACK or anything else to send a NACK  
void i2c::I2C1_read(unsigned char *value, char ack_nack)
{
    I2C1CONbits.RCEN = 1;               // Receive enable
    while (I2C1CONbits.RCEN);           // Wait until RCEN is cleared (automatic)  
    while (!I2C1STATbits.RBF);          // Wait until Receive Buffer is Full (RBF flag)  
    *value = I2C1RCV;                   // Retrieve value from I2C1RCV

    if (!ack_nack)                      // Do we need to send an ACK or a NACK?  
        I2C1_ack();                      // Send ACK  
    else
        I2C1_nack();                     // Send NACK  
}
// I2C_init() initialises I2C1 at at frequency of [frequency]Hz  
void i2c::I2C2_init(double frequency,unsigned long PBFrequency)
{
    double BRG;

    I2C2CON = 0;            // Turn off I2C1 module
    I2C2CONbits.DISSLW = 1; // Disable slew rate for 100kHz

    BRG = (1 / (2 * frequency)) - 0.000000104;
    BRG *= (PBFrequency / 2) - 2;    

    I2C2BRG = (int)BRG;     // Set baud rate
    I2C2CONbits.ON = 1;     // Turn on I2C1 module
}
// I2C_wait_for_idle() waits until the I2C peripheral is no longer doing anything  
void i2c::I2C2_wait_for_idle(void)
{
    while(I2C2CON & 0x1F); // Acknowledge sequence not in progress
                                // Receive sequence not in progress
                                // Stop condition not in progress
                                // Repeated Start condition not in progress
                                // Start condition not in progress
    while(I2C2STATbits.TRSTAT); // Bit = 0 ? Master transmit is not in progress
}

// I2C_start() sends a start condition  
void i2c::I2C2_start()
{
    I2C2_wait_for_idle();
    I2C2CONbits.SEN = 1;
    while (I2C2CONbits.SEN == 1);
}

// I2C_stop() sends a stop condition  
void i2c::I2C2_stop()
{
    I2C2_wait_for_idle();
    I2C2CONbits.PEN = 1;
}

// I2C_restart() sends a repeated start/restart condition
void i2c::I2C2_restart()
{
    I2C2_wait_for_idle();
    I2C2CONbits.RSEN = 1;
    while (I2C2CONbits.RSEN == 1);
}

// I2C_ack() sends an ACK condition
void i2c::I2C2_ack(void)
{
    I2C2_wait_for_idle();
    I2C2CONbits.ACKDT = 0; // Set hardware to send ACK bit
    I2C2CONbits.ACKEN = 1; // Send ACK bit, will be automatically cleared by hardware when sent  
    while(I2C2CONbits.ACKEN); // Wait until ACKEN bit is cleared, meaning ACK bit has been sent
}

// I2C_nack() sends a NACK condition
void i2c::I2C2_nack(void) // Acknowledge Data bit
{
    I2C2_wait_for_idle();
    I2C2CONbits.ACKDT = 1; // Set hardware to send NACK bit
    I2C2CONbits.ACKEN = 1; // Send NACK bit, will be automatically cleared by hardware when sent  
    while(I2C2CONbits.ACKEN); // Wait until ACKEN bit is cleared, meaning NACK bit has been sent
}
// address is I2C slave address, set wait_ack to 1 to wait for ACK bit or anything else to skip ACK checking  
void i2c::I2C2_write(unsigned char address, char wait_ack)
{
    I2C2TRN = address | 0;              // Send slave address with Read/Write bit cleared
    while (I2C2STATbits.TBF == 1);      // Wait until transmit buffer is empty
    I2C2_wait_for_idle();                // Wait until I2C bus is idle
    if (wait_ack) while (I2C2STATbits.ACKSTAT == 1); // Wait until ACK is received  
}
// value is the value of the data we want to send, set ack_nack to 0 to send an ACK or anything else to send a NACK  
void i2c::I2C2_read(unsigned char *value, char ack_nack)
{
    I2C2CONbits.RCEN = 1;               // Receive enable
    while (I2C2CONbits.RCEN);           // Wait until RCEN is cleared (automatic)  
    while (!I2C2STATbits.RBF);          // Wait until Receive Buffer is Full (RBF flag)  
    *value = I2C2RCV;                   // Retrieve value from I2C1RCV

    if (!ack_nack)                      // Do we need to send an ACK or a NACK?  
        I2C2_ack();                      // Send ACK  
    else
        I2C2_nack();                     // Send NACK  
}

