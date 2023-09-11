/****************************************************************/
/******* Author    : Abdelrahman Mohamed Nour   *****************/
/******* Date      : 28 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : RCC_config.h               *****************/
/****************************************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/**
 * @defgroup RCC_System_Clock_Config RCC System Clock Configuration Macros
 * @brief Macros for configuring the RCC system clock source and type.
 * @{
 */

/**
 * @brief Select the system clock source.
 * @note Choose one of the available options:
 *       - RCC_HSI: High-Speed Internal Clock Source (HSI).
 *                  This option uses the internal high-speed oscillator as the system clock source.
 *                  The HSI provides a stable and accurate clock source, suitable for most applications.
 *       - RCC_HSE: High-Speed External Clock Source (HSE).
 *                  This option uses an external crystal oscillator as the system clock source.
 *                  The HSE provides a higher level of accuracy and stability compared to HSI.
 *                  It is recommended for applications requiring precise timing.
 *       - RCC_PLL: Phase-Locked Loop Clock Source (PLL).
 *                  This option uses the PLL as the system clock source, which multiplies
 *                  the frequency of an input clock source (e.g., HSI or HSE) to generate
 *                  a higher frequency output. PLL provides flexibility in tuning the clock frequency,
 *                  making it suitable for applications with specific performance requirements.
 */
#define RCC_SYSCLK RCC_PLL

/**
 * @brief Select the PLL source(if PLL is input clock).
 * @note Choose one of the available options:
 *       - RCC_PLL_HSI_DIV_2: HSI/2
 *       - RCC_PLL_HSE_DIV_2: HSE/2
 *       - RCC_PLL_HSE:       HSE
 */
#if RCC_SYSCLK == RCC_PLL
#define RCC_PLL_INPUT RCC_PLL_HSE
#endif

/**
 * @brief Select the PLL Multiplication value(if PLL is input clock).
 * @note Choose one of the available options:
 *       - RCC_PLL_MUL_4  : x4
 *       - RCC_PLL_MUL_5  : x5
 *       - RCC_PLL_MUL_6  : x6
 *       - RCC_PLL_MUL_7  : x7
 *       - RCC_PLL_MUL_8  : x8
 *       - RCC_PLL_MUL_9  : x9
 *       _ RCC_PLL_MUL_65 : x6.5
 */
#if RCC_SYSCLK == RCC_PLL
#define RCC_PLL_MUL RCC_PLL_MUL_4
#endif

/**
 * @brief Configure the clock type for RCC_SYSCLK when using RCC_HSE.
 * @note Choose one of the available options:
 *       RCC_RC_CLK_       - RC oscillator will be the source of the clock system.
 *       RCC_CRYSTAL_CLK_  - Crystal oscillator will be the source of the clock system.
 */
#if RCC_SYSCLK == RCC_HSE

#define RCC_CLK_BYPASS RCC_CRYSTAL_CLK_

#endif /**< RCC_SYSCLK */

#if RCC_SYSCLK == RCC_PLL

#endif /**< RCC_SYSCLK */

/** @} */ // end of RCC_System_Clock_Config

#endif /**< RCC_CONFIG_H_ */