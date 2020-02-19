#include "general.h"
#include "mcal_adc.h"


T_U8 Hal_readBattery(){
    

    
    int i = 0;
    T_F16 level = 0;
    for (i = 0; i < 5; i++) { 
        level = level + ADC_u16Read(0);
    }
    level = level /5;
    
    T_F16 tens = (level * 8.4) /4095;
    
    T_U8 procent;
    if( tens <= 8.4 && tens >= 7 ){
        procent = (tens - 7)* 57.1 + 20;
    }
    if (tens <= 7 && tens >=6.5 ){
        procent = (tens - 6.5)* 20 + 10;
    }
    if (tens <= 6.5 && tens >=6 ){
         procent = (tens - 6)* 20 + 0;
    }
    return procent;
    
    
}
    
    

