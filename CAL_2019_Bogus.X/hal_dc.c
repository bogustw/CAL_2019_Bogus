#include "hal_dc.h"
#include "mcal_pwm.h"

void Hal_vMotorInit(){
      PWM1_vInit();
}

void Hal_vSetMotorSpeed(T_F16 speed){
    PWM1_vSetDuty(speed, 2);
}

void Hal_vSetMotDir(BOOL dir){
    GPIO_u8WritePortPin(PORTA, 9, dir);
    
}