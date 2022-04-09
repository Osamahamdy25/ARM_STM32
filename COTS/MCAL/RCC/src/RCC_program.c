/******************************************************************************
 *
 * Module: RCC Driver
 *
 * File Name: rcc.C
 *
 * Description: Source file for the STM32 RCC Driver
 *
 * Author: Osama Hamdy
 *
 *******************************************************************************/
#include"Std_types.h"
#include"Bit_utils.h"
#include "RCC_interface.h"
#include"RCC_private.h"
/*******************************************************************************
 *                      Function Definitions                                   *
 *******************************************************************************/

/*
 * Public Function
 * Description :
 * Setup the the system clock source
 * If the input system clock out of the system clock range the function will not handle the request and return error .
 * Function Paramters : Type of clock source
 * Function Return : Error Status of RCC
 */

rcc_tenuErrorState Enable_clock(u8 copy_u8clocktype) {
	    u32 timeout = 50;
		volatile u32 RDY;
	rcc_tenuErrorState loc_u8errorstate = RCC_ok;
	if (copy_u8clocktype > MAX_CLK_RANGE) {
		/* return Error because the  type is  out of the range */
		loc_u8errorstate = RCC_resError;
	} else {
		/* Check the type of clock source ( HSI or HSE or PLL ) */
		switch (copy_u8clocktype) {
	case HSI_CLK:
		/* Enbale HSI Source Clock */
		RCC->RCC_CR |= HSI_ON_MASK;
		RDY = RCC->RCC_CR & HSI_RDY_MASK;
		while (timeout && !RDY) {
			timeout--;
			RDY = RCC->RCC_CR & HSI_RDY_MASK;
		}
		if (RDY) {
			/* if the HSI is ready return ok */
			loc_u8errorstate = RCC_ok;
		} /* end of if (RDY) */

		break;

	case HSE_CLK:
		/* Enbale HSE Source Clock */
		RCC->RCC_CR |= HSE_ON_MASK;
		/* check the value of HSE Ready or not ready */
		RDY = RCC->RCC_CR & HSE_RDY_MASK;
		/* Waiting until the clock being ready or the timeout finished */
		while (timeout && !RDY) {
			timeout--;
			RDY = RCC->RCC_CR & HSE_RDY_MASK;
		}
		if (RDY) {
			/* if the HSE is ready return ok */
			loc_u8errorstate = RCC_ok;
		} /* end of if (RDY) */

		break;

	case PLL_CLK:
		/* Enbale PLL Source Clock */
		RCC->RCC_CR |= PLL_ON_MASK;
		RDY = RCC->RCC_CR & PLL_RDY_MASK;
		while (timeout && !RDY) {
			timeout--;
			RDY = RCC->RCC_CR & PLL_RDY_MASK;
		}
		if (RDY) {
			/* if the PLL is ready return ok */
			loc_u8errorstate = RCC_ok;
		} /* end of if (RDY) */

		break;

		} /* end of switch (copy_u8clocktype) */
	} /* end of else */

	return loc_u8errorstate;
} /* end of rcc_tenuErrorState Enable_clock(u8 copy_u8clocktype) */

/*
 * Public Function
 * Description :
 * Turn on / off  the the system clock source
 * Function Paramters : type of clock source and clock state(on or off )
 * Function Return : Rcc Error state
 */

rcc_tenuErrorState Select_system_clk(u8 copy_u8Clocktype) {
	/* Variable to store the RCC  Error Status */
	rcc_tenuErrorState loc_u8errorstate = RCC_ok;
	if (copy_u8Clocktype > MAX_CLK_RANGE) {
		/* return Error because the  type is  out of the range */
		loc_u8errorstate = RCC_resError;
	} /*  end of if (copy_u8Clocktype > MAX_CLK_RANGE)   */

	else {
		switch (copy_u8Clocktype) {
		volatile u32 var;
		case HSI_CLK:
			/* variable to store the RCC Configuration register value */
			 var = RCC->RCC_CFGR;
			/* variable to clear the sw bits */
			var &= SW_CLEAR_MASK;
			/* choose the HSI clock source */
			var |= SW_HSI_CLK;
			/* Assign the value to the configuration register */
			RCC->RCC_CFGR = var;

			break;

		case HSE_CLK:

			/* variable to store the RCC Configuration register value */
			var = RCC->RCC_CFGR;
			/* variable to clear the sw bits */
			var &= SW_CLEAR_MASK;
			/* choose the HSE clock source */
			var |= SW_HSE_CLK;
			/* Assign the value to the configuration register */
			RCC->RCC_CFGR = var;

			break;
		case PLL_CLK:

			/* variable to store the RCC Configuration register value */
			 var = RCC->RCC_CFGR;
			/* variable to clear the sw bits */
			var &= SW_CLEAR_MASK;
			/* choose the PLL clock source */
			var |= SW_PLL_CLK;
			/* Assign the value to the configuration register */
			RCC->RCC_CFGR = var;

			break;
		} /* end of switch (copy_u8Clocktype) */
		/* variable to store the RCC Configuration register value */
		volatile u32 var = RCC->RCC_CFGR;
		/* variable to store the number of counts */
		u32 timeout = 50;
		/* waiting until the source clock bits is equal to the source clock status bits  */
		while (timeout && ((var >> 2) & (SW_SET_MASK)) != ((var) & (SW_SET_MASK))) {
			/* Decrement the timeout value every loop cycle */
			timeout--;
		} /* end of	while( timeout && ( (var>>2) & (SW_SET_MASK) != (var) & (SW_SET_MASK) ) ) */
		if (((var >> 2) & (SW_SET_MASK)) == ((var) & (SW_SET_MASK))) {
			loc_u8errorstate = RCC_ok;
		} /* end of if ((var >> 2) & (SW_SET_MASK) == (var) & (SW_SET_MASK)) */
		else {

			// Do Nothing
		} /*  end of else */

	} /* end of else */

	return loc_u8errorstate;

} /*  end of rcc_tenuErrorState Select_system_clk(u8 copy_u8Clocktype)  */

/*
 * Public Function
 * Description :
 * Read the status of the system clock Ready or not Ready
 * if the clock type out of clock range or the pointer is equal to NULL the function will not handle the request and return error
 * Function Paramters : type of clock source & the clock state (ready or not ready)
 * Function Return : Rcc Error status
 */

rcc_tenuErrorState get_Clock_Status(u8 copy_u8Clocktype,
		pu8 add_pu8Clock_RDY_State) {

	/* Variable to store the RCC  Error Status */
	rcc_tenuErrorState loc_u8errorstate = RCC_ok;
	/* Check if the pointer is equal to NULL and return NULL Pointer Error */
	if (add_pu8Clock_RDY_State == NULL_PTR) {
		loc_u8errorstate = RCC_NullPointerError;
	} /* end of if(add_pu8Clock_RDY_State==NULL_PTR) */
	else if (copy_u8Clocktype > MAX_CLK_RANGE) {
		/* return Error because the  type is  out of the range */
		loc_u8errorstate = RCC_resError;
	} /*  end of else if (copy_u8Clocktype > MAX_CLK_RANGE)   */

	else {
		u32 timeout=50; /* variable to store the number of counts of the clock being ready */
		u8 RDY; /* variable to store the clock state of being ready or not ready */

		/* checking the type of clock HSI or HSE or PLL */

		switch (copy_u8Clocktype) {
		case HSI_CLK:
			/* variable  store the HSI clock state */
			RDY = RCC->RCC_CR & HSI_RDY_MASK;
			/* waiting until the clock being ready or the timeout  finished */
			while (timeout && !RDY) {
				/* Decrement the time count */
				timeout--;
				/* check again if the HSI clock is reay */
				RDY = RCC->RCC_CR & HSI_RDY_MASK;
			}
			if (RDY) {
				/* if the HSI is ready return ok */
				loc_u8errorstate = RCC_Ready;
				/* Storing the clock status */
				*(add_pu8Clock_RDY_State) = RDY;
			} /* end of if (RDY) */

			break;

		case HSE_CLK:
			/* variable  store the HSE clock state */
			RDY = RCC->RCC_CR & HSE_RDY_MASK;
			/* waiting until the clock being ready or the timeout  finished */
			while (timeout && !RDY) {
				/* Decrement the time count */
				timeout--;
				/* check again if the HSE clock is reay */
				RDY = RCC->RCC_CR & HSE_RDY_MASK;
			}
			if (RDY) {
				/* if the HSI is ready return ok */
				loc_u8errorstate = RCC_Ready;
				/* storing the clock status */
				*(add_pu8Clock_RDY_State) = RDY;
			} /* end of if (RDY) */

			break;

		case PLL_CLK:
			/* variable  store the PLL clock state */
			RDY = RCC->RCC_CR & PLL_RDY_MASK;
			/* waiting until the clock being ready or the timeout  finished */
			while (timeout && !RDY) {
				/* Decrement the time count */
				timeout--;
				/* check again if the PLL clock is reay */
				RDY = RCC->RCC_CR & PLL_RDY_MASK;
			}
			if (RDY) {
				/* if the HSI is ready return ok */
				loc_u8errorstate = RCC_Ready;
				/* storing the clock status */
				*(add_pu8Clock_RDY_State) = RDY;
			} /* end of if (RDY) */

		} /* end of switch (copy_u8Clocktype) */
	} /* end of else */
	return loc_u8errorstate;
}/* end of rcc_tenuErrorState get_Clock_Status(u8 copy_u8Clocktype,
 pu8 add_pu8Clock_RDY_State) */

/* Public Function
 * Description :
 * Setup the the PLL Configuration parameters
 * If the input Configuration parameters out of  range the function will not handle the request and return error .
 * Function Paramters :
 * M-> Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock from 2 -> 63
 * N->Main PLL (PLL) multiplication factor for VCO from 2 -> 432
 * PLLP INPUT Parameters masks
 * PLL_P_2_MASK
 * PLL_P_4_MASK
 * PLL_P_6_MASK
 * PLL_P_8_MASK
 * P->Main PLL (PLL) division factor for main system clock (2,4,6,8)
 * clk_src-> Main PLL(PLL) and audio PLL (PLLI2S) entry clock source (0->HSI & 1->HSE)
 * Q->Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks From 2->15
 * f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)
 * f(PLL general clock output) = f(VCO clock) / PLLP
 * f(USB OTG FS, SDIO, RNG clock output) = f(VCO clock) / PLLQ
 * Function Return : Error Status of RCC
 */

rcc_tenuErrorState PLL_Configuration(u8 copy_u8Mprescalar,
		u16 copy_u16Nmultiplier, u8 copy_u8Pprescalar, u8 copy_u8Qprescalar,
		u8 copy_u8clkSrc) {
	/* Variable to store the RCC  Error Status */
	rcc_tenuErrorState loc_u8errorstate = RCC_ok;
	/* check the Validity range of Main PLL  prescalar */
	if (copy_u8Mprescalar < MIN_M_RANGE || copy_u8Mprescalar > MAX_M_RANGE) {
		loc_u8errorstate = RCC_PLLWrongConfiguration;
	}
	/* Check the validity of Main PLL (PLL) multiplication factor range */
	else if (copy_u16Nmultiplier < MIN_N_RANGE
			|| copy_u16Nmultiplier > MAX_N_RANGE) {
		loc_u8errorstate = RCC_PLLWrongConfiguration;
	}
	/* check the validity of Main PLL (PLL) division factor for USB OTG FS */
	else if (copy_u8Qprescalar < MIN_Q_RANGE || copy_u8Qprescalar > MAX_Q_RANGE) {
		loc_u8errorstate = RCC_PLLWrongConfiguration;
	}

	else {
		/* variable to store the  PLL Configuration register value */
		volatile u32 pll_Reg = RCC->RCC_PLLCFGR;
		/* Clear all the last configuratin values */
		pll_Reg &= PLL_CLEAR_CONFIGURATION_MASK;
		/* set the new configuration values */
		pll_Reg |= (copy_u8Mprescalar << 0) | (copy_u16Nmultiplier << 6)
				| (copy_u8Pprescalar) | (copy_u8Qprescalar)
				| (copy_u8clkSrc << 22);
		/* Assign the new configuration values to the PLL Configuration Register */
		RCC->RCC_PLLCFGR = pll_Reg;
	}
	return loc_u8errorstate;

}/*end of rcc_tenuErrorState PLL_Configuration(u8 copy_u8Mprescalar,
 u16 copy_u16Nmultiplier, u8 copy_u8Pprescalar, u8 copy_u8Qprescalar,
 u8 copy_u8clkSrc) */

/*
 * Public Function
 * Description :
 * select the the Peripheral clock bus and setup the prescalar value
 * Function Paramters : the type of prescalar bus (AHB | APB1 | APB2) and prescalar value(2,4,6,8,16,64,128,256,512)
 * Function Return : Rcc Error status
 */

rcc_tenuErrorState Prescalar_Bus_Control(u32 copy_u32Bustype,
		u32 copy_u32Prescalarvalue) {
	/* Variable to store the RCC  Error Status */
	rcc_tenuErrorState loc_u8errorstate = RCC_ok;
	/* check the prescalar range */
	if (copy_u32Prescalarvalue > MAX_PRESCALAR_RANGE) {
		/* return RCC Bus Prescalar error */
		loc_u8errorstate = RCC_BusPrescalarError;
	} /* end of if(copy_u32Prescalarvalue > MAX_PRESCALAR_RANGE) */
	else if (copy_u32Bustype > MAX_BUS_RANGE) {
		/* return RCC Bus Range error */
		loc_u8errorstate = RCC_BusError;
	} /* end of else if (copy_u32Bustype > MAX_BUS_RANGE) */

	else {
		switch (copy_u32Bustype) {
		case AHB_BUS:
			RCC->RCC_PLLCFGR |= copy_u32Prescalarvalue;
			break;

			/* check the prescalar value of the APB1 Bus */
		case APB1_BUS:
			RCC->RCC_PLLCFGR |= copy_u32Prescalarvalue;
			break;
			/* check the prescalar value of the APB2 Bus */

		case APB2_BUS:
			RCC->RCC_PLLCFGR |= copy_u32Prescalarvalue;
			break;
		} /*end of switch (copy_u32Bustype)*/

	} /* end of else */
	return loc_u8errorstate;
}

/*
 * Public Function
 * Description :
 * Turn on/off  the the Peripheral clock
 * Function Paramters : the type of Bus  & the type of Bus Peripheral
 * Function Return : Rcc Error status
 */

rcc_tenuErrorState enable_clock_peripheral(u32 copy_u32Bustype,
		u64 copy_u64Peripheraltype) {
	/* Variable to store the RCC  Error Status */
	rcc_tenuErrorState loc_u8errorstate = RCC_ok;
	if (copy_u32Bustype > MAX_BUS_RANGE) {
		/* return RCC Bus Range error */
		loc_u8errorstate = RCC_BusError;
	} /* end of else if (copy_u32Bustype > MAX_BUS_RANGE) */

	switch (copy_u32Bustype) {
	case AHB_BUS:
		/* Enable the Peripheral in the AHB Bus */
		RCC->RCC_AHB1ENR |= copy_u64Peripheraltype;
		break;
	case APB1_BUS:
		/* Enable the peripheral in the APB1 Bus */
		RCC->RCC_APB1ENR |= copy_u64Peripheraltype;
		break;
	case APB2_BUS:
		/* Enable the peripheral in the APB2 Bus */
		RCC->RCC_APB2ENR|= copy_u64Peripheraltype;
		break;
	} /* end of switch (copy_u32Bustype) s*/
	return loc_u8errorstate;
}
