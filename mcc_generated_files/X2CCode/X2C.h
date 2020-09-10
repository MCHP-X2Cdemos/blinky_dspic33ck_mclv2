/**
 * @file
 * @brief Generated model file.
 * 
 * Date:  2020-09-10 13:45
 * 
 * X2C-Version: 6.1.1707
 * X2C-Edition: Free
 */
/* This file is part of X2C. http://x2c.lcm.at/                                                                       */

/* Model: blinky_dspic33ck_mclv2                                                                                      */
/* Date:  2020-09-10 13:45                                                                                            */

/* X2C-Version: 6.1.1707                                                                                              */
/* X2C-Edition: Free                                                                                                  */

#ifndef X2C_H
#define X2C_H

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************************************************************/
/**     Includes                                                                                                     **/
/**********************************************************************************************************************/
#include "Constant_FiP16.h"
#include "AutoSwitch_FiP16.h"
#include "Delay_FiP16.h"
#include "Constant_Bool.h"
#include "I_FiP16.h"
#include "Negation_FiP16.h"
#include "PT1_FiP16.h"
#include "Sin3Gen_FiP16.h"
#include "SinGen_FiP16.h"
#include "Scope_Main.h"
#include "CommonFcts.h"

/**********************************************************************************************************************/
/**     Defines                                                                                                      **/
/**********************************************************************************************************************/
#define FUNCTIONS \
    CONSTANT_FIP16_FUNCTIONS , \
    AUTOSWITCH_FIP16_FUNCTIONS , \
    DELAY_FIP16_FUNCTIONS , \
    CONSTANT_BOOL_FUNCTIONS , \
    I_FIP16_FUNCTIONS , \
    NEGATION_FIP16_FUNCTIONS , \
    PT1_FIP16_FUNCTIONS , \
    SIN3GEN_FIP16_FUNCTIONS , \
    SINGEN_FIP16_FUNCTIONS , \
    SCOPE_MAIN_FUNCTIONS

#define PARAMETER_TABLE \
    { 1, &x2cModel.blocks.bAmplitude } , \
    { 2, &x2cModel.blocks.bAutoSwitch } , \
    { 3, &x2cModel.blocks.bAutoSwitch1 } , \
    { 4, &x2cModel.blocks.bFrequency } , \
    { 5, &x2cModel.blocks.bLED_off } , \
    { 6, &x2cModel.blocks.bLED_on } , \
    { 7, &x2cModel.blocks.sOscillator.bAutoSwitch } , \
    { 8, &x2cModel.blocks.sOscillator.bConstant } , \
    { 9, &x2cModel.blocks.sOscillator.bDelay } , \
    { 10, &x2cModel.blocks.sOscillator.bEnable } , \
    { 11, &x2cModel.blocks.sOscillator.bInit } , \
    { 12, &x2cModel.blocks.sOscillator.bIntegrator } , \
    { 13, &x2cModel.blocks.sOscillator.bNegation } , \
    { 14, &x2cModel.blocks.bPT1 } , \
    { 15, &x2cModel.blocks.bSin3Gen } , \
    { 16, &x2cModel.blocks.bSinGen } , \
    { 25, &x2cScope }

#define INPORT_PARAMID_TABLE \
    { 17, 2, &x2cModel.inports.bCPULoad } , \
    { 18, 2, &x2cModel.inports.bS2 } , \
    { 19, 2, &x2cModel.inports.bS3 } , \
    { 20, 2, &x2cModel.inports.bVPot } 

#define OUTPORT_PARAMID_TABLE \
    { 21, 2, &x2cModel.outports.bFLT } , \
    { 22, 2, &x2cModel.outports.bLED1 } , \
    { 23, 2, &x2cModel.outports.bLED2 } , \
    { 24, 2, &x2cModel.outports.bOsc_out } 


/**********************************************************************************************************************/
/**                                            Model structure definition                                            **/
/**********************************************************************************************************************/
struct x2cModel {
/*  Control Blocks                                                                                                    */
    struct {
/*      Sub-system Oscillator                                                                                         */
        struct {
            AUTOSWITCH_FIP16 bAutoSwitch;
            CONSTANT_FIP16 bConstant;
            DELAY_FIP16 bDelay;
            CONSTANT_BOOL bEnable;
            CONSTANT_FIP16 bInit;
            I_FIP16 bIntegrator;
            NEGATION_FIP16 bNegation;
        } sOscillator;
        CONSTANT_FIP16 bAmplitude;
        AUTOSWITCH_FIP16 bAutoSwitch;
        AUTOSWITCH_FIP16 bAutoSwitch1;
        CONSTANT_FIP16 bFrequency;
        CONSTANT_FIP16 bLED_off;
        CONSTANT_FIP16 bLED_on;
        PT1_FIP16 bPT1;
        SIN3GEN_FIP16 bSin3Gen;
        SINGEN_FIP16 bSinGen;
    } blocks;
/*  Inports                                                                                                           */
    struct {
        int16 bCPULoad;
        int16 bS2;
        int16 bS3;
        int16 bVPot;
    } inports;
/*  Outports                                                                                                          */
    struct {
        int16* bFLT;
        int16* bLED1;
        int16* bLED2;
        int16* bOsc_out;
    } outports;
};

/**********************************************************************************************************************/
/**     Externals                                                                                                    **/
/**********************************************************************************************************************/
extern struct x2cModel x2cModel;

extern const tBlockFunctions blockFunctionTable[];
extern const tParameterTable parameterIdTable[];
extern const tIoParamIdEntry inportParamIdTable[];
extern const tIoParamIdEntry outportParamIdTable[];

#define X2C_UPDATE_3_DIVIDER 3

/**********************************************************************************************************************/
/**     Prototypes                                                                                                   **/
/**********************************************************************************************************************/
void X2C_Init(void);
void X2C_Update(void);
void X2C_Update_1(void);
void X2C_Update_3(void);

#ifdef __cplusplus
}
#endif

#endif
