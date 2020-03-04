#include"hal_distance.h"

T_U16 HAL_f16distanceMoved(){
    T_U16 centimeters = 0;
    centimeters = QEI_s16getElapsed() / 100;
    return centimeters;
}
