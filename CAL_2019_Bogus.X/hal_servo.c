#include "hal_servo.h"
#include "mcal_pwm.h"

//void Hal_servoInit(){
//    PWM1_vInit();
//
//}

void Hal_setAngle(T_F16 angle){
    
    if (angle < 65 ){angle = 65;
        }
        else if (angle >115){
        angle = 115;  
    }
    angle = (angle - 65 )* 0.117 + 4;
    
    PWM1_vSetDuty(angle, 1)	 ; // Necesita calcule din modulul 8

}