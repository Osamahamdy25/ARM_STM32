/******************************************************************************
 *
 * Module     : NVIC Driver
 *
 * File Name  : NVIC.c
 *
 * Description: Source file for the STM32 NVIC Driver
 *
 * Author     : Osama Hamdy
 *
 *******************************************************************************/
#include "Std_types.h"
#include "Bit_utils.h"
#include "NVIC.h"
#include "NVIC_prv.h"
/*******************************************************************************
 *                            Fuction ProtoTypes                               *
 *******************************************************************************/
/****************************************************************************************************************
 * Public Function
 * Description : Enable the the NVIC Interupt Pin
 * Function Paramters : Interrupt ID Number
 * Function Return : Error Status of NVIC
 ****************************************************************************************************************/
NVIC_ErrorState_t NVIC_enutEnableInterrupt(u8 Copy_u8IntID) {
	NVIC_ErrorState_t loc_ErrorState = NVIC_OK;
	if (Copy_u8IntID > MAX_INT_NUM) {
		loc_ErrorState = NVIC_PinError;
	} else {
		if (Copy_u8IntID <= 31) {
			NVIC->NVIC_ISER[0] = (1 << Copy_u8IntID);
		} else if (Copy_u8IntID <= 59) {
			Copy_u8IntID = Copy_u8IntID - 32;
			NVIC->NVIC_ISER[1] = (1 << Copy_u8IntID);
		} else {
			/* Retrurn Error */
		}
	}
	return loc_ErrorState;
}
/****************************************************************************************************************
 * Public Function
 * Description : Disable the the NVIC Interupt Pin
 * Function Paramters : Interrupt ID Number
 * Function Return : Error Status of NVIC
 ****************************************************************************************************************/
NVIC_ErrorState_t NVIC_enutDisableInterrupt(u8 Copy_u8IntID) {
	NVIC_ErrorState_t loc_ErrorState = NVIC_OK;
	if (Copy_u8IntID > MAX_INT_NUM) {
		loc_ErrorState = NVIC_PinError;
	} else {
		if (Copy_u8IntID <= 31) {
			NVIC->NVIC_ICER[0] = (1 << Copy_u8IntID);
		} else if (Copy_u8IntID <= 59) {
			Copy_u8IntID = Copy_u8IntID - 32;
			NVIC->NVIC_ICER[1] = (1 << Copy_u8IntID);
		} else {
			/* Retrurn Error */
		}
	}
	return loc_ErrorState;
}
/****************************************************************************************************************
 * Public Function
 * Description : Enable the the NVIC Pending Flag
 * Function Paramters : Interrupt ID Number
 * Function Return : Error Status of NVIC
 ****************************************************************************************************************/
NVIC_ErrorState_t NVIC_SetPendingFlag(u8 Copy_u8IntID) {
	NVIC_ErrorState_t loc_ErrorState = NVIC_OK;

	if (Copy_u8IntID > MAX_INT_NUM) {
		loc_ErrorState = NVIC_PinError;
	} else {
		if (Copy_u8IntID <= 31) {
			NVIC->NVIC_ISPR[0] = (1 << Copy_u8IntID);
		} else if (Copy_u8IntID <= 59) {
			Copy_u8IntID = Copy_u8IntID - 32;
			NVIC->NVIC_ISPR[1] = (1 << Copy_u8IntID);
		} else {
			/* Retrurn Error */
		}
	}

	return loc_ErrorState;
}
/****************************************************************************************************************
 * Public Function
 * Description : Disable the the NVIC Pending Flag
 * Function Paramters : Interrupt ID Number
 * Function Return : Error Status of NVIC
 ****************************************************************************************************************/
NVIC_ErrorState_t NVIC_ClearPendingFlag(u8 Copy_u8IntID) {
	NVIC_ErrorState_t loc_ErrorState = NVIC_OK;
	if (Copy_u8IntID > MAX_INT_NUM) {
		loc_ErrorState = NVIC_PinError;
	} else {
		if (Copy_u8IntID <= 31) {
			NVIC->NVIC_ISPR[0] = (1 << Copy_u8IntID);
		} else if (Copy_u8IntID <= 59) {
			Copy_u8IntID = Copy_u8IntID - 32;
			NVIC->NVIC_ISPR[1] = (1 << Copy_u8IntID);
		} else {
			/* Retrurn Error */
		}
	}
	return loc_ErrorState;
}
/****************************************************************************************************************
 * Public Function
 * Description : Get the Status Value of  the NVIC Pending Flag
 * Function Paramters : Interrupt ID Number
 * Function Return : Error Status of NVIC
 ****************************************************************************************************************/
NVIC_ErrorState_t NVIC_u8GetPendingFlag(u8 Copy_u8IntID,
		pu8 Add_pu8PendingState) {
	NVIC_ErrorState_t loc_ErrorState = NVIC_OK;
	if (Copy_u8IntID > MAX_INT_NUM) {
		loc_ErrorState = NVIC_PinError;
	} else if (Add_pu8PendingState == NULL_PTR) {
		loc_ErrorState = NVIC_NULL_PointerError;
	} else {
		if (Copy_u8IntID <= 31) {
			*(Add_pu8PendingState) = GET_BIT(NVIC->NVIC_ISPR[0], Copy_u8IntID);
		} else if (Copy_u8IntID <= 59) {
			Copy_u8IntID = Copy_u8IntID - 32;
			*(Add_pu8PendingState) = GET_BIT(NVIC->NVIC_ISPR[1], Copy_u8IntID);
		} else {
			/* Retrurn Error */
		}

	}
	return loc_ErrorState;
}
/****************************************************************************************************************
 * Public Function
 * Description : Get the Status Value of  the NVIC Active Flag
 * Function Paramters : Interrupt ID Number
 * Function Return : Error Status of NVIC
 ****************************************************************************************************************/
NVIC_ErrorState_t NVIC_u8GetActiveFlag(u8 Copy_u8IntID, pu8 Add_pu8ActiveState) {
	NVIC_ErrorState_t loc_ErrorState = NVIC_OK;
	if (Copy_u8IntID > MAX_INT_NUM) {
		loc_ErrorState = NVIC_PinError;
	} else if (Add_pu8ActiveState == NULL_PTR) {
		loc_ErrorState = NVIC_NULL_PointerError;
	} else {
		if (Copy_u8IntID <= 31) {
			*(Add_pu8ActiveState) = GET_BIT(NVIC->NVIC_IABR[0], Copy_u8IntID);
		} else if (Copy_u8IntID <= 59) {
			Copy_u8IntID = Copy_u8IntID - 32;
			*(Add_pu8ActiveState) = GET_BIT(NVIC->NVIC_IABR[1], Copy_u8IntID);
		} else {
			/* Retrurn Error */
		}

	}

	return loc_ErrorState;
}
/****************************************************************************************************************
 * Public Function
 * Description : Set  the NVIC Priority => ( Group + SubGroup )
 * Function Paramters : Interrupt ID Number
 * Function Return : Error Status of NVIC
 ****************************************************************************************************************/
NVIC_ErrorState_t NVIC_vidSetPriority(NVIC_PRI *PRI_cfg) {
	NVIC_ErrorState_t loc_ErrorState = NVIC_OK;
	if (PRI_cfg->copy_u8IntID > MAX_INT_NUM) {
		loc_ErrorState = NVIC_PinError;
	}
	else
	{
	u8 Local_u8Priority = PRI_cfg->copy_u8SubPriority|PRI_cfg->copy_u8GroupPriority<<(PRI_cfg->copy_u32Group_type - 0x05FA0300) / 256;
	NVIC_IPR[PRI_cfg->copy_u8IntID]= Local_u8Priority  << 4 ;
	SCB_AIRCR =PRI_cfg->copy_u32Group_type;
	}
	return loc_ErrorState;
}
