![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Thumbstick Click

---

- **CIC Prefix**  : THUMBSTICK
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Dec 2018.

---

### Software Support

We provide a library for the Thumbstick Click on our [LibStock](https://libstock.mikroe.com/projects/view/1051/thumbstick-click-example) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control Thumbstick Click board.
Thumbstick click communicates with the target board via SPI. 
This library contains drivers for read ADC value from the MCP3204 chip,
get position of thumbstick and press button states.

Key functions :

- ``` uint16_t thumbstick_readData( uint8_t readChannel ) ``` - Generic read 2 byte of data function
- ``` uint8_t thumbstick_getPosition() ``` - Get thumbstick position function
- ``` uint8_t thumbstick_pressButton() ``` - Get state of thumbstick button function

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes SPI, GPIO and LOG structures,
     set INT pin as input, CS and RST pins as output.
- Application Initialization - Initialization driver enable's - SPI and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of Thumbstick Click board.
     Thumbstick Click communicates with register via SPI by read ADC value from the MCP3204 chip,
     get position of thumbstick ( joystick ) and get thumbstick press button state.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs write on usb uart when the thumbstick is triggered.


```.c

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

```



The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/1051/thumbstick-click-example) page.

Other mikroE Libraries used in the example:

- SPI


**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.|

---
---
