#include "DMA.h"
void DMA::BasicTransfer(unsigned long buff, unsigned long reg,uint32_t SourceSize, uint32_t DestinationSize,uint32_t CellSize,
                          uint8_t StartIRQ,uint8_t StopIRQ)
{
    switch (channel)
    {
        case 0:
                DCH0CONbits.CHEN = 0;                       // Turn off this channel
                DCH0SSA = buff;             // Move the data from the [buffer] array
                DCH0DSA = reg;// Move the data to the PMDIN register
                DCH0SSIZ = SourceSize;               // Move num_bytes bytes of data in total
                DCH0CSIZ = CellSize;                 // Move 2 bytes at a time
                DCH0DSIZ = DestinationSize;          // Destination size is 2 bytes
                DCH0ECON=0;                          // Clear the DMA configuration settings 
                DCH0ECONbits.CHSIRQ = StartIRQ;      // Move data on PMP interrupt
                DCH0ECONbits.CHAIRQ = StopIRQ;       // Abort on PMP error
                DCH0ECONbits.SIRQEN = 1;             // Enable Start IRQ
                DCH0ECONbits.AIRQEN = 1;             // Enable Abort IRQ
                DCH0CONbits.CHPRI = 3;               // The priority of this channel is 3 (highest)
                DCH0CONbits.CHEN = 1;                // Turn this channel on now          
                DCH0ECONbits.CFORCE = 1;             // Force the start of the transfer now
                DMACONSET=0x8000; 
                break;
        case 1:
                DCH1CONbits.CHEN = 0;                       // Turn off this channel
                DCH1SSA = buff;             // Move the data from the [buffer] array
                DCH1DSA = reg;// Move the data to the PMDIN register
                DCH1SSIZ = SourceSize;               // Move num_bytes bytes of data in total
                DCH1CSIZ = CellSize;                 // Move 2 bytes at a time
                DCH1DSIZ = DestinationSize;          // Destination size is 2 bytes
                DCH1ECON=0;                          // Clear the DMA configuration settings 
                DCH1ECONbits.CHSIRQ = StartIRQ;      // Move data on PMP interrupt
                DCH1ECONbits.CHAIRQ = StopIRQ;       // Abort on PMP error
                DCH1ECONbits.SIRQEN = 1;             // Enable Start IRQ
                DCH1ECONbits.AIRQEN = 1;             // Enable Abort IRQ
                DCH1CONbits.CHPRI = 3;               // The priority of this channel is 3 (highest)
                DCH1CONbits.CHEN = 1;                // Turn this channel on now                
                DCH1ECONbits.CFORCE = 1;             // Force the start of the transfer now
                DMACONSET=0x8000; 
                break;
        case 2:
                DCH2CONbits.CHEN = 0;                       // Turn off this channel
                DCH2SSA = buff;             // Move the data from the [buffer] array
                DCH2DSA = reg;// Move the data to the PMDIN register
                DCH2SSIZ = SourceSize;               // Move num_bytes bytes of data in total
                DCH2CSIZ = CellSize;                 // Move 2 bytes at a time
                DCH2DSIZ = DestinationSize;          // Destination size is 2 bytes
                DCH2ECON=0;                          // Clear the DMA configuration settings 
                DCH2ECONbits.CHSIRQ = StartIRQ;      // Move data on PMP interrupt
                DCH2ECONbits.CHAIRQ = StopIRQ;       // Abort on PMP error
                DCH2ECONbits.SIRQEN = 1;             // Enable Start IRQ
                DCH2ECONbits.AIRQEN = 1;             // Enable Abort IRQ
                DCH2CONbits.CHPRI = 3;               // The priority of this channel is 3 (highest)
                DCH2CONbits.CHEN = 1;                // Turn this channel on now
                DCH2ECONbits.CFORCE = 1;             // Force the start of the transfer now
                DMACONSET=0x8000; 
                break;
        case 3:
                DCH3CONbits.CHEN = 0;                       // Turn off this channel
                DCH3SSA = buff;             // Move the data from the [buffer] array
                DCH3DSA = reg;// Move the data to the PMDIN register
                DCH3SSIZ = SourceSize;               // Move num_bytes bytes of data in total
                DCH3CSIZ = CellSize;                 // Move 2 bytes at a time
                DCH3DSIZ = DestinationSize;          // Destination size is 2 bytes
                DCH3ECON=0;                          // Clear the DMA configuration settings 
                DCH3ECONbits.CHSIRQ = StartIRQ;      // Move data on PMP interrupt
                DCH3ECONbits.CHAIRQ = StopIRQ;       // Abort on PMP error
                DCH3ECONbits.SIRQEN = 1;             // Enable Start IRQ
                DCH3ECONbits.AIRQEN = 1;             // Enable Abort IRQ
                DCH3CONbits.CHPRI = 3;               // The priority of this channel is 3 (highest)
                DCH3CONbits.CHEN = 1;                // Turn this channel on now
                DCH3ECONbits.CFORCE = 1;             // Force the start of the transfer now
                DMACONSET=0x8000;  // Turn the DMA module on
                break;
    }                 
}
void DMA::AutoTransfer(unsigned long buff, unsigned long reg,uint32_t SourceSize, uint32_t DestinationSize,uint32_t CellSize,
                          uint8_t StartIRQ,uint8_t StopIRQ)
{
    switch (channel)
    {
        case 0:
                DCH0CONbits.CHEN = 0;                       // Turn off this channel
                DCH0SSA = buff;             // Move the data from the [buffer] array
                DCH0DSA = reg;// Move the data to the PMDIN register
                DCH0SSIZ = SourceSize;               // Move num_bytes bytes of data in total
                DCH0CSIZ = CellSize;                 // Move 2 bytes at a time
                DCH0DSIZ = DestinationSize;          // Destination size is 2 bytes
                DCH0ECON=0;                          // Clear the DMA configuration settings 
                DCH0ECONbits.CHSIRQ = StartIRQ;      // Move data on PMP interrupt
                DCH0ECONbits.CHAIRQ = StopIRQ;       // Abort on PMP error
                DCH0ECONbits.SIRQEN = 1;             // Enable Start IRQ
                DCH0ECONbits.AIRQEN = 0;             // Enable Abort IRQ
                DCH0CONbits.CHPRI = 3;               // The priority of this channel is 3 (highest)
                DCH0CONbits.CHEN = 1;                // Turn this channel on now          
                DCH0CONbits.CHAEN=1;
                //DCH0ECONbits.CFORCE = 1;             // Force the start of the transfer now
                DMACONSET=0x8000; 
                break;
        case 1:
                DCH1CONbits.CHEN = 0;                       // Turn off this channel
                DCH1SSA = buff;             // Move the data from the [buffer] array
                DCH1DSA = reg;// Move the data to the PMDIN register
                DCH1SSIZ = SourceSize;               // Move num_bytes bytes of data in total
                DCH1CSIZ = CellSize;                 // Move 2 bytes at a time
                DCH1DSIZ = DestinationSize;          // Destination size is 2 bytes
                DCH1ECON=0;                          // Clear the DMA configuration settings 
                DCH1ECONbits.CHSIRQ = StartIRQ;      // Move data on PMP interrupt
                DCH1ECONbits.CHAIRQ = StopIRQ;       // Abort on PMP error
                DCH1ECONbits.SIRQEN = 1;             // Enable Start IRQ
                DCH1ECONbits.AIRQEN = 0;             // Enable Abort IRQ
                DCH1CONbits.CHPRI = 3;               // The priority of this channel is 3 (highest)
                DCH1CONbits.CHEN = 1;                // Turn this channel on now
                DCH1CONbits.CHAEN=1;
                DCH1ECONbits.CFORCE = 1;             // Force the start of the transfer now
                DMACONSET=0x8000; 
                break;
        case 2:
                DCH2CONbits.CHEN = 0;                       // Turn off this channel
                DCH2SSA = buff;             // Move the data from the [buffer] array
                DCH2DSA = reg;// Move the data to the PMDIN register
                DCH2SSIZ = SourceSize;               // Move num_bytes bytes of data in total
                DCH2CSIZ = CellSize;                 // Move 2 bytes at a time
                DCH2DSIZ = DestinationSize;          // Destination size is 2 bytes
                DCH2ECON=0;                          // Clear the DMA configuration settings 
                DCH2ECONbits.CHSIRQ = StartIRQ;      // Move data on PMP interrupt
                DCH2ECONbits.CHAIRQ = StopIRQ;       // Abort on PMP error
                DCH2ECONbits.SIRQEN = 1;             // Enable Start IRQ
                DCH2ECONbits.AIRQEN = 0;             // Enable Abort IRQ
                DCH2CONbits.CHPRI = 3;               // The priority of this channel is 3 (highest)
                DCH2CONbits.CHEN = 1;                // Turn this channel on now
                DCH2CONbits.CHAEN=1;
                DCH2ECONbits.CFORCE = 1;             // Force the start of the transfer now
                DMACONSET=0x8000; 
                break;
        case 3:
                DCH3CONbits.CHEN = 0;                       // Turn off this channel
                DCH3SSA = buff;             // Move the data from the [buffer] array
                DCH3DSA = reg;// Move the data to the PMDIN register
                DCH3SSIZ = SourceSize;               // Move num_bytes bytes of data in total
                DCH3CSIZ = CellSize;                 // Move 2 bytes at a time
                DCH3DSIZ = DestinationSize;          // Destination size is 2 bytes
                DCH3ECON=0;                          // Clear the DMA configuration settings 
                DCH3ECONbits.CHSIRQ = StartIRQ;      // Move data on PMP interrupt
                DCH3ECONbits.CHAIRQ = StopIRQ;       // Abort on PMP error
                DCH3ECONbits.SIRQEN = 1;             // Enable Start IRQ
                DCH3ECONbits.AIRQEN = 1;             // Enable Abort IRQ
                DCH3CONbits.CHPRI = 3;               // The priority of this channel is 3 (highest)
                DCH3CONbits.CHEN = 1;                // Turn this channel on now
                DCH3CONbits.CHAEN=1;
                DCH3ECONbits.CFORCE = 1;             // Force the start of the transfer now
                DMACONSET=0x8000;  // Turn the DMA module on
                break;
    }                 
}
