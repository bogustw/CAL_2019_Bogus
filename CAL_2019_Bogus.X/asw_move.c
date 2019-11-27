#include "asw_move.h"
#include "rte.h"
#include "sys_tasks.h"

T_F16 angle = 60;
BOOL dir = 1;

void move_forward(){
    
    switch(dir){
        case 1:
            RTE_setAngle(angle);
            
            if(angle > 130){
                dir =0;
                break;
            }
            angle += 30;
            break;
            
        case 2:
            RTE_setAngle(angle);
            if(angle < 60){
                dir = 1;
                break;
            }
            angle += 30;
            break;
            break;
            
        default:
            break;
    }
    
    
    
}