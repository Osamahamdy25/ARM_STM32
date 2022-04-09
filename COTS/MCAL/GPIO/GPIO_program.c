/******************************************************************************
 *
 * Module: GPIO Driver
 *
 * File Name: GPIO_program.C
 *
 * Description: Source file for the STM32 GPIO Driver
 *
 * Author: Osama Hamdy
 *
 *******************************************************************************/
#include"Std_types.h" 
#include"Bit_utils.h"
#include"GPIO_interface.h"
#include"GPIO_private.h"
#ifndef GPIO_PROGRAM_C_
#define GPIO_PROGRAM_C_

/*
 * Public Function
 * Function Description :
 * Setting the Initialzation of  the Gpio Pins
 * if the  the pointer is equal to NULL the function will not handle the request and return Null pointer error
 * Function Paramters : Address of Gpio Configuration Structure Consist of (Mode , Speed , Pin Number ,  Port Address )
 * Function Return : Gpio  Error status
 */

GPIO_ErrorState_t GPIO_Init(GPIO_PinCfg_t * Add_pstrPinCfg) {
	/* Local variable to store the Error Status */
	GPIO_ErrorState_t loc_enuRetrunStatus = GPIO_OK;
	/* Local variable to store the Loop Iteration Value */
	u8 loc_u8Iter = 0;
	/* Local Variable to store the Register Status */
	u32 loc_u32TempCfg = 0;
	/* Casting the variable to Access the GPIO Port Registers */
	GPIOx_Register_t * loc_Port = Add_pstrPinCfg->port;
	/* Checking if the Pointer is Equal to Null */
	if (Add_pstrPinCfg == NULL_PTR) {
		/* Return Null Pointer Error */
		loc_enuRetrunStatus = GPIO_NULL_PointerError;
	} /* End of if (Add_pstrPinCfg == NULL_PTR) */

	else {
		/* For loop to Set all the pins Configuration */
		for (loc_u8Iter = 0; loc_u8Iter < 16; loc_u8Iter++) {
			/* Check the Number of the Required pin to set it's Configuration */
			if (GET_BIT(Add_pstrPinCfg->pin, loc_u8Iter)) {
				/* Assign the  MODER Register to the Temporay Register Variable */
				loc_u32TempCfg = Add_pstrPinCfg->Mode & GPIO_MODE_MASK;
				/* Clear the last Value in the MODER Register */
				(loc_Port)->GPIOx_MODER &=
						~(GPIO_MODE_MASK << (loc_u8Iter * 2));
				/* Set the Mode configuration to the MODER Register */
				(loc_Port)->GPIOx_MODER |= loc_u32TempCfg << (loc_u8Iter * 2);

				/* Assign the  PUPDR Register to the Temporay Register Variable */

				loc_u32TempCfg = (Add_pstrPinCfg->Mode & GPIO_PUPD_MASK) >> 4;

				/* Clear the last Value in the PUPDR Register */

				(loc_Port)->GPIOx_PUPDR &=
						~(GPIO_PUPD_MASK << (loc_u8Iter * 2));

				/* Set the Pull Up/Down configuration to the PUPDR Register */

				(loc_Port)->GPIOx_PUPDR |= loc_u32TempCfg << (loc_u8Iter * 2);

				/* Assign the  OTYPR Register to the Temporay Register Variable */

				loc_u32TempCfg = (Add_pstrPinCfg->Mode & GPIO_OTY_MASK) >> 8;

				/* Clear the last Value in the OTYPR Register */

				(loc_Port)->GPIOx_OTYPER &= ~(GPIO_PUPD_MASK << (loc_u8Iter));

				/* Set the Output configuration to the OTYPR Register */

				(loc_Port)->GPIOx_OTYPER |= loc_u32TempCfg << (loc_u8Iter);

				/* Assign the OSPEEDR Register to the Temporay Register Variable */

				loc_u32TempCfg = (Add_pstrPinCfg->Mode & GPIO_MODE_MASK) >> 8;

				/* Clear the last Value in the OSPEEDR Register */

				(loc_Port)->GPIOx_OSPEEDR &= ~(GPIO_MODE_MASK
						<< (loc_u8Iter * 2));

				/* Set the Speed configuration to the OSPEEDR Register */

				(loc_Port)->GPIOx_OSPEEDR |= Add_pstrPinCfg->Speed
						<< (loc_u8Iter * 2);
			} /*End of if (GET_BIT(Add_pstrPinCfg->pin, loc_u8Iter)) */
		} /* End of for (loc_u8Iter = 0; loc_u8Iter < 16; loc_u8Iter++) */
	}/* End of else {} */
	return loc_enuRetrunStatus;
}

GPIO_ErrorState_t GPIO_WritePinValue(GPIO_PinCfg_t * Add_pstrPinCfg,
		u8 Copy_u8Value) {
	/* Local variable to store the Error Status */
	GPIO_ErrorState_t loc_enuRetrunStatus = GPIO_OK;
	/* Casting the variable to Access the GPIO Port Registers */
	GPIOx_Register_t * loc_Port = Add_pstrPinCfg->port;
	/* Checking the Range of Pin Value */
	if (Copy_u8Value > GPIO_u32HIGH) {
		/* Return Gpio Error */
		loc_enuRetrunStatus = GPIO_NOK;
	} /* End of if (Copy_u8Value > GPIO_u32HIGH) */

	else {
		/*Check if the Value is Logical High */
		if (Copy_u8Value == GPIO_u32HIGH) {
			loc_Port->GPIOx_BSRR = Add_pstrPinCfg->pin;
		} /*End of if (Copy_u8Value == GPIO_u32HIGH) */
		else {
			/* if the value is Logical Low */
			loc_Port->GPIOx_BSRR = (Add_pstrPinCfg->pin) << 16;
		} /* End of else */
	}/*End of else */

	return loc_enuRetrunStatus;

}

GPIO_ErrorState_t GPIO_ReadPinValue(GPIO_PinCfg_t * Add_pstrPinCfg,
		pu8 Add_pu8Value) {
	/* Local variable to store the Error Status */
	GPIO_ErrorState_t loc_enuRetrunStatus = GPIO_OK;
	/* Casting the variable to Access the GPIO Port Registers */
	GPIOx_Register_t * loc_Port = Add_pstrPinCfg->port;
	/* Checking if the Pointer is Equal to Null */
	if (Add_pstrPinCfg == NULL_PTR) {
		/* Return Null Pointer Error */
		loc_enuRetrunStatus = GPIO_NULL_PointerError;
	} /* End of if (Add_pstrPinCfg == NULL_PTR) */
	else {
		if (loc_Port->GPIOx_IDR & Add_pstrPinCfg->pin) {
			*(Add_pu8Value) = GPIO_u32HIGH;
		} /* end of if (loc_Port->GPIOx_IDR & Add_pstrPinCfg->pin) */

		else {
			*(Add_pu8Value) = GPIO_u32LOW;
		} /*end of inner else */

	} /* end of outer else */
	return loc_enuRetrunStatus;
}
GPIO_ErrorState_t GPIO_SetAF(GPIO_PinCfg_t * Add_pstrPinCfg, u8 Copy_u8AFValue) {
	/* Local variable to store the Error Status */
	GPIO_ErrorState_t loc_enuRetrunStatus = GPIO_OK;
	/* Casting the variable to Access the GPIO Port Registers */
	GPIOx_Register_t * loc_Port = Add_pstrPinCfg->port;
	if (Add_pstrPinCfg == NULL_PTR) {
		/* Return Null Pointer Error */
		loc_enuRetrunStatus = GPIO_NULL_PointerError;
	} /* End of if (Add_pstrPinCfg == NULL_PTR) */
	else if (Copy_u8AFValue > GPIO_u8ALTERNATE_FUNC_0F) {
		loc_enuRetrunStatus = GPIO_AFError;
	} /*end of else if (Copy_u8AFValue > GPIO_u8ALTERNATE_FUNC_0F) */
	else {
		if (Copy_u8AFValue > GPIO_u8ALTERNATE_FUNC_07) {
			loc_Port->GPIOx_AFRH |= Copy_u8AFValue;
		} /*end of if (Copy_u8AFValue > GPIO_u8ALTERNATE_FUNC_07) */
		else {
			loc_Port->GPIOx_AFRL |= Copy_u8AFValue;
		} /* end of inner else */

	} /*end of outer else */

	return loc_enuRetrunStatus;
}
GPIO_ErrorState_t GPIO_SetLockPin(GPIO_PinCfg_t * Add_pstrPinCfg) {
	/* Local variable to store the Error Status */
	GPIO_ErrorState_t loc_enuRetrunStatus = GPIO_OK;
	/* Casting the variable to Access the GPIO Port Registers */
	GPIOx_Register_t * loc_Port = Add_pstrPinCfg->port;
	/* Temorary Variable to Store the value of Lock Register */
	u32 Temp_Reg;
	if (Add_pstrPinCfg == NULL_PTR) {
		/* Return Null Pointer Error */
		loc_enuRetrunStatus = GPIO_NULL_PointerError;
	} /* End of if (Add_pstrPinCfg == NULL_PTR) */
	else {
		/* Set High to the locked Pin */
		Temp_Reg |= Add_pstrPinCfg->pin;
		/* Locking Sequence to pin16 */
		/* Write High to lck16*/
		Temp_Reg |= (1 << 16);
		loc_Port->GPIOx_LCKR = Temp_Reg;
		/* Write Low to lck16*/
		Temp_Reg &= ~(1 << 16);
		loc_Port->GPIOx_LCKR = Temp_Reg;
		/*Write High to lck16*/
		Temp_Reg |= (1 << 16);
		loc_Port->GPIOx_LCKR = Temp_Reg;
		/* Read The value of the lock register */
		Temp_Reg = loc_Port->GPIOx_LCKR;
		Temp_Reg = loc_Port->GPIOx_LCKR;
		/* Checking if the sequence Done Correctly */
		if (loc_Port->GPIOx_LCKR & (1 << 16)) {
			/* Return that the lock is Active */
			loc_enuRetrunStatus = GPIO_LockActive;
		}/*end of if (loc_Port->GPIOx_LCKR & (1 << 16)) */
		else {
			/* Return that the lock is Not Active */

			loc_enuRetrunStatus = GPIO_LockError;

		} /*End of inner else */
	} /* End of outer else */

	return loc_enuRetrunStatus;
}

#endif /* GPIO_PROGRAM_C_ */
