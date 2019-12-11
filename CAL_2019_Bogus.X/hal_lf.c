#include "hal_lf.h"


void Hal_vSetLineFollower(BOOL bDir){
    
    T_U8 pin = 0;
    
    do{
        GPIO_u8SetPortPin(PORT_C, pin, DIGITAL, bDir);
        pin++;
    }while(pin <6);
   
}

void Hal_vWriteLineFollower(){
//       T_U8 pin = 0;
       Hal_vSetLineFollower(INPUT);
       GPIO_vWritePort(PORT_C,63);
        
       
   
}

T_U8 Hal_vGetLineFollower(){
    
    T_U8 portValue;
    T_U8 MASK = 63;
    Hal_vSetLineFollower(OUTPUT); // setare output
    Hal_vWriteLineFollower();
    
    __delay_us(10);
    
    
    Hal_vSetLineFollower(INPUT); // setare input
    
    __delay_us(500);
    
    portValue = GPIO_u16ReadPort(PORT_C);// citire
           
    return (T_U8)(portValue & MASK);


    
}
