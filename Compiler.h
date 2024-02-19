/*
 * Compiler.h
 *
 *  Created on: 28 Jan 2024
 *      Author: Ziad Yakoot
 */

#ifndef COMPILER_H_
#define COMPILER_H_

#define COMPILER_VENDOR_ID        123

#define COMPILER_AR_RELEASE_MAJOR_VERSION     4
#define COMPILER_AR_RELEASE_MINOR_VERSION     4
#define COMPILER_AR_RELEASE_REVISION_VERSION  0

#define COMPILER_SW_MAJOR_VERSION           1
#define COMPILER_SW_MINOR_VERSION           0
#define COMPILER_SW_PATCH_VERSION           0
#ifndef _GNU_ARM_C_STM32F103_
#define _GNU_ARM_C_STM32F103_
#endif
/*================================================================
 *                      MACROS
 =================================================================*/
//memory classes

#define AUTOMATIC
#define TYPEDEF
#define NULL_PTR     ((void*)0)



/****************************GNU ARM******************************/
#ifdef _GNU_ARM_C_STM32F103_
#define INLINE              inline
#define LOCAL_INLINE      static inline
#define STATIC              static
#define INTERRUPT_FUNC

#endif /*#ifdef _GNU_ARM_C_STM32F103_*/
/*****************************************************************/

#define FUNC(rettype,memclass)rettype

#define P2VAR(rettype,memclass,Ptrclass)ptrtype*

#define P2CONST(rettype,memclass,ptrclass)const ptrtype*

#define CONSTP2VAR(rettype,memclass,ptrclass) ptrtype* const

#define CONSTP2CONST(rettype,memclass,ptrclass) const ptrtype * const

#define P2FUNC(rettype,Ptrclass,fctname)rettype(*fctname)

#define CONST(consttype,memclass)const consttype



#endif /* COMPILER_H_ */
