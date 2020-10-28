#include "SPI.h"
//==============================================================================      
void spi::begin1(unsigned long PBFrequency,unsigned long FSCK,bool Master,bool IntEn,bool EnhBuf)
{
    TRISDbits.TRISD9=0;
    TRISDbits.TRISD7=0;
    TRISDbits.TRISD0=0;
    TRISDbits.TRISD10=0;
    TRISCbits.TRISC4=1;
    SPI1CONbits.ON = 0; // Turn off SPI2 before configuring
    SPI1CONbits.MSTEN = Master; // Enable Master mode
    SPI1CONbits.CKP = 1; // Clock signal is active low, idle state is high
    SPI1CONbits.CKE = 0; // Data is shifted out/in on transition from idle (high) state to active (low) state
    SPI1CONbits.SMP = 1; // Input data is sampled at the end of the clock signal
    SPI1CONbits.MODE16 = 0; // Do not use 16-bit mode
    SPI1CONbits.MODE32 = 0; // Do not use 32-bit mode (combines with the above line to activate 8-bit mode)
    SPI1BRG = (PBFrequency/(2*FSCK) )-1;// Set Baud Rate Generator to 0 [discussed below]
    SPI1CONbits.SRXISEL = 1;
    IFS0bits.SPI1RXIF=0;
    IEC0bits.SPI1RXIE=IntEn;
    SPI1CONbits.ENHBUF = EnhBuf; // Disables Enhanced Buffer mode [also discussed below]
    SPI1CONbits.ON = 1; // Configuration is done, turn on SPI2 peripheral
}
unsigned char spi::transfer1(unsigned char value)
{
    unsigned char rx;
    SPI1BUF = value; // Send **data** to SPI2BUF.
    while (IFS0bits.SPI1RXIF==0); // Which the receive buffer is empty, loop
    rx=SPI1BUF;
    IFS0bits.SPI1RXIF=0;
    return rx; // Return whatever is in SPI2BUF
}
