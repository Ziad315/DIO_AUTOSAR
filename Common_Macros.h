/*
 * COMMON_MACROS.h
 *
 *  Created on: 16 Jan 2024
 *      Author: User
 */

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

#define CLR_BIT(VAR,BITNO)   VAR &=~(1<<BITNO)
#define SET_BIT(VAR,BITNO)   VAR |=(1<<BITNO)
#define TOG_BIT(VAR,BITNO)   VAR ^=(1<<BITNO)
#define GET_BIT(VAR,BITNO)   (VAR>>BITNO)&1

#endif /* COMMON_MACROS_H_ */
