/* ************************************************************************** */
/** X2CMain.c

  @Company
    Microchip Technology

  @Summary
 Implementation of X2C In and Outport connections

 */
/* ************************************************************************** */
#include <xc.h>
#include "X2CMain.h"

#include "X2C.h"
#ifndef X2C_H
#warning "Please generate the code from the model!"
#endif

#include "mcc.h"

int16_t StartTime;
int16_t StopTime;

void UpdateInports(void) {

    /*
     * Pass the peripheral values to model Inports
     * if (PORTA & 1) { 
     *    x2cModel.inports.bInport = INT16_MAX;
     * }else {
     *    x2cModel.inports.bInport = 0;
     * }
     * 
     * The following inputs of the model can be used:
      x2cModel.inports.bCPULoad = Scaling*A_PeripheralVariable
      x2cModel.inports.bS2 = Scaling*A_PeripheralVariable
      x2cModel.inports.bS3 = Scaling*A_PeripheralVariable
      x2cModel.inports.bVPot = Scaling*A_PeripheralVariable

     */
    
    if (ButtonS3_GetValue() != 0) {
        x2cModel.inports.bS3 = 0;
    } else {
        x2cModel.inports.bS3 = INT16_MAX;
    }
    if (ButtonS2_GetValue() != 0) {
        x2cModel.inports.bS2 = 0;
    } else {
        x2cModel.inports.bS2 = INT16_MAX;
    }
    
    
    //x2cModel.inports.bVPot = ADC1_ConversionResultGet(POT);
    
    ADC1_SoftwareTriggerDisable();
    x2cModel.inports.bVPot = (int16_t)ADC1_ConversionResultGet(POT)+32768;  //Scale to FIP16 
    ADC1_ChannelSelect(POT);
    ADC1_SoftwareTriggerEnable();
    
    x2cModel.inports.bCPULoad = StopTime;
    //x2cModel.inports.bCPULoad = (int16)(TMR1_Period16BitGet());
}

void UpdateOutports(void) {
    
    /*
     * Pass model outports to peripherals e.g.:
     * 
     * if (*x2cModel.outports.bOutport) {  // if model Outport differ than zero 
     *    LATB |= 1; // set LATB0 
     * } else {
     *    LATB &= ~1; // clear LATB0
     * }    
     * 
     * The following outputs of the model can be used:
      A_PeripheralVariable = *x2cModel.outports.bFLT*Scaling
      A_PeripheralVariable = *x2cModel.outports.bLED1*Scaling
      A_PeripheralVariable = *x2cModel.outports.bLED2*Scaling
      A_PeripheralVariable = *x2cModel.outports.bOsc_out*Scaling
      A_PeripheralVariable = *x2cModel.outports.bRGB_GREEN*Scaling
      A_PeripheralVariable = *x2cModel.outports.bRGB_RED*Scaling
     */ 
    if (*x2cModel.outports.bLED1 != 0) {
        LED1_SetHigh();
    } else {
        LED1_SetLow();
    }    
    
    if (*x2cModel.outports.bLED2 != 0) {
        LED2_SetHigh();
    } else {
        LED2_SetLow();
    }
    
}
/**
 * Calls the inports update function
 * Then run model calculation
 * Last read model outports and update the peripherals
*/

//Interrupt handler to call model update
void TMR1_CallBack(void){
    StartTime=TMR1_Counter16BitGet();
    UpdateInports();
    X2C_Update();
    UpdateOutports();
    StopTime=TMR1_Counter16BitGet();
    //StopTime = (StopTime - StartTime)*((uint16)INT16_MAX/(100000000/10000));
    
    StopTime = (StopTime - StartTime)*((int16)INT16_MAX/(int16)(TMR1_Period16BitGet()));
}

/* *****************************************************************************
 End of File
 */
