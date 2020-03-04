#include "asw_move.h"
#include "rte.h"
#include "sys_tasks.h"
#include "hal_lf.h"

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
        case 1:RTE_vSetAngle(65);
        break;
        
        case 2: RTE_vSetAngle(70);
        break;
        
        case 3: RTE_vSetAngle(75);
        break;
        
        case 4: RTE_vSetAngle(85);
        break;
        
        case 5: RTE_vSetAngle(90);
        break;
        
        case 6: RTE_vSetAngle(95);
        break;
        
        case 7: RTE_vSetAngle(100);
        break;
        
        case 8: RTE_vSetAngle(110);
        break;
        
        case 9: RTE_vSetAngle(115);
        break;
        
        default: RTE_vSetAngle(90);
    }
    
    if(time < 9)
        ++time;
    else
        time = 0;
    
}

void asw_moveToLine(){
//    static T_U16 time = 0;
//    if((Hal_vGetLineFollower() & 12 ) >3 && (Hal_vGetLineFollower() & 12 ) < 13)
//    {
//        RTE_vSetMotorDir(0);
//        RTE_vSetMotorSpeed(25);
//    }
//    else if((Hal_vGetLineFollower() & 3)>0 &&(Hal_vGetLineFollower() & 3 )<2){
//        RTE_vSetMotorDir(0);
//         RTE_vSetMotorSpeed(25);
//         RTE_vSetAngle(110);
//    }
//    else if((Hal_vGetLineFollower() & 3)>2 &&(Hal_vGetLineFollower() & 3 )<4){
//        RTE_vSetMotorDir(0);
//         RTE_vSetMotorSpeed(20);
//         RTE_vSetAngle(100);
//    }
//    else if((Hal_vGetLineFollower() & 48)>16 &&(Hal_vGetLineFollower() & 48 )<33){
//        RTE_vSetMotorDir(0);
//         RTE_vSetMotorSpeed(25);
//         RTE_vSetAngle(78);
//    }
//    else if((Hal_vGetLineFollower() & 48)>15 &&(Hal_vGetLineFollower() & 48 )<33){
//        RTE_vSetMotorDir(0);
//         RTE_vSetMotorSpeed(25);
//         RTE_vSetAngle(65);
//    }
//    else if(Hal_vGetLineFollower()&63 ==0){
//        RTE_vSetMotorDir(0);
//         RTE_vSetMotorSpeed(1);
//    }
//    if(time < 15)
//        ++time;
//    else
//        time = 0;
    
    T_U8 val_negru = Hal_vGetLineFollower();
    
    if (val_negru!=0){
        RTE_vSetMotorSpeed(30);
        __delay_ms(10);

        if( 0b00100000 & val_negru){
            RTE_vSetAngle(65);
            __delay_ms(10);
        }
        if( 0b00010000 & val_negru){
            RTE_vSetAngle(80);
            __delay_ms(10);
        }
        if( 0b00001100 & val_negru){
            RTE_vSetAngle(90);
            __delay_ms(10);
        }
        if( 0b00000001 & val_negru){
            RTE_vSetAngle(110);
            __delay_ms(10);
        }
        if( 0b00000010 & val_negru){
            RTE_vSetAngle(100);
            __delay_ms(10);
        }
    }
    else {
          RTE_vSetMotorDir(1);
            RTE_vSetMotorSpeed(10);
    }
    
    

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


void asw_moveDistance(T_S16 centimeters){
    static T_S16 moved = 0;
    moved += RTE_vGetCentimeters();
    if ( (centimeters - moved) > 0 ){
        RTE_vSetMotorSpeed(30);
    }
    else {
        RTE_vSetMotorSpeed(1);
        
    }
    
}