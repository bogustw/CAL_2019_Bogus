#include "asw_move.h"
#include "rte.h"
#include "sys_tasks.h"

T_F16 angle = 60;
BOOL dir = 1;

void asw_moveInit()
{
    RTE_vMotorInit();
}

void asw_moveUpAndDown()
{
    static T_U16 time = 0;
    if(time == 0)
    {
        RTE_vSetMotorDir(0);
        RTE_vSetMotorSpeed(13);
    }
    if(time == 10)
    {
        RTE_vSetMotorDir(1);
        RTE_vSetMotorSpeed(20);
    }
    if(time < 15)
        ++time;
    else
        time = 0;
    
}

//void asw_dirInit()
//{
//    RTE_vInitServo();
//}


void asw_moveRightAndLeft()
{
    static T_U16 time = 0;
    switch(time)
    {
        case 1:RTE_vSetAngle(50);
        break;
        
        case 2: RTE_vSetAngle(60);
        break;
        
        case 3: RTE_vSetAngle(70);
        break;
        
        case 4: RTE_vSetAngle(80);
        break;
        
        case 5: RTE_vSetAngle(90);
        break;
        
        case 6: RTE_vSetAngle(100);
        break;
        
        case 7: RTE_vSetAngle(110);
        break;
        
        case 8: RTE_vSetAngle(110);
        break;
        
        case 9: RTE_vSetAngle(130);
        break;
        
        default: RTE_vSetAngle(90);
    }
    
    if(time < 9)
        ++time;
    else
        time = 0;
    
}


void move_forward(){
    
    switch(dir){
        case 1:
            RTE_vSetAngle(angle);
            
            if(angle > 130){
                dir =0;
                break;
            }
            angle += 30;
            break;
            
        case 2:
            RTE_vSetAngle(angle);
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