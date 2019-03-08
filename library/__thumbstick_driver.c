/*
    __thumbstick_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__thumbstick_driver.h"
#include "__thumbstick_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __THUMBSTICK_DRV_I2C__
static uint8_t _slaveAddress;
#endif

const uint8_t _THUMBSTICK_START_SINGLE_ENDED_BIT                         = 0x04;
const uint8_t _THUMBSTICK_CHANNEL_1                                      = 0x01;
const uint8_t _THUMBSTICK_CHANNEL_2                                      = 0x02;
const uint8_t _THUMBSTICK_POSITION_START                                 = 0x00;
const uint8_t _THUMBSTICK_POSITION_TOP                                   = 0x01;
const uint8_t _THUMBSTICK_POSITION_RIGHT                                 = 0x02;
const uint8_t _THUMBSTICK_CHANNEL_BOTTOM                                 = 0x03;
const uint8_t _THUMBSTICK_CHANNEL_LEFT                                   = 0x04;
const uint8_t _THUMBSTICK_BUTTON_INACTIVE                                = 0x00;
const uint8_t _THUMBSTICK_BUTTON_ACTIVE                                  = 0x01;


/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __THUMBSTICK_DRV_SPI__

void thumbstick_spiDriverInit(T_THUMBSTICK_P gpioObj, T_THUMBSTICK_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_csSet( 0 );
}

#endif
#ifdef   __THUMBSTICK_DRV_I2C__

void thumbstick_i2cDriverInit(T_THUMBSTICK_P gpioObj, T_THUMBSTICK_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __THUMBSTICK_DRV_UART__

void thumbstick_uartDriverInit(T_THUMBSTICK_P gpioObj, T_THUMBSTICK_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif



/* ----------------------------------------------------------- IMPLEMENTATION */


/* Generic read 2 byte of data function */
uint16_t thumbstick_readData( uint8_t readChannel )
{
    uint8_t wBuffer[ 1 ];
    uint8_t rBuffer[ 2 ];
    uint16_t result;
    
    result = 0x00;

    wBuffer[ 0 ] = _THUMBSTICK_START_SINGLE_ENDED_BIT | readChannel;

    hal_gpio_csSet( 0 );
    hal_spiWrite( wBuffer, 1 );
    hal_spiRead( rBuffer, 2 );;
    hal_gpio_csSet( 1 );

    result = rBuffer[ 0 ] & 0x0F ;
    result <<= 8;
    result |= rBuffer[ 1 ];

    return result;
}

/* Get thumbstick position function */
uint8_t thumbstick_getPosition()
{
    uint16_t ch1;
    uint16_t ch2;
    uint8_t position;
    
    ch1 = thumbstick_readData( _THUMBSTICK_CHANNEL_1 );

    ch2 = thumbstick_readData( _THUMBSTICK_CHANNEL_2 );
    
    position = 0;
    
    if ( ch1 < 24 && ch2 < 24 )
        position = 1;
    else if ( ch1 < 24 && ch2 < 4072 )
        position = 2;
    else if ( ch1 > 48 && ch2 > 2072 )
        position = 3;
    else if ( ch1 > 48 && ch2 < 4072 )
        position = 4;
        
    return position;
}

/* Get state of thumbstick button function */
uint8_t thumbstick_pressButton()
{
    return !hal_gpio_intGet();
}



/* -------------------------------------------------------------------------- */
/*
  __thumbstick_driver.c

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