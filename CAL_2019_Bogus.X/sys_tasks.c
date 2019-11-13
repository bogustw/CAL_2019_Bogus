/* 
 * File:   sys_tasks.h
 * Author: Cristian T. A.
 *
 * Created on August 17, 2018, 1:26 PM
 */

#include "general.h"
#include "sys_tasks.h"

#include "mcal_init.h"
#include "asw_com.h"
#include "light_sig.h"
#include "mcal_gpio.h"

T_U16 a = 0;
int counter = 0;
int loading = 0;

void TASK_Inits()
{
    MCAL_vInit();
    GPIO_u8SetPortPin(PORT_A, 10, DIGITAL ,OUTPUT);
}

void TASK_1ms()
{
    
}

void TASK_5ms()
{

}

void TASK_10ms()
{   
//    a = !a;
//    counter++;
//    if(counter == 20){
//        GPIO_u8WritePortPin(PORT_A, 10,a);
//    }
//    counter = 0;
}

void TASK_100ms()
{   
    loading ++;
    counter++;
    if(loading == 6){
        loading = -5;
    }
    a = !a;
    
    if (counter == 2 && loading <6 && loading >= 0){
        GPIO_u8WritePortPin(PORT_A, 10,a);
        counter =0;
        
    }else {
        GPIO_u8WritePortPin(PORT_A, 10,0);
        if (loading == 0){
            counter = 0;
         }
        }
//    Handle_light_signal();
}

void TASK_500ms()
{ 

}

void TASK_1000ms()
{
//    a = !a;
//    GPIO_u8WritePortPin(PORT_A, 10, a);
}