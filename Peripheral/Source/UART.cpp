#include "UART.h"
void UART::begin()
{
    switch(CH)
    {
        case 1:
            U1MODE=0;   
            U1MODEbits.BRGH=1;
            U1BRG=(PBFreq/(4*baudRate))-1;
            U1MODEbits.PDSEL=Mode&0b11;
            U1MODEbits.STSEL=(Mode&0b100)>>2;
            U1MODEbits.ON=1;
            U1STA=0;
            U1STAbits.URXEN=1;
            U1STAbits.UTXEN=1;
            IFS0bits.U1RXIF=0;
            IEC0bits.U1RXIE =0;
            break;
        case 2:
            U2MODE=0;   
            U2MODEbits.BRGH=1;
            U2BRG=(PBFreq/(4*baudRate))-1;
            U2MODEbits.PDSEL=Mode&0b11;
            U2MODEbits.STSEL=(Mode&0b100)>>2;
            U2MODEbits.ON=1;
            U2STA=0;
            U2STAbits.URXEN=1;
            U2STAbits.UTXEN=1;
            IFS1bits.U2RXIF=0;
            IEC1bits.U2RXIE =0;
            break;
        case 3:
            U3MODE=0;   
            U3MODEbits.BRGH=1;
            U3BRG=(PBFreq/(4*baudRate))-1;
            U3MODEbits.PDSEL=Mode&0b11;
            U3MODEbits.STSEL=(Mode&0b100)>>2;
            U3MODEbits.ON=1;
            U3STA=0;
            U3STAbits.URXEN=1;
            U3STAbits.UTXEN=1;
            IFS1bits.U3RXIF=0;
            IEC1bits.U3RXIE =0;
            break;
        case 4:
            U4MODE=0;   
            U4MODEbits.BRGH=1;
            U4BRG=(PBFreq/(4*baudRate))-1;
            U4MODEbits.PDSEL=Mode&0b11;
            U4MODEbits.STSEL=(Mode&0b100)>>2;
            U4MODEbits.ON=1;
            U4STA=0;
            U4STAbits.URXEN=1;
            U4STAbits.UTXEN=1;
            IFS2bits.U4RXIF=0;
            IEC2bits.U4RXIE =0;
            break;
        case 5:
            U5MODE=0;   
            U5MODEbits.BRGH=1;
            U5BRG=(PBFreq/(4*baudRate))-1;
            U5MODEbits.PDSEL=Mode&0b11;
            U5MODEbits.STSEL=(Mode&0b100)>>2;
            U5MODEbits.ON=1;
            U5STA=0;
            U5STAbits.URXEN=1;
            U5STAbits.UTXEN=1;
            IFS2bits.U5RXIF=0;
            IEC2bits.U5RXIE =0;
            break;
        case 6:
            U6MODE=0;   
            U6MODEbits.BRGH=1;
            U6BRG=(PBFreq/(4*baudRate))-1;
            U6MODEbits.PDSEL=Mode&0b11;
            U6MODEbits.STSEL=(Mode&0b100)>>2;
            U6MODEbits.ON=1;
            U6STA=0;
            U6STAbits.URXEN=1;
            U6STAbits.UTXEN=1;
            IFS2bits.U6RXIF=0;
            IEC2bits.U6RXIE =0;
            break;
            
    }
}
void UART::begin(__uint8_t intPriority, __uint8_t intSubPriority)
{
    switch(CH)
    {
        case 1:
            U1MODE=0;   
            U1MODEbits.BRGH=1;
            U1BRG=(PBFreq/(4*baudRate))-1;
            U1MODEbits.PDSEL=Mode&0b11;
            U1MODEbits.STSEL=(Mode&0b100)>>2;
            U1MODEbits.ON=1;
            U1STA=0;
            U1STAbits.URXEN=1;
            U1STAbits.UTXEN=1;
            IPC6bits.U1IP=intPriority;
            IPC6bits.U1IS=intSubPriority;
            IFS0bits.U1RXIF=0;
            IEC0bits.U1RXIE =1;
            break;
        case 2:
            U2MODE=0;   
            U2MODEbits.BRGH=1;
            U2BRG=(PBFreq/(4*baudRate))-1;
            U2MODEbits.PDSEL=Mode&0b11;
            U2MODEbits.STSEL=(Mode&0b100)>>2;
            U2MODEbits.ON=1;
            U2STA=0;
            U2STAbits.URXEN=1;
            U2STAbits.UTXEN=1;
            IPC8bits.U2IP=intPriority;
            IPC8bits.U2IS=intSubPriority;
            IFS1bits.U2RXIF=0;
            IEC1bits.U2RXIE =1;
            break;
        case 3:
            U3MODE=0;   
            U3MODEbits.BRGH=1;
            U3BRG=(PBFreq/(4*baudRate))-1;
            U3MODEbits.PDSEL=Mode&0b11;
            U3MODEbits.STSEL=(Mode&0b100)>>2;
            U3MODEbits.ON=1;
            U3STA=0;
            U3STAbits.URXEN=1;
            U3STAbits.UTXEN=1;
            IPC7bits.U3IP=intPriority;
            IPC7bits.U3IS=intSubPriority;
            IFS1bits.U3RXIF=0;
            IEC1bits.U3RXIE =1;
            break;
        case 4:
            U4MODE=0;   
            U4MODEbits.BRGH=1;
            U4BRG=(PBFreq/(4*baudRate))-1;
            U4MODEbits.PDSEL=Mode&0b11;
            U4MODEbits.STSEL=(Mode&0b100)>>2;
            U4MODEbits.ON=1;
            U4STA=0;
            U4STAbits.URXEN=1;
            U4STAbits.UTXEN=1;
            IPC12bits.U4IP=intPriority;
            IPC12bits.U4IS=intSubPriority;
            IFS2bits.U4RXIF=0;
            IEC2bits.U4RXIE =1;
            break;
        case 5:
            U5MODE=0;   
            U5MODEbits.BRGH=1;
            U5BRG=(PBFreq/(4*baudRate))-1;
            U5MODEbits.PDSEL=Mode&0b11;
            U5MODEbits.STSEL=(Mode&0b100)>>2;
            U5MODEbits.ON=1;
            U5STA=0;
            U5STAbits.URXEN=1;
            U5STAbits.UTXEN=1;
            IPC12bits.U5IP=intPriority;
            IPC12bits.U5IS=intSubPriority;
            IFS2bits.U5RXIF=0;
            IEC2bits.U5RXIE =1;
            break;
        case 6:
            U6MODE=0;   
            U6MODEbits.BRGH=1;
            U6BRG=(PBFreq/(4*baudRate))-1;
            U6MODEbits.PDSEL=Mode&0b11;
            U6MODEbits.STSEL=(Mode&0b100)>>2;
            U6MODEbits.ON=1;
            U6STA=0;
            U6STAbits.URXEN=1;
            U6STAbits.UTXEN=1;
            IPC12bits.U6IP=intPriority;
            IPC12bits.U6IS=intSubPriority;
            IFS2bits.U6RXIF=0;
            IEC2bits.U6RXIE =1;
            break;
            
    }    
}
bool UART::available()
{
    bool AD=0;
    switch (CH)
    {
        case 1: AD = U1STAbits.URXDA;break;
        case 2: AD = U2STAbits.URXDA;break;
        case 3: AD = U3STAbits.URXDA;break;
        case 4: AD = U4STAbits.URXDA;break;
        case 5: AD = U5STAbits.URXDA;break;
        case 6: AD = U6STAbits.URXDA;break;
    }
    return AD; 
}
uint8_t UART::read()
{
    uint8_t data=0;
    switch (CH)
    {
        case 1: data = U1RXREG;break;
        case 2: data = U2RXREG;break;
        case 3: data = U3RXREG;break;
        case 4: data = U4RXREG;break;
        case 5: data = U5RXREG;break;
        case 6: data = U6RXREG;break;
    }
    return data; 
}
void UART::write(__uint8_t data)
{
    switch (CH)
    {
        case 1: U1TXREG = data;while(U1STAbits.UTXBF);break;
        case 2: U2TXREG = data;while(U2STAbits.UTXBF);break;
        case 3: U3TXREG = data;while(U3STAbits.UTXBF);break;
        case 4: U4TXREG = data;while(U4STAbits.UTXBF);break;
        case 5: U5TXREG = data;while(U5STAbits.UTXBF);break;
        case 6: U6TXREG = data;while(U6STAbits.UTXBF);break;
    }
}
void UART::flush()
{
    switch (CH)
    {
        case 1: while(U1STAbits.TRMT);break;
        case 2: while(U2STAbits.TRMT);break;
        case 3: while(U3STAbits.TRMT);break;
        case 4: while(U4STAbits.TRMT);break;
        case 5: while(U5STAbits.TRMT);break;
        case 6: while(U6STAbits.TRMT);break;
    }
}
void UART::end()
{
    switch (CH)
    {
        case 1: U1MODE=0;break;
        case 2: U2MODE=0;break;
        case 3: U3MODE=0;break;
        case 4: U4MODE=0;break;
        case 5: U5MODE=0;break;
        case 6: U6MODE=0;break;
    }
}
void UART::puts(const char* string)
{
    int i=0;
    while(string[i]!='\0')
    {
        write(string[i]);
        i++;
    }
}
