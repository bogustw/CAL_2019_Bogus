/* 
 * File:   asw_move.h
 * Author: student
 *
 * Created on November 27, 2019, 6:57 PM
 */

#ifndef ASW_MOVE_H
#define	ASW_MOVE_H
#include "hal_servo.h"
#include "hal_dc.h"
#include "hal_lf.h"
#include "general.h"
#include "mcal_encoder.h"

void asw_moveInit();
void asw_moveToLine();
void asw_moveUpAndDown();
void asw_moveRightAndLeft();
void move_forward();
void asw_moveDistance(T_S16 centimeters);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* ASW_MOVE_H */

