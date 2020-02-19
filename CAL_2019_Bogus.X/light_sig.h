#ifndef LIGHT_SIG_H
#define	LIGHT_SIG_H

#include "general_types.h"


#ifdef	__cplusplus
extern "C" {
#endif
    
extern void lowBattery(void);
extern void obstacleDetected(void);
extern void batteryLevel(void);

#ifdef	__cplusplus
}
#endif

#endif	/* LIGHT_SIG_H */
