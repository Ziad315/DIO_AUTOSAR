/*
 * Dio.h
 *
 *  Created on: 25 Jan 2024
 *      Author: Ziad Yakoot
 */
#ifndef DIO_H_
#define DIO_H_

/*================================================================
 *                       INCLUDE FILES
 =================================================================*/
#include "Dio_Cfg.h"
#include "std_Types.h"

/*===============================================================
 *            SOURCE FILE VERSION INFORMATION
 ================================================================*/
#define DIO_VENDOR_ID        123
#define DIO_MODULE_ID        120
#define DIO_INSTANCE_ID       0

#define DIO_AR_RELEASE_MAJOR_VERSION     4
#define DIO_AR_RELEASE_MINOR_VERSION     4
#define DIO_AR_RELEASE_REVISION_VERSION  0

#define DIO_SW_MAJOR_VERSION           1
#define DIO_SW_MINOR_VERSION           0
#define DIO_SW_PATCH_VERSION           0

/*================================================================
 *                 FILE VERSION CHECK
 =================================================================*/
#ifndef DISABLE_MCAL_INTERMEDULE_ASR_CHECK
#if ((DIO_AR_RELEASE_MAJOR_VERSION !=STD_AR_RELEASE_MAJOR_VERSION) || \
	  (DIO_AR_RELEASE_MINOR_VERSION !=STD_AR_RELEASE_MINOR_VERSION))
    #error"Autosar version number in std_Types.h Dio.h is different"
#endif
#endif

#if (DIO_VENDOR_ID !=DIO_VENDOR_ID_CFG)
    #error"Dio.h and Dio_Cfg.h has different vendor id"
#endif

#ifndef DISABLE_MCAL_INTERMEDULE_ASR_CHECK
#if ((DIO_AR_RELEASE_MAJOR_VERSION !=DIO_AR_RELEASE_MAJOR_VERSION_CFG) || \
	  (DIO_AR_RELEASE_MINOR_VERSION !=DIO_AR_RELEASE_MINOR_VERSION_CFG) || \
	  (DIO_AR_RELEASE_REVISION_VERSION != DIO_AR_RELEASE_REVISION_VERSION_CFG))
    #error"Autosar version number in std_Types.h and Compiler_Types.h is different"
#endif
#endif
/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Channel */
#define DIO_E_PARAM_INVALID_CHANNEL_ID (uint8)0x0A

/* Dio_Init API service called with NULL pointer parameter */
#define DIO_E_PARAM_CONFIG             (uint8)0x10

/* DET code to report Invalid Port */
#define DIO_E_PARAM_INVALID_PORT_ID    (uint8)0x14

/* DET code to report Invalid Channel Group */
#define DIO_E_PARAM_INVALID_GROUP      (uint8)0x1F

/*
 * The API service shall return immediately without any further action,
 * beside reporting this development error.
 */
#define DIO_E_PARAM_POINTER             (uint8)0x20

/*
 * API service used without module initialization is reported using following
 * error code (Not exist in AUTOSAR 4.4.0 DIO SWS Document.
 */
#define DIO_E_UNINIT                   (uint8)0xF0



/*
 * Macros for Dio Status
 */
#define DIO_INITIALIZED                (1U)
#define DIO_NOT_INITIALIZED            (0U)

/*FUNCTIONS IDS*/
#define DIO_INIT_SID              (uint8)0x10
#define Dio_ReadChannel_SID       (uint8)0x00
#define Dio_WriteChannel_SID      (uint8)0x01
#define Dio_ReadPort_SID          (uint8)0x02
#define Dio_ReadPort_SID          (uint8)0x03
#define Dio_ReadChannelGroup_SID  (uint8)0x04
#define Dio_WriteChannelGroup_SID (uint8)0x05

/* Numeric ID of a DIO channel*/
typedef uint8  Dio_ChannelType;

/*Numeric ID of a DIO port*/
typedef uint8  Dio_PortType;

/*These are the possible levels a DIO channel can have (HIGH or LOW)*/
typedef uint8 Dio_LevelType;


/*Type for the definition of a channel group, which consists of several adjoining
 * channels within a port.
 */
typedef struct
{
	uint8 mask;
	uint8 offset;
	Dio_PortType portindex;
}Dio_ChannelGroupType;

typedef struct
{
	/* Member contains the ID of the Port that this channel belongs to */
	Dio_PortType Port_Num;
	/* Member contains the ID of the Channel*/
	Dio_ChannelType Ch_Num;
}Dio_ConfigChannel;


/* Data Structure required for initializing the Dio Driver */
typedef struct
{
	Dio_ConfigChannel Channels[DIO_CONFIGURED_CHANNLES];
	Dio_PortType ports[DIO_CONFIGURED_PORTS];
	Dio_ChannelGroupType groups [DIO_CONFIGURED_GROUPS];
} Dio_ConfigType;

/* If the µC owns ports of different port widths (e.g. 4, 8,16...Bit) Dio_PortLevelType
inherits the size of the largest port.
*/
typedef uint8 Dio_PortLevelType;
/********************************************************************************
 *                    FUNCTION PROTOTYPE
 ********************************************************************************/
#define DIO_START_SEC_CODE
#include"MemMap.h"
void Dio_init(const Dio_ConfigType* ConfigPtr);

/*Returns the value of the specified DIO channel*/
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);
/*Service to set a level of a channel */
void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level);
/*Returns the level of all channels of that port*/
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);

/*Service to set a value of the port*/
void Dio_WritePort (Dio_PortType PortId,Dio_PortLevelType Level);

/*This Service reads a subset of the adjoining bits of a port*/
Dio_PortLevelType Dio_ReadChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr);

/*Service to set a subset of the adjoining bits of a port to a specified level*/
void Dio_WriteChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level);

#define DIO_STOP_SEC_CODE
#include"MemMap.h"

#endif /* DIO_H_ */
