/*
 * Copyright (c) 2013, Linz Center of Mechatronics GmbH (LCM) http://www.lcm.at/
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
 */
/* USERCODE-BEGIN:Description                                                                                         */
/* Description: 	Makes the incoming signal accessible for reading with parameter numbers.						  */
/*																													  */
/* USERCODE-END:Description                                                                                           */
#include "uSaveSignal_Float64.h"

/* USERCODE-BEGIN:PreProcessor                                                                                        */
/* USERCODE-END:PreProcessor                                                                                          */

/**********************************************************************************************************************/
/** No Update function                                                                                               **/
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/** Initialization                                                                                                   **/
/**********************************************************************************************************************/
void uSaveSignal_Float64_Init(USAVESIGNAL_FLOAT64 *pTuSaveSignal_Float64)
{
    pTuSaveSignal_Float64->ID = USAVESIGNAL_FLOAT64_ID;
/* USERCODE-BEGIN:InitFnc                                                                                             */
/* USERCODE-END:InitFnc                                                                                               */
}

/**********************************************************************************************************************/
/** Load block data                                                                                                  **/
/**********************************************************************************************************************/
uint8 uSaveSignal_Float64_Load(const USAVESIGNAL_FLOAT64 *pTuSaveSignal_Float64, uint8 data[], uint16 *dataLength, uint16 maxSize)
{
    uint8 error = (uint8)0;
    if ((uint16)0 > maxSize)
    {
        error = (uint8)1;
    }
    else
    {
        *dataLength = (uint16)0;
/* USERCODE-BEGIN:LoadFnc                                                                                             */
		data[0] = (uint8)((*(uint64*)(pTuSaveSignal_Float64->In)) & 0x00000000000000FF);
		data[1] = (uint8)((*(uint64*)(pTuSaveSignal_Float64->In) >> 8) & 0x00000000000000FF);
		data[2] = (uint8)((*(uint64*)(pTuSaveSignal_Float64->In) >> 16) & 0x00000000000000FF);
		data[3] = (uint8)((*(uint64*)(pTuSaveSignal_Float64->In) >> 24) & 0x00000000000000FF);
		data[4] = (uint8)((*(uint64*)(pTuSaveSignal_Float64->In) >> 32) & 0x00000000000000FF);
		data[5] = (uint8)((*(uint64*)(pTuSaveSignal_Float64->In) >> 40) & 0x00000000000000FF);
		data[6] = (uint8)((*(uint64*)(pTuSaveSignal_Float64->In) >> 48) & 0x00000000000000FF);
		data[7] = (uint8)((*(uint64*)(pTuSaveSignal_Float64->In) >> 56) & 0x00000000000000FF);
		*dataLength = (uint16)8;
/* USERCODE-END:LoadFnc                                                                                               */
    }
    return (error);
}

/**********************************************************************************************************************/
/** No Save function                                                                                                 **/
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/** Get block element address                                                                                        **/
/**********************************************************************************************************************/
#if !defined(USAVESIGNAL_FLOAT64_ISLINKED)
void* uSaveSignal_Float64_GetAddress(const USAVESIGNAL_FLOAT64* block, uint16 elementId)
{
    void* addr;
    switch (elementId)
    {
        case 1:
            addr = (void*)block->In;
            break;
        default:
            addr = (void*)0;
            break;
    }
    return (addr);
}
#endif
