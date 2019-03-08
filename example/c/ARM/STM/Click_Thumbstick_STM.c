/*
Example for Thumbstick Click

    Date          : Dec 2018.
    Author        : Nenad Filipovic

Test configuration STM32 :

    MCU              : STM32F107VCT6
    Dev. Board       : EasyMx PRO v7 for STM32
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes SPI, GPIO and LOG structures,
     set INT pin as input, CS and RST pins as output.
- Application Initialization - Initialization driver enable's - SPI and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of Thumbstick Click board.
     Thumbstick Click communicates with register via SPI by read ADC value from the MCP3204 chip,
     getget position of thumbstick ( joystick ) and get thumbstick press button state.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs write on usb uart when the thumbstick is triggered.


*/

#include "Click_Thumbstick_types.h"
#include "Click_Thumbstick_config.h"


uint8_t position;
uint8_t buttonState;
uint8_t positionOld = 0xFF;
uint8_t buttonStateOld = 0;

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );

    mikrobus_spiInit( _MIKROBUS1, &_THUMBSTICK_SPI_CFG[0] );

    mikrobus_logInit( _LOG_USBUART_A, 9600 );

    Delay_100ms();
}

void applicationInit()
{
    thumbstick_spiDriverInit( (T_THUMBSTICK_P)&_MIKROBUS1_GPIO, (T_THUMBSTICK_P)&_MIKROBUS1_SPI );

    mikrobus_logWrite( "-------------------", _LOG_LINE );
    mikrobus_logWrite( " Thumbstick  Click ", _LOG_LINE );
    mikrobus_logWrite( "-------------------", _LOG_LINE );
}

void applicationTask()
{
    position = thumbstick_getPosition();

    buttonState = thumbstick_pressButton();

    if ( buttonState == _THUMBSTICK_BUTTON_ACTIVE && buttonStateOld == _THUMBSTICK_BUTTON_INACTIVE )
    {
        buttonStateOld = _THUMBSTICK_BUTTON_ACTIVE;

        mikrobus_logWrite( " Button is pressed ", _LOG_LINE );
        mikrobus_logWrite( "-------------------", _LOG_LINE );
    }

    if ( buttonState == _THUMBSTICK_BUTTON_INACTIVE && buttonStateOld == _THUMBSTICK_BUTTON_ACTIVE )
    {
        buttonStateOld = _THUMBSTICK_BUTTON_INACTIVE;
    }

    if ( positionOld != position )
    {
        if ( position == _THUMBSTICK_POSITION_START )
            mikrobus_logWrite( "     S T A R T", _LOG_LINE );

        if ( position == _THUMBSTICK_POSITION_TOP )
            mikrobus_logWrite( "       T O P", _LOG_LINE );

        if ( position == _THUMBSTICK_POSITION_RIGHT )
            mikrobus_logWrite( "     R I G H T", _LOG_LINE );

        if ( position == _THUMBSTICK_CHANNEL_BOTTOM )
            mikrobus_logWrite( "    B O T T O M", _LOG_LINE );

        if ( position == _THUMBSTICK_CHANNEL_LEFT )
            mikrobus_logWrite( "      L E F T", _LOG_LINE );

        mikrobus_logWrite( "-------------------", _LOG_LINE );

        positionOld = position;
    }
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}