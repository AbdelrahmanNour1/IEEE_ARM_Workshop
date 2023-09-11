/****************************************************************/
/******* Author    : Abdelrahman Mohamed Nour   *****************/
/******* Date      : 28 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : RCC_program.c              *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/*****************************< Function Implementations *****************************/
Std_ReturnType MCAL_RCC_InitSysClock(void)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

#if RCC_SYSCLK == RCC_HSE

/**< Enable the external clock to be the source for the system clock. */
#if RCC_CLK_BYPASS == RCC_RC_CLK_
    SET_BIT(RCC_CR, RCC_CR_HSEBYP); /**< Choose RC as a SYSCLK */
#elif RCC_CLK_BYPASS == RCC_CRYSTAL_CLK_
    CLR_BIT(RCC_CR, RCC_CR_HSEBYP); /**< Choose CRYSTAL as a SYSCLK */
#else
#error "Wrong Choice !!"
#endif /**< RCC_CLK_BYPASS */

    /**< Enable the High-Speed External clock. */
    SET_BIT(RCC_CR, RCC_CR_HSEON);

    /**< Wait until the High-Speed External clock is stable. */
    while (!GET_BIT(RCC_CR, RCC_CR_HSERDY))
        ;

    /**< Select High-Speed External clock as the system clock source. */
    RCC_CFGR = 0x00000001;

    Local_FunctionStatus = E_OK;

#elif RCC_SYSCLK == RCC_HSI

    /**< Enable the High-Speed Internal clock. */
    SET_BIT(RCC_CR, RCC_CR_HSION);

    /**< Wait until the High-Speed Internal clock is stable. */
    while (!GET_BIT(RCC_CR, RCC_CR_HSIRDY))
        ;

    /**< Select High-Speed Internal clock as the system clock source. */
    RCC_CFGR = 0x00000000;

    Local_FunctionStatus = E_OK;

#elif RCC_SYSCLK == RCC_PLL

        /**< PLL CLK Source */
#if RCC_PLL_INPUT == RCC_PLL_HSI_DIV_2
    CLR_BIT(RCC_CFGR, RCC_CFGR_PLLSRC);
#elif RCC_PLL_INPUT == RCC_PLL_HSE_DIV_2
    SET_BIT(RCC_CFGR, RCC_CFGR_PLLSRC);
    SET_BIT(RCC_CFGR, RCC_CFGR_PLLXTRPE);
#elif RCC_PLL_INPIT == RCC_PLL_HSE
    SET_BIT(RCC_CFGR, RCC_CFGR_PLLSRC);
    CLR_BIT(RCC_CFGR, RCC_CFGR_PLLXTRPE);
#endif

    /**<PLL MUL Value */
    RCC_CFGR = ((RCC_CFGR & 0xFFC3FFFF) | (RCC_PLL_MUL << RCC_CFGR_PLLMUL0));

    
    /**< Enable PLL. */
    SET_BIT(RCC_CR, RCC_CR_PLLON);

    /**< Wait until the PLL clock is locked. */
    while (!GET_BIT(RCC_CR, RCC_CR_PLLRDY))
        ;

    /**< Select PLL as the system clock source. */
    CLR_BIT(RCC_CFGR, RCC_CFGR_SW0);
    SET_BIT(RCC_CFGR, RCC_CFGR_SW1);

    Local_FunctionStatus = E_OK;

#else
#error "Wrong Choice !!"

#endif /**< RCC_SYSCLK */

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_RCC_EnablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch (Copy_BusId)
    {
    /**< Enable the peripheral on the AHB bus. */
    case RCC_AHB:
        SET_BIT(RCC_AHBENR, Copy_PeripheralId);
        Local_FunctionStatus = E_OK;
        break;

    /**< Enable the peripheral on the APB1 bus. */
    case RCC_APB1:
        SET_BIT(RCC_APB1ENR, Copy_PeripheralId);
        Local_FunctionStatus = E_OK;
        break;

    /**< Enable the peripheral on the APB2 bus. */
    case RCC_APB2:
        SET_BIT(RCC_APB2ENR, Copy_PeripheralId);
        Local_FunctionStatus = E_OK;
        break;

    default:
        Local_FunctionStatus = E_NOT_OK;
        break;
    }

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_RCC_DisablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch (Copy_BusId)
    {
    /**< Disable the peripheral on the AHB bus. */
    case RCC_AHB:
        CLR_BIT(RCC_AHBENR, Copy_PeripheralId);
        Local_FunctionStatus = E_OK;
        break;

    /**< Disable the peripheral on the APB1 bus. */
    case RCC_APB1:
        CLR_BIT(RCC_APB1ENR, Copy_PeripheralId);
        Local_FunctionStatus = E_OK;
        break;

    /**< Disable the peripheral on the APB2 bus. */
    case RCC_APB2:
        CLR_BIT(RCC_APB2ENR, Copy_PeripheralId);
        Local_FunctionStatus = E_OK;
        break;

    default:
        Local_FunctionStatus = E_NOT_OK;
        break;
    }

    return Local_FunctionStatus;
}

/*****************************< End of Function Implementations *****************************/
