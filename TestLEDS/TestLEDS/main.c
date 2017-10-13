
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


    PinTypeGPIO(PIN_64, PIN_MODE_0, false);
    GPIODirModeSet(GPIOA0_BASE, 0x2, GPIO_DIR_MODE_OUT);
    while(1){
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
	return 0;
}
