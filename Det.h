/*
 * Det.h
 *
 *  Created on: 19 Feb 2024
 *      Author: Ziad Yakoot
 */

#ifndef DET_H_
#define DET_H_
/*================================================================
 *                          INCLUDE FILES
 ================================================================*/
#include "std_Types.h"

#define DET_INSTANCE_ID               (0U)
#define DET_MODULE_ID        15

#define DET_AR_MAJOR_VERSION     4
#define DET_AR_MINOR_VERSION     4
#define DET_AR_REVISION_VERSION  0

#define DET_SW_MAJOR_VERSION           1
#define DET_SW_MINOR_VERSION           0
#define DET_SW_PATCH_VERSION           0

/* AUTOSAR checking between Std Types and Det Modules */
#if ((DET_AR_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_REVISION_VERSION != STD_AR_RELEASE_REVISION_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif



/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
void Det_ReportError( uint16 ModuleId,
                      uint8 InstanceId,
                      uint8 ApiId,
					  uint8 ErrorId );

#endif /* DET_H_ */
