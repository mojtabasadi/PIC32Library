/* 
 * File:   CANBus.h
 * Author: Mojtaba
 *
 * Created on July 13, 2020, 11:31 AM
 */

#ifndef CANBUS_H
#define	CANBUS_H
#include <xc.h>
#include <sys/kmem.h>
// Section: Constants & Data Types
// *****************************************************************************
// *****************************************************************************

// Size of CAN TX and Full Receive RX Message Buffer in bytes.
#define CAN_TX_RX_MESSAGE_SIZE_BYTES 16    

// Size of CAN Data-Only RX Message Buffer in bytes.
#define CAN_RX_DATA_ONLY_SIZE_BYTES 8   


// *****************************************************************************
/* CAN Module

  Summary:
    Identifies the supported CAN Modules.

  Description:
    This enumeration identifies the available CAN modules.
*/

typedef enum  
{
#ifdef _CAN1
    CAN1,   // CAN Module 1 ID.
#endif

#ifdef _CAN2
    CAN2,    // CAN Module 2 ID.
#endif

    CAN_NUMBER_OF_MODULES   // Number of available CAN modules.

}CAN_MODULE;



// *****************************************************************************
/* CAN Channel

  Summary:
    Identifies the supported CAN Channels.

  Description:
    This enumeration identifies the available CAN channels. Each CAN channel
    can be configured to trasnmit and receive messages.    
*/   

typedef enum 
{
	CAN_CHANNEL0,       // Channel 0 ID
	CAN_CHANNEL1,       // Channel 1 ID
	CAN_CHANNEL2,       // Channel 2 ID
	CAN_CHANNEL3,       // Channel 3 ID
	CAN_CHANNEL4,       // Channel 4 ID
	CAN_CHANNEL5,       // Channel 5 ID
	CAN_CHANNEL6,       // Channel 6 ID
	CAN_CHANNEL7,       // Channel 7 ID
	CAN_CHANNEL8,       // Channel 8 ID
	CAN_CHANNEL9,       // Channel 9 ID
	CAN_CHANNEL10,      // Channel 10 ID
	CAN_CHANNEL11,      // Channel 11 ID
	CAN_CHANNEL12,      // Channel 12 ID
	CAN_CHANNEL13,      // Channel 13 ID
	CAN_CHANNEL14,      // Channel 14 ID
	CAN_CHANNEL15,      // Channel 15 ID
	CAN_CHANNEL16,      // Channel 16 ID
	CAN_CHANNEL17,      // Channel 17 ID
	CAN_CHANNEL18,      // Channel 18 ID
	CAN_CHANNEL19,      // Channel 19 ID
	CAN_CHANNEL20,      // Channel 20 ID
	CAN_CHANNEL21,      // Channel 21 ID
	CAN_CHANNEL22,      // Channel 22 ID
	CAN_CHANNEL23,      // Channel 23 ID
	CAN_CHANNEL24,      // Channel 24 ID
	CAN_CHANNEL25,      // Channel 25 ID
	CAN_CHANNEL26,      // Channel 26 ID
	CAN_CHANNEL27,      // Channel 27 ID
	CAN_CHANNEL28,      // Channel 28 ID
	CAN_CHANNEL29,      // Channel 29 ID
	CAN_CHANNEL30,      // Channel 30 ID
	CAN_CHANNEL31,      // Channel 31 ID
	CAN_ALL_CHANNELS    // This ID covers all channels. This ID can only
                        // be used with the CANAbortPendingTx() function.
		
}CAN_CHANNEL;

// *****************************************************************************
/* CAN Operation Mode

  Summary:
    Lists all possible CAN Module modes.

  Description:
    This enumerates all operating modes of the CAN module. The application
    should set the desired mode using the CANSetOperatingMode() function, and 
    should then use the CANGetOperatingMode() function to check if the CAN module
    has entered the requested mode. 
*/   

typedef enum 
{
    // CAN Normal Operation Mode. The CAN module
    // transmits and receives messages in this mode. 
	CAN_NORMAL_OPERATION,           

    // CAN Disable Mode. The CAN module does not transmit
    // or receive messages in this mode. 
	CAN_DISABLE,                   

    // CAN Loopback Mode. In this mode, the CAN module TX is
    // internally connected to the RX line. This mode is 
    // useful for debugging operation.  
	CAN_LOOPBACK,                   

    // CAN Listen Only Mode. In this mode, the CAN module will
    // not acknowledge signal and will not participate in error
    // signalling. All messages are captured.
	CAN_LISTEN_ONLY,                

    // CAN Configuration Mode. Various CAN module settings 
    // can be configured in this mode.
	CAN_CONFIGURATION,              

    // CAN Listen All Message Mode. The CAN module listens to all
    // messages, regardless of errors.
	CAN_LISTEN_ALL_MESSAGES = 7     

}CAN_OP_MODE;

// *****************************************************************************
/* CAN Channel Event

  Summary:
    Identifies all possible CAN Channel events.

  Description:
    This enumerates all CAN RX and TX channel events. This enumeration can be used
    to enable or disable channel events and as a mask to check if a channel event is
    active.
    A single or a combination of the events can be logically OR'ed to specify the
    event(s) to be enabled disabled or events to check. The CAN_RX_CHANNEL_xx_xx 
    events should only be used with a RX channel. The CAN_TX_CHANNEL_xx_xx events 
    should only be used with a TX channel. The CAN_xx_CHANNEL_ANY EVENT can be used
    to enable or disable all events or to check if any channel event is active.

    This enumeration is used by the CANGetChannelEvent() and CANEnableChannelEvent()
    functions.
*/   

typedef enum 
{
	CAN_RX_CHANNEL_NOT_EMPTY 	= 0x1,      // CAN RX Channel Not Empty Event Mask
	CAN_RX_CHANNEL_HALF_FULL 	= 0x2,      // CAN RX Channel Half Full Event Mask
	CAN_RX_CHANNEL_FULL 		= 0x4,      // CAN RX Channel Full Event Mask
	CAN_RX_CHANNEL_OVERFLOW 	= 0x8,      // CAN RX Channel Overflow Event Mask
	CAN_RX_CHANNEL_ANY_EVENT 	= 0xF,      // CAN RX Channel Any Event Mask
	CAN_TX_CHANNEL_EMPTY 		= 0x100,    // CAN TX Channel Empty Event Mask
	CAN_TX_CHANNEL_HALF_EMPTY 	= 0x200,    // CAN TX Channel Half Empty Event Mask
	CAN_TX_CHANNEL_NOT_FULL		= 0x400,    // CAN TX Channel Not Full Event Mask
	CAN_TX_CHANNEL_ANY_EVENT 	= 0x700     // CAN TX Channel Any Event Mask

}CAN_CHANNEL_EVENT;

// *****************************************************************************
/* CAN bit Time Quanta

  Summary:
    All possible values for the assignable number of Time Quanta. 

  Description:
    This enumeration defines values that can be assigned while defining the 
    number of Time Quanta in a bit. 
*/   

typedef enum 
{
	CAN_BIT_1TQ=1,    // 1-bit Time Quanta
	CAN_BIT_2TQ,    // 2-bit Time Quanta
	CAN_BIT_3TQ,    // 3-bit Time Quanta
	CAN_BIT_4TQ,    // 4-bit Time Quanta
	CAN_BIT_5TQ,    // 5-bit Time Quanta
	CAN_BIT_6TQ,    // 6-bit Time Quanta
	CAN_BIT_7TQ,    // 7-bit Time Quanta
	CAN_BIT_8TQ     // 8-bit Time Quanta

}CAN_BIT_TQ;

// *****************************************************************************
/* CAN bit Configuration

  Summary:
    Configuration of number of bit Time quanta in a CAN bit. 

  Description:
    This data structure provides an interface to the CAN bit configuration parameters.
    Note that the bit configuration affects the CAN Bus Speed. The total number of 
    time quanta in a bit is between 8 and 25 inclusive.  Refer to the CAN Bus 
    specification for more details on  setting up the time quanta in a bit.

    This data type is used with the CANSetSpeed() function.
*/   

typedef struct 
{
    // Number of Time quanta in Phase Segment 2. 
    // This value can be between CAN_BIT_1TQ and CAN_BIT_8TQ
	CAN_BIT_TQ 	phaseSeg2Tq;           

    // Number of Time quanta in Phase Segment 1. 
    // This value can be between CAN_BIT_1TQ and CAN_BIT_8TQ
	CAN_BIT_TQ 	phaseSeg1Tq;

    // Number of Time quanta in Propagation Segment 2. 
    // This value can be between CAN_BIT_1TQ and CAN_BIT_8TQ
	CAN_BIT_TQ 	propagationSegTq;      
    
    // This determines if the Phase Segment 2  value is 
    // specified by code or set automatically by the module. 
    // TRUE - Phase Segment 2 can be set in code.
    // FALSE - Phase Segment 2 is set by module. 
	bool	 	phaseSeg2TimeSelect;    
                                        
    // This determines the number of times a bit is sampled by
    // the CAN module.. 
    // TRUE - bit is sampled 3 times.
    // FALSE - bit is sampled once. 
	bool 		sample3Time;

    // This determines the Synchronization jump width Time quanta. 
    // This value should be between CAN_BIT_1TQ and CAN_BIT_4TQ.
	CAN_BIT_TQ 	syncJumpWidth; 

}CAN_BIT_CONFIG;

// *****************************************************************************
/* CAN Event Code

  Summary:
    CAN Event Code returned by the CAN Module. 

  Description:
    This enumeration identifies all of the event codes returned by the 
    CANGetPendingEventCode() function. 
*/   

typedef enum 
{
	CAN_CHANNEL0_EVENT,     // An event on Channel 0 is active.
	CAN_CHANNEL1_EVENT,     // An event on Channel 1 is active.
	CAN_CHANNEL2_EVENT,     // An event on Channel 2 is active.
	CAN_CHANNEL3_EVENT,     // An event on Channel 3 is active.
	CAN_CHANNEL4_EVENT,     // An event on Channel 4 is active.
	CAN_CHANNEL5_EVENT,     // An event on Channel 5 is active.
	CAN_CHANNEL6_EVENT,     // An event on Channel 6 is active.
	CAN_CHANNEL7_EVENT,     // An event on Channel 7 is active.
	CAN_CHANNEL8_EVENT,     // An event on Channel 8 is active.
	CAN_CHANNEL9_EVENT,     // An event on Channel 9 is active.
	CAN_CHANNEL10_EVENT,    // An event on Channel 10  is active.
	CAN_CHANNEL11_EVENT,    // An event on Channel 11  is active.
	CAN_CHANNEL12_EVENT,    // An event on Channel 12  is active.
	CAN_CHANNEL13_EVENT,    // An event on Channel 13  is active.
	CAN_CHANNEL14_EVENT,    // An event on Channel 14  is active.
	CAN_CHANNEL15_EVENT,    // An event on Channel 15  is active.
	CAN_CHANNEL16_EVENT,    // An event on Channel 16  is active.
	CAN_CHANNEL17_EVENT,    // An event on Channel 17  is active.
	CAN_CHANNEL18_EVENT,    // An event on Channel 18  is active.
	CAN_CHANNEL19_EVENT,    // An event on Channel 19  is active.
	CAN_CHANNEL20_EVENT,    // An event on Channel 20  is active.
	CAN_CHANNEL21_EVENT,    // An event on Channel 21  is active.
	CAN_CHANNEL22_EVENT,    // An event on Channel 22  is active.
	CAN_CHANNEL23_EVENT,    // An event on Channel 23  is active.
	CAN_CHANNEL24_EVENT,    // An event on Channel 24  is active.
	CAN_CHANNEL25_EVENT,    // An event on Channel 25  is active.
	CAN_CHANNEL26_EVENT,    // An event on Channel 26  is active.
	CAN_CHANNEL27_EVENT,    // An event on Channel 27  is active.
	CAN_CHANNEL28_EVENT,    // An event on Channel 28  is active.
	CAN_CHANNEL29_EVENT,    // An event on Channel 29  is active.
	CAN_CHANNEL30_EVENT,    // An event on Channel 30  is active.
	CAN_CHANNEL31_EVENT,    // An event on Channel 31  is active.
	CAN_NO_EVENT = 0x40,    // No Event is active.
	CAN_ERROR_EVENT,        // CAN Bus Error Event is active.
	CAN_WAKEUP_EVENT,       // CAN Bus Wakeup Event is active.
	CAN_RX_CHANNEL_OVERFLOW_EVENT,  // CAN Receive Channel Overflow Event is active.
	CAN_ADDRESS_ERROR_EVENT,        // CAN Address Error Event is active.
	CAN_BUS_BANDWIDTH_ERROR,        // CAN Bus Bandwidth Error is active.
	CAN_TIMESTAMP_TIMER_EVENT,      // CAN Timestamp Timer Overflow event is active.
	CAN_MODE_CHANGE_EVENT,          // CAN Module Mode Change is active.
	CAN_INVALID_MESSAGE_RECEIVED_EVENT  // CAN Invalid Message Received Event active.

}CAN_EVENT_CODE;

// *****************************************************************************
/* CAN Filters

  Summary:
    Identifies the available CAN filters. 

  Description:
    This enumeration identifies the available filters in each CAN module.
*/   

typedef enum 
{
	CAN_FILTER0,        // CAN Filter 0 
	CAN_FILTER1,        // CAN Filter 1
	CAN_FILTER2,        // CAN Filter 2
	CAN_FILTER3,        // CAN Filter 3
	CAN_FILTER4,        // CAN Filter 4
	CAN_FILTER5,        // CAN Filter 5
	CAN_FILTER6,        // CAN Filter 6
	CAN_FILTER7,        // CAN Filter 7
	CAN_FILTER8,        // CAN Filter 8
	CAN_FILTER9,        // CAN Filter 9
	CAN_FILTER10,       // CAN Filter 10
	CAN_FILTER11,       // CAN Filter 11
	CAN_FILTER12,       // CAN Filter 12
	CAN_FILTER13,       // CAN Filter 13
	CAN_FILTER14,       // CAN Filter 14
	CAN_FILTER15,       // CAN Filter 15
	CAN_FILTER16,       // CAN Filter 16
	CAN_FILTER17,       // CAN Filter 17
	CAN_FILTER18,       // CAN Filter 18
	CAN_FILTER19,       // CAN Filter 19
	CAN_FILTER20,       // CAN Filter 20
	CAN_FILTER21,       // CAN Filter 21
	CAN_FILTER22,       // CAN Filter 22
	CAN_FILTER23,       // CAN Filter 23
	CAN_FILTER24,       // CAN Filter 24
	CAN_FILTER25,       // CAN Filter 25
	CAN_FILTER26,       // CAN Filter 26
	CAN_FILTER27,       // CAN Filter 27
	CAN_FILTER28,       // CAN Filter 28
	CAN_FILTER29,       // CAN Filter 29
	CAN_FILTER30,       // CAN Filter 30
	CAN_FILTER31,       // CAN Filter 31
    
    // Total number of filters in the 
    // module.
    
    CAN_NUMBER_OF_FILTERS   
                            

}CAN_FILTER;

// *****************************************************************************
/* CAN Filter Masks

  Summary:
    CAN Filter Masks Supported. 

  Description:
    This enumeration identifies the available filters masks in each CAN module.
*/   

typedef enum 
{
	CAN_FILTER_MASK0,   // CAN Filter Mask 0
	CAN_FILTER_MASK1,   // CAN Filter Mask 1
	CAN_FILTER_MASK2,   // CAN Filter Mask 2
	CAN_FILTER_MASK3,    // CAN Filter Mask 3
    
    // Total number os filter masks
    // in the module.
    
    CAN_NUMBER_OF_FILTER_MASKS

}CAN_FILTER_MASK;

// *****************************************************************************
/* CAN ID Type 

  Summary:
    Specifies the CAN ID Type. 

  Description:
    This enumeration specifies the two CAN ID types: Standard and Extended. The Standard
    Type ID is 11 bits long and the Extended ID is 29 bits long. This enumeration then
    specifies the type of the ID specified while configuring Filter and Filter masks.
*/   

typedef enum 
{
	CAN_EID,    // CAN Extended ID
	CAN_SID     // CAN Standard ID

}CAN_ID_TYPE;

// *****************************************************************************
/* CAN Transmit Channel Remote Transmit Request (RTR)

  Summary:
    Specifies the status of the CAN Remote Transmit Request (RTR) feature for
    a CAN TX Channel.

  Description:
    This enumeration specifies the status of the CAN Remote Transmit Request 
    feature for a CAN TX Channel. The RTR feature allows a node on the CAN Bus
    to request a transmission from another node on the bus. The responding node
    in this case should have a RTR enabled TX Channel in order to be able to
    respond to this request. 
*/

typedef enum  
{
	CAN_TX_RTR_ENABLED,   // CAN TX Channel RTR Feature is enabled.
	CAN_TX_RTR_DISABLED    // CAN TX Channel RTR Feature is disabled.

}CAN_TX_RTR;

// *****************************************************************************
/* CAN Receive Channel Data Only Mode

  Summary:
    Enables the Data Only Receive Mode or Full Receive Mode of a CAN Receive Channel.
    
  Description:
    This enumeration specifies the status of the CAN Receive Channel Data Only 
    feature. If the feature is enabled, the CAN module will store only the data
    payload portion of the received CAN message. If the Full Receive mode is 
    specified, the CAN module stores the entire CAN message (ID field plus data
    payload). The RX channel can either in Data Only mode or Full Receive Mode. 
*/

typedef enum  
{
	CAN_RX_DATA_ONLY,           // CAN RX Channel Data Only Mode is enabled.
	CAN_RX_FULL_RECEIVE    // CAN RX Channel Full Receive Mode is enabled.

}CAN_RX_DATA_MODE;

// *****************************************************************************
/* CAN Filter Mask Type 

  Summary:
    Specifies the CAN Filter Mask Type. 

  Description:
    This enumeration specifies the filter mask type. The filter mask can either
    process messages with any type of ID (extended or standard) or can only process
    by ID specified in the filter configuration. For example, if the filter associated
    with the mask only accepts EID type messages and if the mask is configured to process
    by ID type, then SID messages will not be accepted. If the mask is configured to 
    process any type of message, both SID and EID messages will be accepted on a filter
    match. 
*/

typedef enum 
{
	CAN_FILTER_MASK_IDE_TYPE,   // Mask processes only Filter type of message.
	CAN_FILTER_MASK_ANY_TYPE    // Mask processes any type (SID or EID) of message.

}CAN_FILTER_MASK_TYPE;

// *****************************************************************************
/* CAN TX Channel Priority 

  Summary:
    Specifies the priority of a TX channel. 

  Description:
    This enumeration identifies the available TX channel priorities. A TX channel
    has its own natural priority order, which determines priority when two or more
    TX channels are assigned the same priority level. Channel 1 has higher natural
    priority than Channel 0 and Channel 2 has a natural priority than Channel 1, and
    so on.
*/

typedef enum 
{
	CAN_LOWEST_PRIORITY,
	CAN_LOW_MEDIUM_PRIORITY,
	CAN_HIGH_MEDIUM_PRIORITY,
	CAN_HIGHEST_PRIORITY

}CAN_TXCHANNEL_PRIORITY;

// *****************************************************************************
/* CAN Device Net Filter Size 

  Summary:
    Specifies the size of the Device Net Filter. 

  Description:
    This enumeration identifies the size of the Device Net filter in bits. If the
    size of the Device Net filter is n, the n most significant bits of the data
    payload are compared with the EID field of enabled filters. 
*/

typedef enum 
{
	CAN_DNET_FILTER_DISABLE,        // Device Net Filtering is disabled.
	CAN_DNET_FILTER_SIZE_1_BIT,     // Device Net Filter is 1 bit long.
    CAN_DNET_FILTER_SIZE_2_BIT,     // Device Net Filter is 2 bits long.
    CAN_DNET_FILTER_SIZE_3_BIT,     // Device Net Filter is 3 bits long.
	CAN_DNET_FILTER_SIZE_4_BIT,     // Device Net Filter is 4 bits long.
	CAN_DNET_FILTER_SIZE_5_BIT,     // Device Net Filter is 5 bits long.
	CAN_DNET_FILTER_SIZE_6_BIT,     // Device Net Filter is 6 bits long.
	CAN_DNET_FILTER_SIZE_7_BIT,     // Device Net Filter is 7 bits long.
	CAN_DNET_FILTER_SIZE_8_BIT,     // Device Net Filter is 8 bits long.
	CAN_DNET_FILTER_SIZE_9_BIT,     // Device Net Filter is 9 bits long.
	CAN_DNET_FILTER_SIZE_10_BIT,     // Device Net Filter is 10 bits long.
	CAN_DNET_FILTER_SIZE_11_BIT,     // Device Net Filter is 11 bits long.
	CAN_DNET_FILTER_SIZE_12_BIT,     // Device Net Filter is 12 bits long.
	CAN_DNET_FILTER_SIZE_13_BIT,     // Device Net Filter is 13 bits long.
	CAN_DNET_FILTER_SIZE_14_BIT,     // Device Net Filter is 14 bits long.
	CAN_DNET_FILTER_SIZE_15_BIT,     // Device Net Filter is 15 bits long.
	CAN_DNET_FILTER_SIZE_16_BIT,     // Device Net Filter is 16 bits long.
	CAN_DNET_FILTER_SIZE_17_BIT,     // Device Net Filter is 17 bits long.
	CAN_DNET_FILTER_SIZE_18_BIT,     // Device Net Filter is 18 bits long.
	
}CAN_DNET_FILTER_SIZE;

// *****************************************************************************
/* CAN Module Events 

  Summary:
    Specifies the CAN module events. 

  Description:
    This enumeration identifies all of the CAN module events. A combination of listed
    events can be logically OR'ed to enable or disable module level events. Similarly,
    a combination of events can be checked if active.

    This enumeration is used with the CANEnableModuleEvent() and CANGetModuleEvent()
    functions. 
*/


typedef enum 
{
    // TX channel event. This event will occur
    // if any of the TX Channel events are active.  
	CAN_TX_EVENT 						= 0x1,

    // RX channel event. This event will occur
    // if any of the RX Channel events are active.
	CAN_RX_EVENT 						= 0x2,

    // CAN Timer Stamp Timer Overflow event occurs.
    // This event occurs when the Timestamp Timer has
    // overflowed. 
	CAN_TIMESTAMP_TIMER_OVERFLOW_EVENT 	= 0x4,

    // CAN Operation Mode Change Event. This event
    // occurs when the CAN module has changed it's
    // operating mode successfully.
	CAN_OPERATION_MODE_CHANGE_EVENT 	= 0x8,

    // CAN RX Channel Overflow Event. This event occurs
    // when any of the RX Channel has overflowed.
    CAN_RX_OVERFLOW_EVENT 				= 0x800,

    // CAN System Error Event. This event occurs when
    // CAN module tries to access an invalid Device RAM
    // location.
	CAN_SYSTEM_ERROR_EVENT 				= 0x1000,

    // CAN Bus Error Event. This event occurs when the 
    // CAN module cannot access the system bus.
	CAN_BUS_ERROR_EVENT 				= 0x2000,

    // CAN Bus Actvity Wakeup. This event occurs when the
    // device is in sleep mode and bus activity is detected
    // on the CAN bus.
	CAN_BUS_ACTIVITY_WAKEUP_EVENT		= 0x4000,

    // CAN Bus Invalid RX Message Event. This event occurs
    // when the CAN module receives an Invalid message.
	CAN_INVALID_RX_MESSAGE_EVENT 		= 0x8000

}CAN_MODULE_EVENT;

// *****************************************************************************
/* CAN Error States 

  Summary:
    Specifies the CAN Module Error States. 

  Description:
    This enumeration identifies all the CAN module error states events. The
    CAN module enters or exits an error state as the Transmit and Receive 
    Error Counter values change. Refer to the CAN specification for more 
    details on the error states.

    This enumeration is used with the CANGetErrorState() function. 
*/

typedef enum 
{
    // CAN Module is in a TX or RX warning state.
	CAN_TX_RX_WARNING_STATE 	= 0x10000,

    // CAN Module is in a RX warning state.
	CAN_RX_WARNING_STATE 		= 0x20000,

    // CAN Module is in a TX warning state.
	CAN_TX_WARNING_STATE 		= 0x40000,

    // CAN RX is in a Bus Passive state.
	CAN_RX_BUS_PASSIVE_STATE 	= 0x80000,
	
    // CAN TX is in a Bus Passive state.
    CAN_TX_BUS_PASSIVE_STATE 	= 0x100000,

    // CAN TX is in Bus Off state.
	CAN_TX_BUS_OFF_STATE 		= 0x200000

}CAN_ERROR_STATE;

// *****************************************************************************
/* CAN Module Features 

  Summary:
    Specifies other CAN Module features. 

  Description:
    This enumeration identifies some of the CAN module features that need to be
    configured as a part of the CAN module intialization. A combination of the
    enumeration members can be logically OR'ed as a parameter to enable or disable
    features.

    This enumeration is used with the CANEnableFeature() function.
*/

typedef enum 
{
    // Specifies if the CAN module is running
    // while CPU is in IDLE mode.
	CAN_STOP_IN_IDLE = 0x2000,

    // Specifies if the CAN module will timestamp
    // every received message.
	CAN_RX_TIMESTAMP = 0x100000,

    // Specifies if the CAN Wake up on bus activity
    // RX line filter is enabled.
	CAN_WAKEUP_BUS_FILTER = 0x400000

}CAN_MODULE_FEATURES;

// *****************************************************************************
/* CAN Channel Masks 

  Summary:
    Lists series of useful masks.  

  Description:
    This enumeration identifies a series of useful masks. Each mask represents a 
    CAN channel. These masks are used  with the CANGetAllChannelEventStatus() and
    CANGetAllChannelOverflowStatus() functions. The value returned by these functions
    can be logically AND'ed with any of these masks to check if an event or overflow
    event for that channel is active. 
*/

typedef enum 
{
	CAN_CHANNEL0_MASK  = 0x00000001,    // Channel 0 Mask
	CAN_CHANNEL1_MASK  = 0x00000002,    // Channel 1 Mask
	CAN_CHANNEL2_MASK  = 0x00000004,    // Channel 2 Mask
	CAN_CHANNEL3_MASK  = 0x00000008,    // Channel 3 Mask
	CAN_CHANNEL4_MASK  = 0x00000010,    // Channel 4 Mask
	CAN_CHANNEL5_MASK  = 0x00000020,    // Channel 5 Mask
	CAN_CHANNEL6_MASK  = 0x00000040,    // Channel 6 Mask
	CAN_CHANNEL7_MASK  = 0x00000080,    // Channel 7 Mask
	CAN_CHANNEL8_MASK  = 0x00000100,    // Channel 8 Mask
	CAN_CHANNEL9_MASK  = 0x00000200,    // Channel 9 Mask
	CAN_CHANNEL10_MASK = 0x00000400,    // Channel 10 Mask
	CAN_CHANNEL11_MASK = 0x00000800,    // Channel 11 Mask
	CAN_CHANNEL12_MASK = 0x00001000,    // Channel 12 Mask
	CAN_CHANNEL13_MASK = 0x00002000,    // Channel 13 Mask
	CAN_CHANNEL14_MASK = 0x00004000,    // Channel 14 Mask
	CAN_CHANNEL15_MASK = 0x00008000,    // Channel 15 Mask
	CAN_CHANNEL16_MASK = 0x00010000,    // Channel 16 Mask
	CAN_CHANNEL17_MASK = 0x00020000,    // Channel 17 Mask
	CAN_CHANNEL18_MASK = 0x00040000,    // Channel 18 Mask
	CAN_CHANNEL19_MASK = 0x00080000,    // Channel 19 Mask
	CAN_CHANNEL20_MASK = 0x00100000,    // Channel 20 Mask
	CAN_CHANNEL21_MASK = 0x00200000,    // Channel 21 Mask
	CAN_CHANNEL22_MASK = 0x00400000,    // Channel 22 Mask
	CAN_CHANNEL23_MASK = 0x00800000,    // Channel 23 Mask
	CAN_CHANNEL24_MASK = 0x01000000,    // Channel 24 Mask
	CAN_CHANNEL25_MASK = 0x02000000,    // Channel 25 Mask
	CAN_CHANNEL26_MASK = 0x04000000,    // Channel 26 Mask
	CAN_CHANNEL27_MASK = 0x08000000,    // Channel 27 Mask
	CAN_CHANNEL28_MASK = 0x10000000,    // Channel 28 Mask
	CAN_CHANNEL29_MASK = 0x20000000,    // Channel 29 Mask
	CAN_CHANNEL30_MASK = 0x40000000,    // Channel 30 Mask
	CAN_CHANNEL31_MASK = 0x80000000,    // Channel 31 Mask
	CAN_ANYCHANNEL_MASK = 0xFFFFFFFF    // Channel any channel Mask

}CAN_CHANNEL_MASK;

// *****************************************************************************
/* CAN TX Channel Condition 

  Summary:
    Possible TX Channel Specific Conditions.  

  Description:
    This enumeration identifies the possible TX channel condition. These masks can 
    be logically AND'ed with values returned by the CANGetTxChannelCondition() 
    function to check if a condition is active.
*/


typedef enum 
{
    // CAN TX Channel is currently Transmitting.
	CAN_TX_CHANNEL_TRANSMITTING = 0x8,

    // CAN TX Channel Error has occurred.
	CAN_TX_CHANNEL_ERROR = 0x10,

    // CAN TX Channel lost arbitration.
	CAN_TX_CHANNEL_ARBITRATION_LOST = 0x20

}CAN_TX_CHANNEL_CONDITION;





// *****************************************************************************
/* CAN RX Message SID Word  

  Summary:
    Defines the structure of the SID word section of the RX message.  

  Description:
    This data structure represents the SID section of the CAN RX message. The data
    data structure is an element of the CANRxMessageBuffer data structure. 
*/

typedef	struct 
{
    // SID of the Received CAN Message. 
	unsigned SID:11;

    // Filter which accepted this message.
	unsigned FILHIT:5;

    // Time stamp of the received message. This is
    // valid only if the Timestamping is enabled.
	unsigned CMSGTS:16;

}CAN_RX_MSG_SID;

// *****************************************************************************
/* CAN RX Message Buffer  

  Summary:
    Defines the structure of the CAN RX Message Buffer.  

  Description:
    This data structure represents the CAN RX Message Buffer. Received messages could
    be either full-receive messages or data-only messages. Full receive message contains
    the message header and data payload section.  For a full receive CAN RX channel, the
    caller should use the msgSID, msgEID and data members . A data-only message contains
    only a 8-byte data payload. While using this data structure with a Data-Only type of
    CAN RX channel, the caller should use the dataOnlyMsgData member of the structure and
    should read only 8 bytes of data.

     
*/
/**/
#define FIFO0 C1FIFOUA0
#define FIFO1 C1FIFOUA1
#define FIFO2 C1FIFOUA2
#define FIFO3 C1FIFOUA3
#define FIFO4 C1FIFOUA4
#define FIFO5 C1FIFOUA5
#define FIFO6 C1FIFOUA6
#define FIFO7 C1FIFOUA7
#define FIFO8 C1FIFOUA8
#define FIFO9 C1FIFOUA9
#define FIFO10 C1FIFOUA10
#define FIFO11 C1FIFOUA11
#define FIFO12 C1FIFOUA12
#define FIFO13 C1FIFOUA13
#define FIFO14 C1FIFOUA14
#define FIFO15 C1FIFOUA15
#define FIFO16 C1FIFOUA16
#define FIFO17 C1FIFOUA17
#define FIFO18 C1FIFOUA18
#define FIFO19 C1FIFOUA19
#define FIFO20 C1FIFOUA20
#define FIFO21 C1FIFOUA21
#define FIFO22 C1FIFOUA22
#define FIFO23 C1FIFOUA23
#define FIFO24 C1FIFOUA24
#define FIFO25 C1FIFOUA25
#define FIFO26 C1FIFOUA26
#define FIFO27 C1FIFOUA27
#define FIFO28 C1FIFOUA28
#define FIFO29 C1FIFOUA29
#define FIFO30 C1FIFOUA30
#define FIFO31 C1FIFOUA31
/* This code snippet shows an example of data structure to implement a CAN */
/* full receive message buffer.*/
    /* Define the sub-components of the data structure as specified in Table 34-5 */
    /* Create a CMSGSID data type. */
    typedef struct 
    {
        unsigned SID:11;
        unsigned FILHIT:5;
        unsigned CMSGTS:16;
    }rxcmsgsid;
    /* Create a CMSGEID data type. */
    typedef struct {
        unsigned DLC:4;
        unsigned RB0:1;
        unsigned :3;
        unsigned RB1:1;
        unsigned RTR:1;
        unsigned EID:18;
        unsigned IDE:1;
        unsigned SRR:1;
        unsigned :2;
    }rxcmsgeid;
    /* Create a CMSGDATA0 data type. */
    typedef struct{
        unsigned Byte0:8;
        unsigned Byte1:8;
        unsigned Byte2:8;
        unsigned Byte3:8;
    }rxcmsgdata0;
    /* Create a CMSGDATA1 data type. */
    typedef struct{
        unsigned Byte4:8;
        unsigned Byte5:8;
        unsigned Byte6:8;
        unsigned Byte7:8;
    }rxcmsgdata1;
    /* This is the main data structure. */
    typedef union uCANRxMessageBuffer 
    {
        struct
        {
            rxcmsgeid CMSGSID;
            rxcmsgeid CMSGEID;
            rxcmsgdata0 CMSGDATA0;
            rxcmsgdata0 CMSGDATA1;
        };
        int messageWord[4];
    }CANRxMessageBuffer;
    
/* This code snippet shows an example of data structure to implement a CAN */
    /* message buffer. */
    /* Define the sub-components of the data structure as specified in Table 34-2 */
    /* Create a CMSGSID data type. */
    typedef struct 
    {
        unsigned SID:11;
        unsigned :21;
    }txcmsgsid;
    /* Create a CMSGEID data type. */
    typedef struct {
        unsigned DLC:4;
        unsigned RB0:1;
        unsigned :3;
        unsigned RB1:1;
        unsigned RTR:1;
        unsigned EID:18;
        unsigned IDE:1;
        unsigned SRR:1;
        unsigned :2;
    }txcmsgeid;/* Create a CMSGDATA0 data type. */
    typedef struct{
        unsigned Byte0:8;
        unsigned Byte1:8;
        unsigned Byte2:8;
        unsigned Byte3:8;
    }txcmsgdata0;/* Create a CMSGDATA1 data type. */
    typedef struct{
        unsigned Byte4:8;
        unsigned Byte5:8;
        unsigned Byte6:8;
        unsigned Byte7:8;
    }txcmsgdata1;/* This is the main data structure. */
    typedef union uCANTxMessageBuffer {
        struct{
            txcmsgsid CMSGSID;
            txcmsgeid CMSGEID;
            txcmsgdata0 CMSGDATA0;
            txcmsgdata0 CMSGDATA1;
        };int messageWord[4];
    }CANTxMessageBuffer;
    

#define TRUE 1
#define FALSE 0
#define CAN1 1
#define CAN2 2
class CANBus{
public:
    CANBus(uint8_t CANModule,uint32_t PBFreq,uint32_t CANBusSpeed);
    void EnableModule(uint8_t CANModule,bool En);
    void SetOperatingMode(uint8_t CANModule,uint8_t CanModuleMode);         
    void SetSpeed(__uint8_t CANModule, __uint32_t PhaseSeg1, __uint32_t PhaseSeg2,__uint32_t PropagationSeg,__uint8_t BRPValue);
    void AssignMemoryBuffer(__uint8_t CANModule,uint32_t BuffAddress);
    void ConfigureChannelForRx(uint8_t CANModule,uint8_t CANChannel,uint8_t BufferMode);
    void ConfigureChannelForTx(uint8_t CANModule,uint8_t CANChannel,uint8_t BufferMode);
    void ConfigureFilter(uint8_t CANModule,uint8_t FilterNo,uint32_t FilterID,uint8_t DataMode);
    void EnableChannelEvent(uint8_t CANModule,uint8_t CANChannel,uint16_t EventMode,uint8_t En);
    void EnableModuleEvent(__uint8_t CANModule, __uint8_t Periority, __uint8_t SubPeriority, __uint8_t En);
    void FillTransmitBuff(__uint32_t FIFOAddress, __uint32_t StandardID,uint8_t Data0);
    void FillTransmitBuff(__uint32_t FIFOAddress, __uint32_t StandardID,uint8_t Data0,uint8_t Data1);
    void FillTransmitBuff(__uint32_t FIFOAddress, __uint32_t StandardID,uint8_t Data0,uint8_t Data1,uint8_t Data2);
    void FillTransmitBuff(__uint32_t FIFOAddress, __uint32_t StandardID,uint8_t Data0,uint8_t Data1,uint8_t Data2,uint8_t Data3);
    void FillTransmitBuff(__uint32_t FIFOAddress, __uint32_t StandardID,uint8_t Data0,uint8_t Data1,uint8_t Data2,uint8_t Data3,uint8_t Data4);
    void FillTransmitBuff(__uint32_t FIFOAddress, __uint32_t StandardID,uint8_t Data0,uint8_t Data1,uint8_t Data2,uint8_t Data3,uint8_t Data4,uint8_t Data5);
    void FillTransmitBuff(__uint32_t FIFOAddress, __uint32_t StandardID,uint8_t Data0,uint8_t Data1,uint8_t Data2,uint8_t Data3,uint8_t Data4,uint8_t Data5,uint8_t Data6);
    void FillTransmitBuff(__uint32_t FIFOAddress, __uint32_t StandardID,uint8_t Data0,uint8_t Data1,uint8_t Data2,uint8_t Data3,uint8_t Data4,uint8_t Data5,uint8_t Data6,uint8_t Data7);
    void Transfer(__uint8_t CANModule,uint8_t CANChannel);
    void ExtendedTransmit(uint32_t FIFOAddress,uint32_t ExtendedID,uint8_t DataLength);
private:
};

#endif	/* CANBUS_H */

