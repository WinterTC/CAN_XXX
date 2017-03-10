#infdefine CAN_XXX
#define CAN_XXX

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/fpu.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "grlib/grlib.h"
#include "drivers/cfal96x64x16.h"
#include "utils/uartstdio.h"
#include "driverlib/interrupt.h"


//! See diagram
//! \verbatim
//!       CANH--+--------------------------+--CANH
//!             |                          |
//!            .-.                        .-.
//!            | |120ohm          | |120ohm
//!            | |                        | |
//!            '-'                        '-'
//!             |                          |
//!       CANL--+--------------------------+--CANL
//! \endverbatim
//!

//********************************************************************************************************************
//Initializes the CAN controller after reset.
//ui32Base is the base address of the CAN controller
//********************************************************************************************************************
void CAN_XXX_CANInit(uint32_t ui32Base);

//********************************************************************************************************************
//Clears a CAN interrupt source.
//ui32Base is the base address of the CAN controller.
//ui32IntClr is a value indicating which interrupt source to clear.
//********************************************************************************************************************
void CAN_XXX_CANIntClear(uint32_t ui32Base, uint32_t ui32IntClr)

//********************************************************************************************************************
//Sets the CAN bit timing values to a nominal setting based on a desired bit rate.
//ui32Base is the base address of the CAN controller.
//ui32SourceClock is the system clock for the device in Hz.
//ui32BitRate is the desired bit rate.
//********************************************************************************************************************
uint32_t CAN_XXX_CANBitRateSet(uint32_t ui32Base, uint32_t ui32SourceClock, uint32_t ui32BitRate);

//********************************************************************************************************************
//Enables individual CAN controller interrupt sources
//ui32Base is the base address of the CAN controller.
//ui32IntFlags is the bit mask of the interrupt sources to be enabled.
//********************************************************************************************************************
void CAN_XXX_CANIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags);

//********************************************************************************************************************
//Enables the CAN controller.
//ui32Base is the base address of the CAN controller to enable
//********************************************************************************************************************
void CAN_XXX_CANEnable(uint32_t ui32Base);

//********************************************************************************************************************
//Disables the CAN controller
//ui32Base is the base address of the CAN controller to disable
//********************************************************************************************************************
void CAN_XXX_CANDisable(uint32_t ui32Base);

//********************************************************************************************************************
//Configures a message object in the CAN controller.
//ui32Base is the base address of the CAN controller.
//ui32ObjID is the object number to configure (1-32).
//psMsgObject is a pointer to a structure containing message object settings.
//eMsgType indicates the type of message for this object.
//********************************************************************************************************************
void CAN_XXX_CANMessageSet (uint32_t ui32Base, uint32_t ui32ObjID, tCANMsgObject *psMsgObject, tMsgObjType eMsgType);

//********************************************************************************************************************
//Reads a CAN message from one of the message object buffers.
//ui32Base is the base address of the CAN controller.
//ui32ObjID is the object number to read (1-32).
//psMsgObject points to a structure containing message object fields.
//bClrPendingInt indicates whether an associated interrupt should be cleared.
//********************************************************************************************************************
void CAN_XXX_CANMessageGet (uint32_t ui32Base, uint32_t ui32ObjID, tCANMsgObject *psMsgObject, bool bClrPendingInt);

//********************************************************************************************************************
//Returns the current CAN controller interrupt status
//ui32Base is the base address of the CAN controller.
//eIntStsReg indicates which interrupt status register to read
//********************************************************************************************************************
uint32_t CAN_XXX_CANIntStatus (uint32_t ui32Base, tCANIntStsReg eIntStsReg);

//********************************************************************************************************************
//Reads one of the controller status registers.
//ui32Base is the base address of the CAN controller.
//eStatusReg is the status register to read.
//********************************************************************************************************************
uint32_t CAN_XXX_CANStatusGet (uint32_t ui32Base, tCANStsReg eStatusReg);


#endif //CAN_XXX