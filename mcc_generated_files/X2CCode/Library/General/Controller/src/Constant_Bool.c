/*
 * Copyright (c) 2017, Linz Center of Mechatronics GmbH (LCM) http://www.lcm.at/
 * All rights reserved.
 */
/*
 * This file is licensed according to the BSD 3-clause license as follows:
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the "Linz Center of Mechatronics GmbH" and "LCM" nor
 *       the names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL "Linz Center of Mechatronics GmbH" BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * This file is part of X2C. http://x2c.lcm.at/
 * $LastChangedRevision: 1603 $
 * $LastChangedDate:: 2019-01-21 19:02:13 +0100#$
 */
/* USERCODE-BEGIN:Description                                                                                         */
/* Description: */
/* USERCODE-END:Description                                                                                           */
#include "Constant_Bool.h"

/* USERCODE-BEGIN:PreProcessor                                                                                        */
/* Outputs */
#define OUT				(pTConstant_Bool->Out)

/* Parameter */
#define VALUE 			(pTConstant_Bool->K)

/* USERCODE-END:PreProcessor                                                                                          */

/**********************************************************************************************************************/
/** No Update function                                                                                               **/
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/** Initialization                                                                                                   **/
/**********************************************************************************************************************/
void Constant_Bool_Init(CONSTANT_BOOL *pTConstant_Bool)
{
    pTConstant_Bool->ID = CONSTANT_BOOL_ID;
    pTConstant_Bool->Out = 0;
/* USERCODE-BEGIN:InitFnc                                                                                             */
     OUT = VALUE;
/* USERCODE-END:InitFnc                                                                                               */
}

/**********************************************************************************************************************/
/** Load block data                                                                                                  **/
/**********************************************************************************************************************/
uint8 Constant_Bool_Load(const CONSTANT_BOOL *pTConstant_Bool, uint8 data[], uint16 *dataLength, uint16 maxSize)
{
    uint8 error = (uint8)0;
    if ((uint16)1 > maxSize)
    {
        error = (uint8)1;
    }
    else
    {
        data[0] = (uint8)pTConstant_Bool->K;
        *dataLength = (uint16)1;
/* USERCODE-BEGIN:LoadFnc                                                                                             */
/* USERCODE-END:LoadFnc                                                                                               */
    }
    return (error);
}

/**********************************************************************************************************************/
/** Save block data                                                                                                  **/
/**********************************************************************************************************************/
uint8 Constant_Bool_Save(CONSTANT_BOOL *pTConstant_Bool, const uint8 data[], uint16 dataLength)
{
    uint8 error;

    if (dataLength != (uint16)1)
    {
        error = (uint8)1;
    }
    else
    {
        pTConstant_Bool->K = ((uint8)data[0]);
        error = (uint8)0;
/* USERCODE-BEGIN:SaveFnc                                                                                             */
          OUT = VALUE;
/* USERCODE-END:SaveFnc                                                                                               */
    }
    return (error);
}

/**********************************************************************************************************************/
/** Get block element address                                                                                        **/
/**********************************************************************************************************************/
#if !defined(CONSTANT_BOOL_ISLINKED)
void* Constant_Bool_GetAddress(const CONSTANT_BOOL* block, uint16 elementId)
{
    void* addr;
    switch (elementId)
    {
        case 1:
            addr = (void*)&block->Out;
            break;
        default:
            addr = (void*)0;
            break;
    }
    return (addr);
}
#endif
