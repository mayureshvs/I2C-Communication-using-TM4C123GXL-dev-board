

#include <stdint.h>
#include <stdbool.h>
//#include "Tiva_i2c.h"
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_i2c.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/i2c.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"

void slaveinitI2C0(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);

    //reset I2C module
    SysCtlPeripheralReset(SYSCTL_PERIPH_I2C0);

    //enable GPIO peripheral that contains I2C
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

    // Configure the pin muxing for I2C0 functions on port B2 and B3.
    GPIOPinConfigure(GPIO_PB2_I2C0SCL);
    GPIOPinConfigure(GPIO_PB3_I2C0SDA);

    // Select the I2C function for these pins.
    GPIOPinTypeI2CSCL(GPIO_PORTB_BASE, GPIO_PIN_2);
    GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_3);
    //I2CSlaveEnable(I2C0_BASE);
    // Enable and initialize the I2C0 master module.  Use the system clock for
    // the I2C0 module.  The last parameter sets the I2C data transfer rate.
    // If false the data rate is set to 100kbps and if true the data rate will
    // be set to 400kbps.
    //(I2C0_BASE, 0, 0b0000001);
    I2CSlaveInit(I2C0_BASE, 0b0000001);
    //I2CMasterInitExpClk(I2C0_BASE, SysCtlClockGet(), false);

    //clear I2C FIFOs
    HWREG(I2C0_BASE + I2C_O_FIFOCTL) = 80008000;
}

int main()
{
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
       GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_2);
       slaveinitI2C0();
    while(1)
    {
        if(I2CSlaveStatus(I2C0_BASE)==I2C_SLAVE_ACT_RREQ)
        {
            I2CSlaveACKOverride(I2C0_BASE, true);
            I2CSlaveACKValueSet(I2C0_BASE, true);

            if((I2CSlaveDataGet(I2C0_BASE)=='k'))
                {
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0xFF);
                }
        }
    }

}

