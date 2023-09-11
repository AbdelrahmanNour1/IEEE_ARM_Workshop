/****************************************************************/
/******* Author    : Abdelrahman Mohamed Nour   *****************/
/******* Date      : 28 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : RCC_private.h              *****************/
/****************************************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/**
 * @defgroup RCC_Registers
 * @brief Reset and Clock Control (RCC) Registers
 *
 * This module provides definitions for the RCC (Reset and Clock Control) registers
 * for configuring and controlling system clocks and resets in the microcontroller.
 *
 * @{
 */

/**
 * @brief RCC Control Register (CR)
 *
 * This register provides control over the main and PLL (Phase-Locked Loop) system clocks.
 */
#define RCC_CR (*((volatile u32 *)0x40021000))

/**
 * @brief RCC Configuration Register (CFGR)
 *
 * This register configures the system clock sources, prescalers, and peripherals clocks.
 */
#define RCC_CFGR (*((volatile u32 *)0x40021004))

/**
 * @brief RCC Clock Interrupt Register (CIR)
 *
 * This register manages clock interrupts and flags.
 */
#define RCC_CIR (*((volatile u32 *)0x40021008))

/**
 * @brief RCC APB2 Peripheral Reset Register (APB2RSTR)
 *
 * This register controls the reset state of peripherals connected to APB2 bus.
 */
#define RCC_APB2RSTR (*((volatile u32 *)0x4002100C))

/**
 * @brief RCC APB1 Peripheral Reset Register (APB1RSTR)
 *
 * This register controls the reset state of peripherals connected to APB1 bus.
 */
#define RCC_APB1RSTR (*((volatile u32 *)0x40021010))

/**
 * @brief RCC AHB Peripheral Clock Enable Register (AHBENR)
 *
 * This register enables clock access for peripherals connected to AHB bus.
 */
#define RCC_AHBENR (*((volatile u32 *)0x40021014))

/**
 * @brief RCC APB1 Peripheral Clock Enable Register (APB1ENR)
 *
 * This register enables clock access for peripherals connected to APB1 bus.
 */
#define RCC_APB1ENR (*((volatile u32 *)0x4002101C))

/**
 * @brief RCC APB2 Peripheral Clock Enable Register (APB2ENR)
 *
 * This register enables clock access for peripherals connected to APB2 bus.
 */
#define RCC_APB2ENR (*((volatile u32 *)0x40021018))

/**
 * @brief RCC Backup Domain Control Register (BDCR)
 *
 * This register provides control over backup domain and RTC (Real-Time Clock).
 */
#define RCC_BDCR (*((volatile u32 *)0x40021020))

/**
 * @brief RCC Control and Status Register (CSR)
 *
 * This register provides various control and status flags.
 */
#define RCC_CSR (*((volatile u32 *)0x40021024))

/** @} */ // end of RCC Control Register (CR)

/**
 * @defgroup RCC_CR_Bit_Definitions RCC Control Register (RCC_CR) Bit Definitions
 * @{
 */

#define RCC_CR_HSION 0   /**< Internal High-Speed Clock Enable */
#define RCC_CR_HSIRDY 1  /**< Internal High-Speed Clock Ready */
#define RCC_CR_HSICAL 8  /**< Internal High-Speed Clock Calibration */
#define RCC_CR_HSEON 16  /**< External High-Speed Clock Enable */
#define RCC_CR_HSERDY 17 /**< External High-Speed Clock Ready */
#define RCC_CR_HSEBYP 18 /**< External High-Speed Clock Bypass */
#define RCC_CR_HSEPRE 19 /**< External High-Speed Clock Prescaler */
#define RCC_CR_CSSON 24  /**< Clock Security System Enable */
#define RCC_CR_PLLON 24  /**< PLL Enable */
#define RCC_CR_PLLRDY 25 /**< PLL Ready */

/** @} */ // end of RCC_CR_Bit_Definitions

/**
 * @defgroup RCC_CFGR_Bit_Definitions RCC Control Register (RCC_CFGR) Bit Definitions
 * @{
 */

#define RCC_CFGR_SW0 0
#define RCC_CFGR_SW1 1
#define RCC_CFGR_SWS0 2
#define RCC_CFGR_SWS1 3
#define RCC_CFGR_HPRE0 4
#define RCC_CFGR_HPRE1 5
#define RCC_CFGR_HPRE2 6
#define RCC_CFGR_HPRE3 7
#define RCC_CFGR_PPRE10 8
#define RCC_CFGR_PPRE11 9
#define RCC_CFGR_PPRE12 10
#define RCC_CFGR_PPRE20 11
#define RCC_CFGR_PPRE21 12
#define RCC_CFGR_PPRE22 13
#define RCC_CFGR_ADCPRE0 14
#define RCC_CFGR_ADCPRE1 15
#define RCC_CFGR_PLLSRC 16
#define RCC_CFGR_PLLXTRPE 17
#define RCC_CFGR_PLLMUL0 18
#define RCC_CFGR_PLLMUL1 19
#define RCC_CFGR_PLLMUL2 20
#define RCC_CFGR_PLLMUL3 21
#define RCC_CFGR_USBPRE 22
#define RCC_CFGR_MCO0 24
#define RCC_CFGR_MCO1 25
#define RCC_CFGR_MCO2 26
#define RCC_CFGR_MCO3 27

/** @} */ // end of RCC_CFGR_Bit_Definitions

/**
 * @defgroup RCC_Clock_Source RCC Clock Source Macros
 * @{
 */

#define RCC_HSI 0 /**< High-Speed Internal Clock Source (HSI) */
#define RCC_HSE 1 /**< High-Speed External Clock Source (HSE) */
#define RCC_PLL 2 /**< Phase-Locked Loop Clock Source (PLL) */

/** @} */ // end of RCC_Clock_Source

/**
 * @defgroup PLL_Input_Source RCC Clock Source Macros
 * @{
 */

#define RCC_PLL_HSI_DIV_2 0 /**< HSI oscillator clock divided by 2 */
#define RCC_PLL_HSE_DIV_2 1 /**< HSE oscillator clock divided by 2 */
#define RCC_PLL_HSE 2       /**< HSE oscillator clock              */

/** @} */ // end of PLL_Input_Source

/**
 * @defgroup PLL_Multiplication_Value RCC Clock Source Macros
 * @{
 */

#define RCC_PLL_MUL_4 2   /**< x4   */
#define RCC_PLL_MUL_5 3   /**< x5   */
#define RCC_PLL_MUL_6 4   /**< x6   */
#define RCC_PLL_MUL_7 5   /**< x7   */
#define RCC_PLL_MUL_8 6   /**< x8   */
#define RCC_PLL_MUL_9 7   /**< x9   */
#define RCC_PLL_MUL_65 13 /**< x6.5 */

/** @} */ // end of PLL_Multiplication_Value

/**
 * @defgroup RCC_Clock_Type RCC Clock Type Macros
 * @{
 */

#define RCC_CRYSTAL_CLK_ 0 /**< Crystal Oscillator Clock Type */
#define RCC_RC_CLK_ 1      /**< RC Oscillator Clock Type */

/** @} */ // end of RCC_Clock_Type

#endif /* RCC_PRIVATE_H_ */