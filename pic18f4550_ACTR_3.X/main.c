#include "sysconfig.h"

#include <xc.h>

#include "main.h"
#include "usb_cdc_lib.h"
#include "actr.h"



void main(void) 
{
    initUSBLib();
    initACTR();
    
    
    while(1)
    {
        
        if(isUSBReady())
        {
            uint8_t i;
            uint8_t numBytesRead;

            numBytesRead = getsUSBUSART(usbReadBuffer, sizeof(usbReadBuffer));

            if(numBytesRead > 0)
            {
                unsigned char well = 0;
                unsigned char ref = 0;
                unsigned char source = 0;
                unsigned char signal = 0;
                unsigned char data_sent = usbReadBuffer[0];
                unsigned char command = data_sent & 0xF0;
                command = data_sent >> 4;
                switch(command)
                {
                    case ENERGIZE: 
                        energize();
                        break;
                    case DEENERGIZE:
                        deenergize();
                        break;
                    case SELECT_WELL:
                        well = data_sent & 0xF;
                        selectWell(well);
                        break;
                    case HOLD_SAMPLE:
                        holdSample();
                        break;
                    case RELEASE_SAMPLE:
                        releaseSample();
                        break;
                    case SELECT_SIGNAL:
                        signal = data_sent & 0xF;
                        selectSignal(signal);
                        break;
                    case MAKE_AD_CONVERSION:
                        makeADConversion(&response);
                        putUSBUSART(&response, sizeof(short));
                        break;
                    case SELECT_SOURCE:
                        source = data_sent & 0xF;
                        selectSource(source);
                        break;
                        
                }


                
            }
        }
        
        // *******************************************************************
        


        
        
        //asm("sleep");  
        
        
        
        CDCTxService();
    }
    
    return;
}

void __interrupt() mainISR (void)
{

    processUSBTasks();
}

