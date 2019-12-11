/* 
 * File:   hal_lf.h
 * Author: student
 *
 * Created on December 11, 2019, 6:18 PM
 */

#ifndef HAL_LF_H
#define	HAL_LF_H
#include "mcal_pwm.h"

#ifdef	__cplusplus
extern "C" {
#endif

    void Hal_vSetLineFollower(BOOL bDir);
    void Hal_vWriteLineFollower();
    T_U8 Hal_vGetLineFollower();


#ifdef	__cplusplus
}
#endif

#endif	/* HAL_LF_H */

