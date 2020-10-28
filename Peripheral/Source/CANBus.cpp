#include "CANBus.h"
CANBus::CANBus(uint8_t CANModule,uint32_t PBFreq,uint32_t CANBusSpeed)
{
     
}
void CANBus::Transfer(__uint8_t CANModule,uint8_t CANChannel)
{
    switch(CANChannel)
    {
        case CAN_CHANNEL0:
            C1FIFOCON0SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON0SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL1:
            C1FIFOCON1SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON1SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL2:
            C1FIFOCON2SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON2SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL3:
            C1FIFOCON3SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON3SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL4:
            C1FIFOCON4SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON4SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL5:
            C1FIFOCON5SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON5SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL6:
            C1FIFOCON6SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON6SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL7:
            C1FIFOCON7SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON7SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL8:
            C1FIFOCON8SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON8SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL9:
            C1FIFOCON9SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON9SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL10:
            C1FIFOCON10SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON10SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL11:
            C1FIFOCON11SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON11SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL12:
            C1FIFOCON12SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON12SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL13:
            C1FIFOCON13SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON13SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL14:
            C1FIFOCON14SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON14SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL15:
            C1FIFOCON15SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON15SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL16:
            C1FIFOCON16SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON16SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL17:
            C1FIFOCON17SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON17SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL18:
            C1FIFOCON18SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON18SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL19:
            C1FIFOCON19SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON19SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL20:
            C1FIFOCON20SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON20SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL21:
            C1FIFOCON21SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON21SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL22:
            C1FIFOCON22SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON22SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL23:
            C1FIFOCON23SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON23SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL24:
            C1FIFOCON24SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON24SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL25:
            C1FIFOCON25SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON25SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL26:
            C1FIFOCON26SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON26SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL27:
            C1FIFOCON27SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON27SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL28:
            C1FIFOCON28SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON28SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL29:
            C1FIFOCON29SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON29SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL30:
            C1FIFOCON30SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON30SET = 0x00000008;/* Set the TXREQ bit */
            break;
            case CAN_CHANNEL31:
            C1FIFOCON31SET = 0x00002000;/* Set the UINC bit */
            C1FIFOCON31SET = 0x00000008;/* Set the TXREQ bit */
            break;
    } 
}
void CANBus::FillTransmitBuff(__uint32_t FIFOAddress, __uint32_t StandardID,uint8_t Data0)
{
    /* Pointer to CAN Message Buffer */
    CANTxMessageBuffer * transmitMessage; 
    /* Get the address of the message buffer to write to. Load the buffer and */
    /* then set the UINC bit. Set the TXREQ bit next to send the message. */
    transmitMessage = (CANTxMessageBuffer *)(PA_TO_KVA1(FIFOAddress));
    transmitMessage->CMSGSID.SID = StandardID;/* CMSGSID */
    transmitMessage->CMSGEID.IDE = 0;
    transmitMessage->CMSGEID.DLC = 1;
    transmitMessage->CMSGDATA0.Byte0=Data0;
}
void CANBus::FillTransmitBuff(__uint32_t FIFOAddress, __uint32_t StandardID,uint8_t Data0,uint8_t Data1)
{
    /* Pointer to CAN Message Buffer */
    CANTxMessageBuffer * transmitMessage; 
    /* Get the address of the message buffer to write to. Load the buffer and */
    /* then set the UINC bit. Set the TXREQ bit next to send the message. */
    transmitMessage = (CANTxMessageBuffer *)(PA_TO_KVA1(FIFOAddress));
    transmitMessage->CMSGSID.SID = StandardID;/* CMSGSID */
    transmitMessage->CMSGEID.IDE = 0;
    transmitMessage->CMSGEID.DLC = 2;
    transmitMessage->CMSGDATA0.Byte0=Data0;
    transmitMessage->CMSGDATA0.Byte1=Data1;
}
void CANBus::FillTransmitBuff(__uint32_t FIFOAddress, __uint32_t StandardID,uint8_t Data0,uint8_t Data1,uint8_t Data2)
{
    /* Pointer to CAN Message Buffer */
    CANTxMessageBuffer * transmitMessage; 
    /* Get the address of the message buffer to write to. Load the buffer and */
    /* then set the UINC bit. Set the TXREQ bit next to send the message. */
    transmitMessage = (CANTxMessageBuffer *)(PA_TO_KVA1(FIFOAddress));
    transmitMessage->CMSGSID.SID = StandardID;/* CMSGSID */
    transmitMessage->CMSGEID.IDE = 0;
    transmitMessage->CMSGEID.DLC = 3;
    transmitMessage->CMSGDATA0.Byte0=Data0;
    transmitMessage->CMSGDATA0.Byte1=Data1;
    transmitMessage->CMSGDATA0.Byte2=Data2;
}
void CANBus::FillTransmitBuff(__uint32_t FIFOAddress, __uint32_t StandardID,uint8_t Data0,uint8_t Data1,uint8_t Data2,uint8_t Data3)
{
    /* Pointer to CAN Message Buffer */
    CANTxMessageBuffer * transmitMessage; 
    /* Get the address of the message buffer to write to. Load the buffer and */
    /* then set the UINC bit. Set the TXREQ bit next to send the message. */
    transmitMessage = (CANTxMessageBuffer *)(PA_TO_KVA1(FIFOAddress));
    transmitMessage->CMSGSID.SID = StandardID;/* CMSGSID */
    transmitMessage->CMSGEID.IDE = 0;
    transmitMessage->CMSGEID.DLC = 4;
    transmitMessage->CMSGDATA0.Byte0=Data0;
    transmitMessage->CMSGDATA0.Byte1=Data1;
    transmitMessage->CMSGDATA0.Byte2=Data2;
    transmitMessage->CMSGDATA0.Byte3=Data3;    
}
void CANBus::FillTransmitBuff(__uint32_t FIFOAddress, __uint32_t StandardID,uint8_t Data0,uint8_t Data1,uint8_t Data2,uint8_t Data3,uint8_t Data4)
{
    /* Pointer to CAN Message Buffer */
    CANTxMessageBuffer * transmitMessage; 
    /* Get the address of the message buffer to write to. Load the buffer and */
    /* then set the UINC bit. Set the TXREQ bit next to send the message. */
    transmitMessage = (CANTxMessageBuffer *)(PA_TO_KVA1(FIFOAddress));
    transmitMessage->CMSGSID.SID = StandardID;/* CMSGSID */
    transmitMessage->CMSGEID.IDE = 0;
    transmitMessage->CMSGEID.DLC = 5;
    transmitMessage->CMSGDATA0.Byte0=Data0;
    transmitMessage->CMSGDATA0.Byte1=Data1;
    transmitMessage->CMSGDATA0.Byte2=Data2;
    transmitMessage->CMSGDATA0.Byte3=Data3;
    transmitMessage->CMSGDATA1.Byte0=Data4;
}
void CANBus::FillTransmitBuff(__uint32_t FIFOAddress, __uint32_t StandardID,uint8_t Data0,uint8_t Data1,uint8_t Data2,uint8_t Data3,uint8_t Data4,uint8_t Data5)
{
    /* Pointer to CAN Message Buffer */
    CANTxMessageBuffer * transmitMessage; 
    /* Get the address of the message buffer to write to. Load the buffer and */
    /* then set the UINC bit. Set the TXREQ bit next to send the message. */
    transmitMessage = (CANTxMessageBuffer *)(PA_TO_KVA1(FIFOAddress));
    transmitMessage->CMSGSID.SID = StandardID;/* CMSGSID */
    transmitMessage->CMSGEID.IDE = 0;
    transmitMessage->CMSGEID.DLC = 6;
    transmitMessage->CMSGDATA0.Byte0=Data0;
    transmitMessage->CMSGDATA0.Byte1=Data1;
    transmitMessage->CMSGDATA0.Byte2=Data2;
    transmitMessage->CMSGDATA0.Byte3=Data3;
    transmitMessage->CMSGDATA1.Byte0=Data4;
    transmitMessage->CMSGDATA1.Byte1=Data5;
}
void CANBus::FillTransmitBuff(__uint32_t FIFOAddress, __uint32_t StandardID,uint8_t Data0,uint8_t Data1,uint8_t Data2,uint8_t Data3,uint8_t Data4,uint8_t Data5,uint8_t Data6)
{
    /* Pointer to CAN Message Buffer */
    CANTxMessageBuffer * transmitMessage; 
    /* Get the address of the message buffer to write to. Load the buffer and */
    /* then set the UINC bit. Set the TXREQ bit next to send the message. */
    transmitMessage = (CANTxMessageBuffer *)(PA_TO_KVA1(FIFOAddress));
    transmitMessage->CMSGSID.SID = StandardID;/* CMSGSID */
    transmitMessage->CMSGEID.IDE = 0;
    transmitMessage->CMSGEID.DLC = 7;
    transmitMessage->CMSGDATA0.Byte0=Data0;
    transmitMessage->CMSGDATA0.Byte1=Data1;
    transmitMessage->CMSGDATA0.Byte2=Data2;
    transmitMessage->CMSGDATA0.Byte3=Data3;
    transmitMessage->CMSGDATA1.Byte0=Data4;
    transmitMessage->CMSGDATA1.Byte1=Data5;
    transmitMessage->CMSGDATA1.Byte2=Data6;
}
void CANBus::FillTransmitBuff(__uint32_t FIFOAddress, __uint32_t StandardID,uint8_t Data0,uint8_t Data1,uint8_t Data2,uint8_t Data3,uint8_t Data4,uint8_t Data5,uint8_t Data6,uint8_t Data7)
{
    /* Pointer to CAN Message Buffer */
    CANTxMessageBuffer * transmitMessage; 
    /* Get the address of the message buffer to write to. Load the buffer and */
    /* then set the UINC bit. Set the TXREQ bit next to send the message. */
    transmitMessage = (CANTxMessageBuffer *)(PA_TO_KVA1(FIFOAddress));
    transmitMessage->CMSGSID.SID = StandardID;/* CMSGSID */
    transmitMessage->CMSGEID.IDE = 0;
    transmitMessage->CMSGEID.DLC = 8;
    transmitMessage->CMSGDATA0.Byte0=Data0;
    transmitMessage->CMSGDATA0.Byte1=Data1;
    transmitMessage->CMSGDATA0.Byte2=Data2;
    transmitMessage->CMSGDATA0.Byte3=Data3;
    transmitMessage->CMSGDATA1.Byte0=Data4;
    transmitMessage->CMSGDATA1.Byte1=Data5;
    transmitMessage->CMSGDATA1.Byte2=Data6;
    transmitMessage->CMSGDATA1.Byte3=Data7;
}

void CANBus::ExtendedTransmit(__uint32_t FIFOAddress, __uint32_t ExtendedID, __uint8_t DataLength)
{
    /* Pointer to CAN Message Buffer */
    CANTxMessageBuffer * transmitMessage; 
    /* Get the address of the message buffer to write to. Load the buffer and */
    /* then set the UINC bit. Set the TXREQ bit next to send the message. */
    transmitMessage = (CANTxMessageBuffer *)(PA_TO_KVA1(FIFOAddress));
    transmitMessage->CMSGEID.EID = ExtendedID;/* CMSGSID */
    transmitMessage->CMSGEID.IDE = 0;
    transmitMessage->CMSGEID.DLC = DataLength;
    transmitMessage->messageWord[2] = 0x12BC1245;/* CMSGDAT0 */
    C1FIFOCON1SET = 0x00002000;/* Set the UINC bit */
    C1FIFOCON1SET = 0x00000008;/* Set the TXREQ bit */
}
void CANBus::ConfigureFilter(__uint8_t CANModule, __uint8_t FilterNo, __uint32_t FilterID, __uint8_t DataMode)
{
    /* This code example shows how to configure a filter to match a Standard */
    /* Identifier (SID) CAN message. */
    /* In this example, Filter 3 is set up to accept messages with a SID range */
    /* of 0x100 to 103. Accepted messages will be stored in FIFO5. Mask 1 is */
    /* used to implement the filter address range. */
    C1FLTCON0bits.FSEL0 = 0;/* Store messages in FIFO5 */
    C1FLTCON0bits.MSEL0 = 0;/* Use Mask 1 */
    C1RXF0bits.SID = FilterID;/* Filter 3 SID */
    C1RXF0bits.EXID = 0;/* Filter only SID messages */
    C1RXM1bits.SID = 0x7FC;/* Ignore last 2 bits in comparison */
    C1RXM1bits.MIDE = 1;/* Match only message types. */
    C1FLTCON0bits.FLTEN0 = 1;/* Enable the filter */
    /* Filter is now configured. */
}
void CANBus::ConfigureChannelForTx(__uint8_t CANModule, __uint8_t CANChannel, __uint8_t BufferMode)
{
    if(CANModule == CAN1)
    {
        switch (CANChannel)
        {
            case CAN_CHANNEL0:
                /* Configure FIFO0 */
                C1FIFOCON0bits.FSIZE = 1;
                C1FIFOCON0SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL1:
                /* Configure FIFO1 */
                C1FIFOCON1bits.FSIZE = 1;
                C1FIFOCON1SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL2:
                /* Configure FIFO2 */
                C1FIFOCON2bits.FSIZE = 1;
                C1FIFOCON2SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL3:
                /* Configure FIFO3 */
                C1FIFOCON3bits.FSIZE = 1;
                C1FIFOCON3SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL4:
                /* Configure FIFO4 */
                C1FIFOCON4bits.FSIZE = 1;
                C1FIFOCON4SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL5:
                /* Configure FIFO5 */
                C1FIFOCON5bits.FSIZE = 1;
                C1FIFOCON5SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL6:
                /* Configure FIFO6 */
                C1FIFOCON6bits.FSIZE = 1;
                C1FIFOCON6SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL7:
                /* Configure FIFO7 */
                C1FIFOCON7bits.FSIZE = 1;
                C1FIFOCON7SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL8:
                /* Configure FIFO8 */
                C1FIFOCON8bits.FSIZE = 1;
                C1FIFOCON8SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL9:
                /* Configure FIFO9 */
                C1FIFOCON9bits.FSIZE = 1;
                C1FIFOCON9SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL10:
                /* Configure FIFO10 */
                C1FIFOCON10bits.FSIZE = 1;
                C1FIFOCON10SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL11:
                /* Configure FIFO11 */
                C1FIFOCON11bits.FSIZE = 1;
                C1FIFOCON11SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL12:
                /* Configure FIFO12 */
                C1FIFOCON12bits.FSIZE = 1;
                C1FIFOCON12SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL13:
                /* Configure FIFO13 */
                C1FIFOCON13bits.FSIZE = 1;
                C1FIFOCON13SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL14:
                /* Configure FIFO14 */
                C1FIFOCON14bits.FSIZE = 1;
                C1FIFOCON14SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL15:
                /* Configure FIFO0 */
                C1FIFOCON15bits.FSIZE = 1;
                C1FIFOCON15SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL16:
                /* Configure FIFO16 */
                C1FIFOCON16bits.FSIZE = 1;
                C1FIFOCON16SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL17:
                /* Configure FIFO17 */
                C1FIFOCON17bits.FSIZE = 1;
                C1FIFOCON17SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL18:
                /* Configure FIFO18 */
                C1FIFOCON18bits.FSIZE = 1;
                C1FIFOCON18SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL19:
                /* Configure FIFO19 */
                C1FIFOCON19bits.FSIZE = 1;
                C1FIFOCON19SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL20:
                /* Configure FIFO20 */
                C1FIFOCON20bits.FSIZE = 1;
                C1FIFOCON20SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL21:
                /* Configure FIFO21 */
                C1FIFOCON21bits.FSIZE = 1;
                C1FIFOCON21SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL22:
                /* Configure FIFO22 */
                C1FIFOCON22bits.FSIZE = 1;
                C1FIFOCON22SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL23:
                /* Configure FIFO23 */
                C1FIFOCON23bits.FSIZE = 1;
                C1FIFOCON23SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL24:
                /* Configure FIFO24 */
                C1FIFOCON24bits.FSIZE = 1;
                C1FIFOCON24SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL25:
                /* Configure FIFO25 */
                C1FIFOCON25bits.FSIZE = 1;
                C1FIFOCON25SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL26:
                /* Configure FIFO26 */
                C1FIFOCON26bits.FSIZE = 1;
                C1FIFOCON26SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL27:
                /* Configure FIFO27 */
                C1FIFOCON27bits.FSIZE = 1;
                C1FIFOCON27SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL28:
                /* Configure FIFO28 */
                C1FIFOCON28bits.FSIZE = 1;
                C1FIFOCON28SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL29:
                /* Configure FIFO29 */
                C1FIFOCON29bits.FSIZE = 1;
                C1FIFOCON29SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL30:
                /* Configure FIFO30 */
                C1FIFOCON30bits.FSIZE = 1;
                C1FIFOCON30SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL31:
                /* Configure FIFO31 */
                C1FIFOCON31bits.FSIZE = 1;
                C1FIFOCON31SET = 0x80;/* Set the TXEN bit */
                break;
        }
    }
    else if(CANModule == CAN2)
    {
        switch (CANChannel)
        {
            case CAN_CHANNEL0:
                /* Configure FIFO0 */
                C2FIFOCON0bits.FSIZE = 1;
                C2FIFOCON0SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL1:
                /* Configure FIFO1 */
                C2FIFOCON1bits.FSIZE = 1;
                C2FIFOCON1SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL2:
                /* Configure FIFO2 */
                C2FIFOCON2bits.FSIZE = 1;
                C2FIFOCON2SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL3:
                /* Configure FIFO3 */
                C2FIFOCON3bits.FSIZE = 1;
                C2FIFOCON3SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL4:
                /* Configure FIFO4 */
                C2FIFOCON4bits.FSIZE = 1;
                C2FIFOCON4SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL5:
                /* Configure FIFO5 */
                C2FIFOCON5bits.FSIZE = 1;
                C2FIFOCON5SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL6:
                /* Configure FIFO6 */
                C2FIFOCON6bits.FSIZE = 1;
                C2FIFOCON6SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL7:
                /* Configure FIFO7 */
                C2FIFOCON7bits.FSIZE = 1;
                C2FIFOCON7SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL8:
                /* Configure FIFO8 */
                C2FIFOCON8bits.FSIZE = 1;
                C2FIFOCON8SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL9:
                /* Configure FIFO9 */
                C2FIFOCON9bits.FSIZE = 1;
                C2FIFOCON9SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL10:
                /* Configure FIFO10 */
                C2FIFOCON10bits.FSIZE = 1;
                C2FIFOCON10SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL11:
                /* Configure FIFO11 */
                C2FIFOCON11bits.FSIZE = 1;
                C2FIFOCON11SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL12:
                /* Configure FIFO12 */
                C2FIFOCON12bits.FSIZE = 1;
                C2FIFOCON12SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL13:
                /* Configure FIFO13 */
                C2FIFOCON13bits.FSIZE = 1;
                C2FIFOCON13SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL14:
                /* Configure FIFO14 */
                C2FIFOCON14bits.FSIZE = 1;
                C2FIFOCON14SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL15:
                /* Configure FIFO0 */
                C2FIFOCON15bits.FSIZE = 1;
                C2FIFOCON15SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL16:
                /* Configure FIFO16 */
                C2FIFOCON16bits.FSIZE = 1;
                C2FIFOCON16SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL17:
                /* Configure FIFO17 */
                C2FIFOCON17bits.FSIZE = 1;
                C2FIFOCON17SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL18:
                /* Configure FIFO18 */
                C2FIFOCON18bits.FSIZE = 1;
                C2FIFOCON18SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL19:
                /* Configure FIFO19 */
                C2FIFOCON19bits.FSIZE = 1;
                C2FIFOCON19SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL20:
                /* Configure FIFO20 */
                C2FIFOCON20bits.FSIZE = 1;
                C2FIFOCON20SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL21:
                /* Configure FIFO21 */
                C2FIFOCON21bits.FSIZE = 1;
                C2FIFOCON21SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL22:
                /* Configure FIFO22 */
                C2FIFOCON22bits.FSIZE = 1;
                C2FIFOCON22SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL23:
                /* Configure FIFO23 */
                C2FIFOCON23bits.FSIZE = 1;
                C2FIFOCON23SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL24:
                /* Configure FIFO24 */
                C2FIFOCON24bits.FSIZE = 1;
                C2FIFOCON24SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL25:
                /* Configure FIFO25 */
                C2FIFOCON25bits.FSIZE = 1;
                C2FIFOCON25SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL26:
                /* Configure FIFO26 */
                C2FIFOCON26bits.FSIZE = 1;
                C2FIFOCON26SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL27:
                /* Configure FIFO27 */
                C2FIFOCON27bits.FSIZE = 1;
                C2FIFOCON27SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL28:
                /* Configure FIFO28 */
                C2FIFOCON28bits.FSIZE = 1;
                C2FIFOCON28SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL29:
                /* Configure FIFO29 */
                C2FIFOCON29bits.FSIZE = 1;
                C2FIFOCON29SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL30:
                /* Configure FIFO30 */
                C2FIFOCON30bits.FSIZE = 1;
                C2FIFOCON30SET = 0x80;/* Set the TXEN bit */
                break;
            case CAN_CHANNEL31:
                /* Configure FIFO31 */
                C2FIFOCON31bits.FSIZE = 1;
                C2FIFOCON31SET = 0x80;/* Set the TXEN bit */
                break;
        }
    }
    
}
void CANBus::ConfigureChannelForRx(__uint8_t CANModule, __uint8_t CANChannel, __uint8_t BufferMode)
{
    if(CANModule == CAN1)
    {
        switch (CANChannel)
        {
            case CAN_CHANNEL0:
                if(BufferMode == CAN_RX_FULL_RECEIVE)
                {
                    /* Configure FIFO0 */
                    C1FIFOCON0bits.FSIZE = 2;
                    C1FIFOCON0CLR = 0x80;/* Clear the TXEN bit */
                }
                else if(BufferMode == CAN_RX_DATA_ONLY)
                {
                    /* Configure FIFO0 */
                    C1FIFOCON0bits.FSIZE = 1;
                    C1FIFOCON0CLR = 0x80;/* Clear the TXEN bit */
                }
                else if(BufferMode == CAN_TX_RTR_DISABLED)
                {
                    /* Configure FIFO0 */
                    C1FIFOCON0bits.FSIZE = 1;
                    C1FIFOCON0SET = 0x80;/* Set the TXEN bit */
                }
                break;
        }
    }
    else if(CANModule == CAN2)
    {
        switch (CANChannel)
        {
            case CAN_CHANNEL0:
                if(BufferMode == CAN_RX_FULL_RECEIVE)
                {
                    /* Configure FIFO0 */
                    C2FIFOCON0bits.FSIZE = 2;
                    C2FIFOCON0CLR = 0x80;/* Clear the TXEN bit */
                }
                else if(BufferMode == CAN_RX_DATA_ONLY)
                {
                    /* Configure FIFO0 */
                    C2FIFOCON0bits.FSIZE = 1;
                    C2FIFOCON0CLR = 0x80;/* Clear the TXEN bit */
                }
                else if(BufferMode == CAN_TX_RTR_DISABLED)
                {
                    /* Configure FIFO0 */
                    C2FIFOCON0bits.FSIZE = 1;
                    C2FIFOCON0SET = 0x80;/* Set the TXEN bit */
                }
                break;
        }
    }
}
void CANBus::AssignMemoryBuffer(__uint8_t CANModule,uint32_t BuffAddress)
{
    /* Initialize C1FIFOBA register with physical address of CAN message Buffer */
    C1FIFOBA = BuffAddress;
    
}
void CANBus::SetSpeed(__uint8_t CANModule, __uint32_t PhaseSeg1, __uint32_t PhaseSeg2,__uint32_t PropagationSeg,__uint8_t BRPValue)
{
    C1CFGbits.SEG2PHTS = 1;/* Phase seg 2 is freely programmable */
    C1CFGbits.SEG2PH = PhaseSeg2;/* Phase seg 2 is 3 Tq. */
    C1CFGbits.SEG1PH = PhaseSeg1;/* Phase seg 1 is 3 Tq. */
    C1CFGbits.PRSEG = PropagationSeg;/* Propagation seg 2 is 3 Tq. */
    C1CFGbits.SAM = 1;/* Sample bit 3 times. */
    C1CFGbits.SJW = 2;/* Sync jump width is 2 Tq */
    C1CFGbits.BRP = BRPValue;/* BRP value */
}
void CANBus::EnableModule(uint8_t CANModule, bool En)
{
    if(CANModule == CAN1)
    {
        /* Switch the CAN module on. */
        C1CONbits.ON = En;/*Set the ON bit */
        while(C1CONbits.CANBUSY == 1);
    }
    else if(CANModule == CAN2)
    {
        /* Switch the CAN module on. */
        C2CONbits.ON = En;/*Set the ON bit */
        while(C2CONbits.CANBUSY == 1);
    }
}
void CANBus::SetOperatingMode(uint8_t CANModule,uint8_t CanModuleMode)
{
    if(CANModule == CAN1)
    {
        if(CanModuleMode == CAN_CONFIGURATION)
        {
            /* Place the CAN module in Configuration mode. */
            C1CONbits.REQOP = 4;
            while(C1CONbits.OPMOD != 4);
        }
        else if(CanModuleMode == CAN_NORMAL_OPERATION)
        {
            /* The CAN module can now be placed into normal mode if no further */
            /* configuration is required. */
            C1CONbits.REQOP = 0;
            while(C1CONbits.OPMOD != 0);
        }
    }
    else if(CANModule == CAN2)
    {
        if(CanModuleMode == CAN_CONFIGURATION)
        {
            /* Place the CAN module in Configuration mode. */
            C2CONbits.REQOP = 4;
            while(C2CONbits.OPMOD != 4);
        }
        else if(CanModuleMode == CAN_NORMAL_OPERATION)
        {
            /* The CAN module can now be placed into normal mode if no further */
            /* configuration is required. */
            C2CONbits.REQOP = 0;
            while(C2CONbits.OPMOD != 0);
        }
    }
}
void CANBus::EnableChannelEvent(__uint8_t CANModule, __uint8_t CANChannel, __uint16_t EventMode, __uint8_t En)
{
    if( CANModule == CAN1 )
    {
        C1FIFOINT0=( (EventMode*En) <<16 );     
    }
    else if(CANModule == CAN2)
    {
        C2FIFOINT0=EventMode<<16;     
    } 
}
void CANBus::EnableModuleEvent(__uint8_t CANModule, __uint8_t Periority, __uint8_t SubPeriority, __uint8_t En)
{
    if(CANModule == CAN1)
    {
        C1INTbits.RBIF=0;
        C1INTbits.RBIE=En;
        IPC11bits.CAN1IP=Periority;
        IPC11bits.CAN1IS=SubPeriority;
        IFS1bits.CAN1IF=0;
        IEC1bits.CAN1IE =En;
    }
    else if(CANModule == CAN2)
    {
        C2INTbits.RBIF=0;
        C2INTbits.RBIE=En;
        IPC11bits.CAN2IP=Periority;
        IPC11bits.CAN2IS=SubPeriority;
        IFS1bits.CAN2IF=0;
        IEC1bits.CAN2IE =En;
    }
}
