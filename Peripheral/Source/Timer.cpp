#include "Timer.h"
Timer::Timer(uint8_t channel,bool ClockSource,uint8_t PreScaler)
{
    TimerChannel=channel;
    switch (TimerChannel)
    {
       case Timer1:
            T1CON=0;
            T1CONbits.TCKPS = PreScaler;
            T1CONbits.TCS = ClockSource;           
            IFS0bits.T1IF = 0;  // Clear interrupt flag for timer 2
            IEC0bits.T1IE = 0;  // Disable Timer 2 Interrupt             
            break;
       case Timer2:
            T2CON=0;
            T2CONbits.TCKPS = PreScaler;
            T2CONbits.TCS = ClockSource;
            IFS0bits.T2IF = 0;  // Clear interrupt flag for timer 2
            IEC0bits.T2IE = 0;  // Disable Timer 2 Interrupt
            break;
       case Timer3:
            T3CON=0;
            T3CONbits.TCKPS = PreScaler;
            T3CONbits.TCS = ClockSource;           
            IFS0bits.T3IF = 0;  // Clear interrupt flag for timer 2
            IEC0bits.T3IE = 0;  // Disable Timer 2 Interrupt
            break;
       case Timer4:
            T4CON=0;
            T4CONbits.TCKPS = PreScaler;
            T4CONbits.TCS = ClockSource;           
            IFS0bits.T4IF = 0;  // Clear interrupt flag for timer 2
            IEC0bits.T4IE = 0;  // Disable Timer 2 Interrupt
            break;
       case Timer5:
            T5CON=0;
            T5CONbits.TCKPS = PreScaler;
            T5CONbits.TCS = ClockSource;         
            IFS0bits.T5IF = 0;  // Clear interrupt flag for timer 2
            IEC0bits.T5IE = 0;  // Disable Timer 2 Interrupt
            break;
       case Timer2va3://32bit Mode
            T2CON=0;
            T3CON=0;
            T2CONbits.T32 = 1;
            T2CONbits.TCKPS = PreScaler;
            T2CONbits.TCS = ClockSource;
            IFS0bits.T1IF = 0;  // Clear interrupt flag for timer 2
            IEC0bits.T1IE = 0;  // Disable Timer 2 Interrupt
            break;
       case Timer4va5://32bit Mode
            T5CON=0;
            T4CON=0;
            T4CONbits.T32 = 1;
            T4CONbits.TCKPS = PreScaler;
            T4CONbits.TCS = ClockSource;
            IFS0bits.T4IF = 0;  // Clear interrupt flag for timer 2
            IEC0bits.T4IE = 0;  // Disable Timer 2 Interrupt
            break;         
    }
}
Timer::Timer(uint8_t channel,bool ClockSource,uint8_t PreScaler,bool IntEn,uint8_t priority,uint8_t Subpriority)
{
    TimerChannel=channel;
    switch (TimerChannel)
    {
       case Timer1:
            T1CON=0;
            T1CONbits.TCKPS = PreScaler;
            T1CONbits.TCS = ClockSource;
            if(IntEn == IntEnableTimer)
            {
                IFS0bits.T1IF = 0;  // Clear interrupt flag for timer 2
                IPC1bits.T1IP = priority;  // Interrupt priority 3
                IPC1bits.T1IS = Subpriority;  // Sub-priority 1
                IEC0bits.T1IE = 1;  // Enable Timer 2 Interrupt
            }
            else
            {
                IFS0bits.T1IF = 0;  // Clear interrupt flag for timer 2
                IEC0bits.T1IE = 0;  // Disable Timer 2 Interrupt
            }  
            break;
       case Timer2:
            T2CON=0;
            T2CONbits.TCKPS = PreScaler;
            T2CONbits.TCS = ClockSource;
            if(IntEn == IntEnableTimer)
            {
                IFS0bits.T2IF = 0;  // Clear interrupt flag for timer 2
                IPC2bits.T2IP = priority;  // Interrupt priority 3
                IPC2bits.T2IS = Subpriority;  // Sub-priority 1
                IEC0bits.T2IE = 1;  // Enable Timer 2 Interrupt
            }
            else
            {
                IFS0bits.T2IF = 0;  // Clear interrupt flag for timer 2
                IEC0bits.T2IE = 0;  // Disable Timer 2 Interrupt
            } 
            break;
       case Timer3:
            T3CON=0;
            T3CONbits.TCKPS = PreScaler;
            T3CONbits.TCS = ClockSource;
            if(IntEn == IntEnableTimer)
            {
                IFS0bits.T3IF = 0;  // Clear interrupt flag for timer 2
                IPC3bits.T3IP = priority;  // Interrupt priority 3
                IPC3bits.T3IS = Subpriority;  // Sub-priority 1
                IEC0bits.T3IE = 1;  // Enable Timer 2 Interrupt
            }
            else
            {
                IFS0bits.T3IF = 0;  // Clear interrupt flag for timer 2
                IEC0bits.T3IE = 0;  // Disable Timer 2 Interrupt
            }
            break;
       case Timer4:
            T4CON=0;
            T4CONbits.TCKPS = PreScaler;
            T4CONbits.TCS = ClockSource;
            if(IntEn == IntEnableTimer)
            {
                IFS0bits.T4IF = 0;  // Clear interrupt flag for timer 2
                IPC4bits.T4IP = priority;  // Interrupt priority 3
                IPC4bits.T4IS = Subpriority;  // Sub-priority 1
                IEC0bits.T4IE = 1;  // Enable Timer 2 Interrupt
            }
            else
            {
                IFS0bits.T4IF = 0;  // Clear interrupt flag for timer 2
                IEC0bits.T4IE = 0;  // Disable Timer 2 Interrupt
            }
            break;
       case Timer5:
            T5CON=0;
            T5CONbits.TCKPS = PreScaler;
            T5CONbits.TCS = ClockSource;
            if(IntEn == IntEnableTimer)
            {
                IFS0bits.T5IF = 0;  // Clear interrupt flag for timer 2
                IPC5bits.T5IP = priority;  // Interrupt priority 3
                IPC5bits.T5IS = Subpriority;  // Sub-priority 1
                IEC0bits.T5IE = 1;  // Enable Timer 2 Interrupt
            }
            else
            {
                IFS0bits.T5IF = 0;  // Clear interrupt flag for timer 2
                IEC0bits.T5IE = 0;  // Disable Timer 2 Interrupt
            }
            break;
       case Timer2va3://32bit Mode
            T2CON=0;
            T3CON=0;
            T2CONbits.T32 = 1;
            T2CONbits.TCKPS = PreScaler;
            T2CONbits.TCS = ClockSource;
            if(IntEn == IntEnableTimer)
            {
                IFS0bits.T2IF = 0;  // Clear interrupt flag for timer 2
                IPC2bits.T2IP = priority;  // Interrupt priority 3
                IPC2bits.T2IS = Subpriority;  // Sub-priority 1
                IEC0bits.T2IE = 1;  // Enable Timer 2 Interrupt
            }
            else
            {
                IFS0bits.T1IF = 0;  // Clear interrupt flag for timer 2
                IEC0bits.T1IE = 0;  // Disable Timer 2 Interrupt
            }
            break;
       case Timer4va5://32bit Mode
            T5CON=0;
            T4CON=0;
            T4CONbits.T32 = 1;
            T4CONbits.TCKPS = PreScaler;
            T4CONbits.TCS = ClockSource;
            if(IntEn == IntEnableTimer)
            {
                IFS0bits.T4IF = 0;  // Clear interrupt flag for timer 2
                IPC4bits.T4IP = priority;  // Interrupt priority 3
                IPC4bits.T4IS = Subpriority;  // Sub-priority 1
                IEC0bits.T4IE = 1;  // Enable Timer 2 Interrupt
            }
            else
            {
                IFS0bits.T4IF = 0;  // Clear interrupt flag for timer 2
                IEC0bits.T4IE = 0;  // Disable Timer 2 Interrupt
            }
            break;         
    }
    
    
}
void Timer::On()
{
    switch (TimerChannel)
    {
        case Timer1:    T1CONbits.ON=1;break;
        case Timer2:    T2CONbits.ON=1;break;
        case Timer3:    T3CONbits.ON=1;break;
        case Timer4:    T4CONbits.ON=1;break;
        case Timer5:    T5CONbits.ON=1;break;
        case Timer2va3:  T2CONbits.ON=1;break;
        case Timer4va5:  T4CONbits.ON=1;break;
    }
}
void Timer::Off()
{
    switch (TimerChannel)
    {
        case Timer1:    T1CONbits.ON=0;break;
        case Timer2:    T2CONbits.ON=0;break;
        case Timer3:    T3CONbits.ON=0;break;
        case Timer4:    T4CONbits.ON=0;break;
        case Timer5:    T5CONbits.ON=0;break;
        case Timer2va3:  T2CONbits.ON=0;break;
        case Timer4va5:  T4CONbits.ON=0;break;
    }
}
bool Timer::getFlag()
{
    switch (TimerChannel)
    {
        case Timer1:    return IFS0bits.T1IF; break;
        case Timer2:    return IFS0bits.T2IF; break;
        case Timer3:    return IFS0bits.T3IF; break;
        case Timer4:    return IFS0bits.T4IF; break;
        case Timer5:    return IFS0bits.T5IF; break;
        case Timer2va3:    return IFS0bits.T2IF; break;
        case Timer4va5:    return IFS0bits.T4IF; break;
    }
}
void Timer::setPeriod(unsigned long PR)
{
    switch (TimerChannel)
    {
        case Timer1:    PR1 = PR; break;
        case Timer2:    PR2 = PR; break;
        case Timer3:    PR3 = PR; break;
        case Timer4:    PR4 = PR; break;
        case Timer5:    PR5 = PR; break;
        case Timer2va3:    PR2 = PR; break;
        case Timer4va5:    PR4 = PR; break;
    }
}
void Timer::setTimer(unsigned long TMR)
{
    switch (TimerChannel)
    {
        case Timer1:    TMR1 = TMR; break;
        case Timer2:    TMR2 = TMR; break;
        case Timer3:    TMR3 = TMR; break;
        case Timer4:    TMR4 = TMR; break;
        case Timer5:    TMR5 = TMR; break;
        case Timer2va3:    TMR2 = TMR; break;
        case Timer4va5:    TMR4 = TMR; break;
    }
}
