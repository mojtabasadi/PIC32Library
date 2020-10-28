/* 
 * File:   DMA.h
 * Author: Mojtaba
 *
 * Created on August 11, 2020, 1:50 PM
 */

#ifndef DMA_H
#define	DMA_H
#include <xc.h>
#include <p32xxxx.h>
#include <sys/kmem.h>

enum DMAMode{
    Basic=1,
    PatternMatch,
    
};
class DMA
{
public:
    DMA(uint8_t ch){channel = ch;}
    DMA(uint8_t ch,uint8_t IntPriority,uint8_t IntSubPriority)
    {
        channel = ch;
        switch (channel)
        {
            case 0:
                IPC9bits.DMA0IP = IntPriority;                 // Set DMA 0 interrupt priority to 3
                IPC9bits.DMA0IS = IntSubPriority;                 // Set DMA 0 interrupt sub-priority to 1
                IFS1bits.DMA0IF = 0;                 // Clear the DMA channel 0 interrupt flag
                IEC1bits.DMA0IE = 1;                 // Enable the DMA 0 interrupt       
                DCH0INTbits.CHBCIF=0;
                DCH0INTbits.CHBCIE = 1;              // Enable the Channel Block Transer Complete (CHBC) Interrupt
                break;
            case 1:
                IPC9bits.DMA1IP = IntPriority;                 // Set DMA 1 interrupt priority to 3
                IPC9bits.DMA1IS = IntSubPriority;                 // Set DMA 1 interrupt sub-priority to 1
                IFS1bits.DMA1IF = 0;                 // Clear the DMA channel 1 interrupt flag
                IEC1bits.DMA1IE = 1;                 // Enable the DMA 1 interrupt
                DCH1INTbits.CHBCIF=0;
                DCH1INTbits.CHBCIE = 1;              // Enable the Channel Block Transer Complete (CHBC) Interrupt
                break;
            case 2:
                IPC9bits.DMA2IP = IntPriority;                 // Set DMA 1 interrupt priority to 3
                IPC9bits.DMA2IS = IntSubPriority;                 // Set DMA 1 interrupt sub-priority to 1
                IFS1bits.DMA2IF = 0;                 // Clear the DMA channel 1 interrupt flag
                IEC1bits.DMA2IE = 1;                 // Enable the DMA 1 interrupt
                DCH2INTbits.CHBCIF=0;
                DCH2INTbits.CHBCIE = 1;              // Enable the Channel Block Transer Complete (CHBC) Interrupt
                break;
            case 3:
                IPC9bits.DMA3IP = IntPriority;                 // Set DMA 1 interrupt priority to 3
                IPC9bits.DMA3IS = IntSubPriority;                 // Set DMA 1 interrupt sub-priority to 1
                IFS1bits.DMA3IF = 0;                 // Clear the DMA channel 1 interrupt flag
                IEC1bits.DMA3IE = 1;                 // Enable the DMA 1 interrupt
                DCH3INTbits.CHBCIF=0;
                DCH3INTbits.CHBCIE = 1;              // Enable the Channel Block Transer Complete (CHBC) Interrupt
                break;
        }
        
    }
    void BasicTransfer(unsigned long buff, unsigned long reg,uint32_t SourceSize, uint32_t DestinationSize,uint32_t CellSize,
                        uint8_t StartIRQ,uint8_t StopIRQ);
    void AutoTransfer(unsigned long buff, unsigned long reg,uint32_t SourceSize, uint32_t DestinationSize,uint32_t CellSize,
                          uint8_t StartIRQ,uint8_t StopIRQ);
private:
    uint8_t channel;
};


#endif	/* DMA_H */

