/*
 * STD_TYPES.h
 *
 *  Created on: 7 Dec 2023
 *      Author: Ziad Yakoot
 */

#ifndef AVR_DRIVER_LIB_STD_TYPES_H_
#define AVR_DRIVER_LIB_STD_TYPES_H_

#include"Platform_Types.h"
#include"Compiler.h"

#define STD_VENDOR_ID        123

#define STD_AR_RELEASE_MAJOR_VERSION     4
#define STD_AR_RELEASE_MINOR_VERSION     4
#define STD_AR_RELEASE_REVISION_VERSION  0

#define STD_SW_MAJOR_VERSION           1
#define STD_SW_MINOR_VERSION           0
#define STD_SW_PATCH_VERSION           0

/*================================================================
 *                 FILE VERSION CHECK
 =================================================================*/
#ifndef DISABLE_MCAL_INTERMEDULE_ASR_CHECK
#if ((STD_AR_RELEASE_MAJOR_VERSION !=PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
	  (STD_AR_RELEASE_MINOR_VERSION !=PLATFORM_AR_RELEASE_MINOR_VERSION))
    #error"Autosar version number in std_Types.h and Platform_Types.h is different"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMEDULE_ASR_CHECK
#if ((STD_AR_RELEASE_MAJOR_VERSION !=COMPILER_AR_RELEASE_MAJOR_VERSION) || \
	  (STD_AR_RELEASE_MINOR_VERSION !=COMPILER_AR_RELEASE_MINOR_VERSION))
    #error"Autosar version number in std_Types.h and Compiler_Types.h is different"
#endif
#endif


#define STD_HIGH       0x01
#define STD_LOW        0x00

#define STD_ACTIVE     0x01
#define STD_IDLE       0x00

#define STD_OFF         0x00
#define STD_ON          0x01

#define E_NOT_OK        0x01

#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
#define E_OK     0x00
/*
 *  @brief This type is defined in OSEK compliance
 */
typedef unsigned char statusType;
#endif

typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short int uint16;
typedef signed short int sint16;
typedef unsigned int uint64;
typedef signed short int sint64;
typedef unsigned long uint32;
#define NULL ((void*)0)

/*
 * This type can be used as standard API return type which
 * is shared between RTE and BSW
 */
typedef uint8 std_ReturnType;

typedef struct
{
	uint16 vendorID;
	uint16 moduleID;
	uint8 sw_major_version;
	uint8 sw_minor_version;
	uint8 sw_patch_version;
}std_versionInfoType;

#endif /* AVR_DRIVER_LIB_STD_TYPES_H_ */
