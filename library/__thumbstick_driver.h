/*
    __thumbstick_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __thumbstick_driver.h
@brief    Thumbstick Driver
@mainpage Thumbstick Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   THUMBSTICK
@brief      Thumbstick Click Driver
@{

| Global Library Prefix | **THUMBSTICK** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Dec 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _THUMBSTICK_H_
#define _THUMBSTICK_H_

/** 
 * @macro T_THUMBSTICK_P
 * @brief Driver Abstract type 
 */
#define T_THUMBSTICK_P    const uint8_t*

/** @defgroup THUMBSTICK_COMPILE Compilation Config */              /** @{ */

   #define   __THUMBSTICK_DRV_SPI__                            /**<     @macro __THUMBSTICK_DRV_SPI__  @brief SPI driver selector */
//  #define   __THUMBSTICK_DRV_I2C__                            /**<     @macro __THUMBSTICK_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __THUMBSTICK_DRV_UART__                           /**<     @macro __THUMBSTICK_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup THUMBSTICK_VAR Variables */                           /** @{ */


extern const uint8_t _THUMBSTICK_CHANNEL_1;
extern const uint8_t _THUMBSTICK_CHANNEL_2;
extern const uint8_t _THUMBSTICK_POSITION_START;
extern const uint8_t _THUMBSTICK_POSITION_TOP;
extern const uint8_t _THUMBSTICK_POSITION_RIGHT;
extern const uint8_t _THUMBSTICK_CHANNEL_BOTTOM;
extern const uint8_t _THUMBSTICK_CHANNEL_LEFT;
extern const uint8_t _THUMBSTICK_BUTTON_INACTIVE;
extern const uint8_t _THUMBSTICK_BUTTON_ACTIVE;
                                                                       /** @} */
/** @defgroup THUMBSTICK_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup THUMBSTICK_INIT Driver Initialization */              /** @{ */

#ifdef   __THUMBSTICK_DRV_SPI__
void thumbstick_spiDriverInit(T_THUMBSTICK_P gpioObj, T_THUMBSTICK_P spiObj);
#endif
#ifdef   __THUMBSTICK_DRV_I2C__
void thumbstick_i2cDriverInit(T_THUMBSTICK_P gpioObj, T_THUMBSTICK_P i2cObj, uint8_t slave);
#endif
#ifdef   __THUMBSTICK_DRV_UART__
void thumbstick_uartDriverInit(T_THUMBSTICK_P gpioObj, T_THUMBSTICK_P uartObj);
#endif


/** @defgroup THUMBSTICK_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Generic read 2 byte of data function
 *
 * @param[in] readChannel
 * - Channel:
 * - 1 : first channel;
 * - 2 : secound chennel;
 *
 * @return
 * 14-bit read ADC data
 *
 * Function read 14-bit ADC data from selected channel
 * from MCP3204 chip of the Thumbstick Click.
 */
uint16_t thumbstick_readData( uint8_t readChannel );

/**
 * @brief Get thumbstick position function
 *
 * @return
 * 8-bit data of position
 * - 0 : Start           Position;
 * - 1 : Top             Position;
 * - 2 : Right           Position;
 * - 3 : Bottom          Position;
 * - 4 : Left            Position;
 *
 * Function get position of thumbstick,
 * return position state value from 0 to 5 that calculeted
 * by the value read ADC value from the MCP3204 chip.
 */
uint8_t thumbstick_getPosition();

/**
 * @brief Get state of thumbstick button function
 *
 * @return
 * state of thumbstick button:
 * - 0 : not active;
 * - 1 : active;
 *
 * Function return state of thumbstick button 0 or 1
 * by read state of INT  pin
 * from MCP3204 chip of the Thumbstick Click.
 */
uint8_t thumbstick_pressButton();



                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Thumbstick_STM.c
    @example Click_Thumbstick_TIVA.c
    @example Click_Thumbstick_CEC.c
    @example Click_Thumbstick_KINETIS.c
    @example Click_Thumbstick_MSP.c
    @example Click_Thumbstick_PIC.c
    @example Click_Thumbstick_PIC32.c
    @example Click_Thumbstick_DSPIC.c
    @example Click_Thumbstick_AVR.c
    @example Click_Thumbstick_FT90x.c
    @example Click_Thumbstick_STM.mbas
    @example Click_Thumbstick_TIVA.mbas
    @example Click_Thumbstick_CEC.mbas
    @example Click_Thumbstick_KINETIS.mbas
    @example Click_Thumbstick_MSP.mbas
    @example Click_Thumbstick_PIC.mbas
    @example Click_Thumbstick_PIC32.mbas
    @example Click_Thumbstick_DSPIC.mbas
    @example Click_Thumbstick_AVR.mbas
    @example Click_Thumbstick_FT90x.mbas
    @example Click_Thumbstick_STM.mpas
    @example Click_Thumbstick_TIVA.mpas
    @example Click_Thumbstick_CEC.mpas
    @example Click_Thumbstick_KINETIS.mpas
    @example Click_Thumbstick_MSP.mpas
    @example Click_Thumbstick_PIC.mpas
    @example Click_Thumbstick_PIC32.mpas
    @example Click_Thumbstick_DSPIC.mpas
    @example Click_Thumbstick_AVR.mpas
    @example Click_Thumbstick_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __thumbstick_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */