
//Developed by Vincent Claes
// vincent.claes [at]pxl.be


#include <stdio.h>
#include <hw_types.h>
//#include <hw_gpio.h>
#include <hw_memmap.h>
//#include <hw_ints.h>
#include <gpio.h>
#include <pin.h>
//#include <interrupt.h>
//#include <prcm.h>
#include <utils.h>

int main(void)
{

    //LEDS
    PinTypeGPIO(PIN_64, PIN_MODE_0, false);
    GPIODirModeSet(GPIOA1_BASE, GPIO_PIN_1, GPIO_DIR_MODE_OUT);
    PinTypeGPIO(PIN_01, PIN_MODE_0, false);
    GPIODirModeSet(GPIOA1_BASE, GPIO_PIN_2, GPIO_DIR_MODE_OUT);
    PinTypeGPIO(PIN_02, PIN_MODE_0, false);
    GPIODirModeSet(GPIOA1_BASE, GPIO_PIN_3, GPIO_DIR_MODE_OUT);

    PinTypeGPIO(PIN_15, PIN_MODE_0, false);
    GPIODirModeSet(GPIOA2_BASE, GPIO_PIN_6, GPIO_DIR_MODE_IN);
    PinTypeGPIO(PIN_04, PIN_MODE_0, false);
    GPIODirModeSet(GPIOA2_BASE, GPIO_PIN_6, GPIO_DIR_MODE_IN);


    while(1){

        if(GPIOPinRead(GPIOA2_BASE,GPIO_PIN_6))
        {
            GPIOPinWrite(GPIOA1_BASE,0x2,0x2);
            UtilsDelay(8000000);
            GPIOPinWrite(GPIOA1_BASE, 0x4,0x4);
            UtilsDelay(8000000);
            GPIOPinWrite(GPIOA1_BASE, 0x8,0x8);
            UtilsDelay(8000000);
            GPIOPinWrite(GPIOA1_BASE,0x2,~0x2);
            UtilsDelay(8000000);
            GPIOPinWrite(GPIOA1_BASE, 0x4,~0x4);
            UtilsDelay(8000000);
            GPIOPinWrite(GPIOA1_BASE, 0x8,~0x8);
            UtilsDelay(8000000);
        }
        else
        {
            GPIOPinWrite(GPIOA1_BASE,0x2,0x00);
            UtilsDelay(8000000);
            GPIOPinWrite(GPIOA1_BASE, 0x4,0x00);
            UtilsDelay(8000000);
            GPIOPinWrite(GPIOA1_BASE, 0x8,0x00);
            UtilsDelay(8000000);

        }
    }
	return 0;
}
