#include "hal_servo.h"
#include "mcal_pwm.h"

void Hal_vSetServoAngle(T_F16 angle){
    PWM1_vInit();
     
    PWM1_vSetDuty(angle, 1)	 ; // Necesita calcule din modulul 8

}