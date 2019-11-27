#include "hal_servo.h"
#include "mcal_pwm.h"

//void Hal_servoInit(){
//    PWM1_vInit();
//
//}

void Hal_setAngle(T_F16 angle){
    
    angle = (angle - 10 )* 0.04375 + 4;
    if (angle < 6.15 ){angle = 6.15;
        }
        else if (angle > 8.81){
        angle = 8.81;
    }
    PWM1_vSetDuty(angle, 1)	 ; // Necesita calcule din modulul 8

}