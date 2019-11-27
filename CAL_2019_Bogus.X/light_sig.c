#include "light_sig.h"
#include "sys_tasks.h"
#include "general.h"


void lowBattery(void) // every 100 ms 
{
    static int state = -1;
    if(state < 20)  // perioada de 2 s
        state++;
    else
       state = 0;
    switch (state/2)
    {
        case 1:
        case 3:
        case 5:
            GPIO_u8WritePortPin(PORT_A, 10, 1);
            break;
        default:
            GPIO_u8WritePortPin(PORT_A, 10, 0);
    }
    
}


void obstacleDetected(void)  // every 10 ms
{
    static int state = -1;
    if(state < 100)  // perioada de 1s
        state++;
    else
       state = 0;
    if(state / 25 == 0)   // 0 - 24
        GPIO_u8WritePortPin(PORT_A, 10, 1);
    else
    {
        GPIO_u8WritePortPin(PORT_A, 10, 0);
    }
        
    
    
}

