/* 
 * File:   rte.h
 * Author: student
 *
 * Created on November 20, 2019, 6:32 PM
 */

#ifndef RTE_H
#define	RTE_H

#include "hal_dc.h"
#include "hal_servo.h"
#include "hal_distance.h"

#define RTE_vMotorInit Hal_vMotorInit
#define RTE_vSetMotorDir Hal_vSetMotDir
#define RTE_vSetMotorSpeed Hal_vSetMotorSpeed
#define RTE_vMotorInit Hal_vMotorInit
//#define RTE_servoInit Hal_servoInit
#define RTE_vSetAngle Hal_setAngle
#define RTE_vGetCentimeters HAL_f16distanceMoved

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* RTE_H */

