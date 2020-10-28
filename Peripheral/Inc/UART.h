/* 
 * File:   UART.h
 * Author: Mojtaba
 *
 * Created on August 11, 2020, 1:43 PM
 */

#ifndef UART_H
#define	UART_H
#include <xc.h>
#include <p32xxxx.h>
enum mode{
        SERIAL_8N1=0,
        SERIAL_8E1,
        SERIAL_8O1,
        SERIAL_9N1,
        SERIAL_8N2,
        SERIAL_8E2,
        SERIAL_8O2,
        SERIAL_9N2,               
    }; 
class UART{
public:
    UART(unsigned long PBFrequency,uint8_t channel,uint32_t BaudRate, uint8_t mode){PBFreq=PBFrequency,Mode = mode;CH = channel;baudRate = BaudRate;}
    UART(unsigned long PBFrequency,uint8_t channel,uint32_t BaudRate){PBFreq=PBFrequency,Mode = SERIAL_8N1;CH = channel;baudRate = BaudRate;}
    UART(unsigned long PBFrequency,uint8_t channel){PBFreq=PBFrequency,Mode = SERIAL_8N1;CH = channel;baudRate = 9600;}
    void begin ();//Default 8N1 no interrupt    
    void begin (uint8_t intPriority,uint8_t intSubPriority);  
    bool available();
    void flush();
    uint8_t read();
    void write(uint8_t data);
    void puts(const char *string);
    void end();
    
private:
    unsigned long PBFreq;
    uint8_t  CH;
    uint8_t  Mode;
    uint32_t baudRate;
};

#endif	/* UART_H */

