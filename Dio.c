/*
 * Dio.c
 *
 *  Created on: 26 Jan 2024
 *      Author: Ziad Yakoot
 */

/*=======================================================
 *                  INCLUDE FILES
 =======================================================*/
#include"std_types.h"
#include "Common_macros.h"
#include "Dio.h"
#include "Compiler.h"
#include "Dio_regs.h"
#include "Det.h"

STATIC Dio_ConfigChannel *Dio_PortChannels = NULL_PTR;
STATIC Dio_PortType *Dio_Ports = NULL_PTR;
STATIC Dio_ChannelGroupType *Dio_ChannelGroups  = NULL_PTR;
STATIC uint8 Dio_Status = DIO_NOT_INITIALIZED;

void Dio_Init(const Dio_ConfigType * ConfigPtr)
{
#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_INIT_SID,
		     DIO_E_PARAM_CONFIG);
	}
	else
#endif
	{
		/*
		 * Set the module state to initialized and point to the PB configuration structure using a global pointer.
		 * This global pointer is global to be used by other functions to read the PB configuration structures
		 */
		Dio_Status       = DIO_INITIALIZED;
		Dio_PortChannels = ConfigPtr->Channels; /* address of the first Channels structure --> Channels[0] */
		Dio_Ports = ConfigPtr->ports;
		Dio_ChannelGroups = ConfigPtr->groups;

	}
}


Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
	Dio_PortLevelType *PORT_ptr =NULL;
	uint8 errorState = E_OK;
	Dio_LevelType output = STD_LOW;
	if(ChannelId > DIO_CONFIGURED_CHANNLES)
	{
		errorState=E_NOT_OK;
		//det
	}
	else
	{
		//do nothing
	}
	if(errorState ==E_OK)
	{
		switch(Dio_PortChannels[ChannelId].Port_Num)
		{
		case 0: PORT_ptr=&PINA_REG;break;
		case 1: PORT_ptr=&PINB_REG;break;
		case 2: PORT_ptr=&PINC_REG;break;
		case 3: PORT_ptr=&PIND_REG;break;
		default:errorState=E_NOT_OK;break;
		}
		if(GET_BIT(*PORT_ptr,Dio_PortChannels[ChannelId].Ch_Num)==1)
		{
			output =STD_HIGH;
		}
		else if(GET_BIT(*PORT_ptr,Dio_PortChannels[ChannelId].Ch_Num)==0)
		{
			output =STD_LOW;
		}
		else
		{
			errorState=E_NOT_OK;
		}
	}
	return output;
}

void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level)
{
	Dio_PortLevelType *PORT_ptr =NULL;
		uint8 errorState = E_OK;
		Dio_LevelType output = STD_LOW;
		if(ChannelId > DIO_CONFIGURED_CHANNLES)
		{
			errorState=E_NOT_OK;
			//det
		}
		else
		{
			//do nothing
		}
		if(errorState ==E_OK)
		{
			switch(Dio_PortChannels[ChannelId].Port_Num)
			{
			case 0: PORT_ptr=&PORTA_REG;break;
			case 1: PORT_ptr=&PORTB_REG;break;
			case 2: PORT_ptr=&PORTC_REG;break;
	    	case 3: PORT_ptr=&PORTD_REG;break;
			default:errorState=E_NOT_OK;break;
			}
			if(Level == STD_HIGH)
			{
				SET_BIT(*PORT_ptr,Dio_PortChannels[ChannelId].Ch_Num);
			}
			else if(Level ==STD_LOW)
			{
				CLR_BIT(*PORT_ptr,Dio_PortChannels[ChannelId].Ch_Num);
			}
			else
			{
				errorState=E_NOT_OK;
			}
		}
}
