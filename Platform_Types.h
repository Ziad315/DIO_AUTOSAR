/*
 * Platform_Types.h
 *
 *  Created on: 16 Feb 2024
 *      Author: Ziad Yakoot
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#define PLATFORM_VENDOR_ID        123

#define PLATFORM_AR_RELEASE_MAJOR_VERSION     4
#define PLATFORM_AR_RELEASE_MINOR_VERSION     4
#define PLATFORM_AR_RELEASE_REVISION_VERSION  0

#define PLATFORM_SW_MAJOR_VERSION           1
#define PLATFORM_SW_MINOR_VERSION           0
#define PLATFORM_SW_PATCH_VERSION           0

/*================================================================
 *                  CPU TYPE
 =================================================================*/
#define CPU_TYPE_8       8
#define CPU_TYPE_16      16
#define CPU_TYPE_32      32
#define CPU_TYPE_64      64

#define MSB_FIRST        1
#define LSB_FIRST        0

#define HIGH_BYTE_FIRST      1
#define LOW_BYTE_FIRST       0



#define CPU_TYPE(CPU_TYPE_32)
#define CPU_BIT_ORDER(LSB_FIRST)
#define cpu_byte_ORDER(LOW_BYTE_FIRST)


#ifndef TRUE
#define TRUE     1
#endif


#ifndef FALSE
#define FALSE     0
#endif


#endif /* PLATFORM_TYPES_H_ */
