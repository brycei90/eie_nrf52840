/*
 * main.c
 */

#include <zephyr/kernel.h>

#include "BTN.h"
#include "LED.h"

#define SLEEP_MS 10

int main(void) {
    
    //int count = 0;

    if(0 > BTN_init()){
        return 0;
    }
    if(0 > LED_init()){
        return 0;
    }

    int seq = 0;
    int locked = 1;
    while (1) {

        
        k_msleep(SLEEP_MS);         
                        
    }
    
    return 0;
}

// void updateLEDs(int value)
// {
//     int LEDS[4] = {LED0, LED1, LED2, LED3};
//     for(int i = 0; i < 4; i++){
//         if((value >> i) & 1){
//             printk("%d\n", i);
//             LED_set(LEDS[i], LED_ON);
//         }else{
//             LED_set(LEDS[i], LED_OFF);
//         }
//     }
// }