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
    while (1) {

        
        switch (seq){
            case 0:
                if(BTN_check_clear_pressed(BTN0)){
                   printk("press 1\n");
                   seq = 1;
                }else if (BTN_check_clear_pressed(BTN1) ||
                        BTN_check_clear_pressed(BTN2) ||
                        BTN_check_clear_pressed(BTN3)) {
                            seq = 0;
                        }
                break;
            case 1:
                if(BTN_check_clear_pressed(BTN1)){
                    printk("press 2\n");
                    seq = 2;
                }else if (BTN_check_clear_pressed(BTN0) ||
                       BTN_check_clear_pressed(BTN2) ||
                       BTN_check_clear_pressed(BTN3)) {
                            seq = 0;
                       }
                break;
            case 2:
                if(BTN_check_clear_pressed(BTN2)){
                    printk("press 3\n");
                    seq = 3;
                }else if (BTN_check_clear_pressed(BTN0) ||
                       BTN_check_clear_pressed(BTN1) ||
                       BTN_check_clear_pressed(BTN3)) {
                            seq = 0;
                       }
                break;
            case 3:
                if(BTN_check_clear_pressed(BTN3)){
                    printk("press 4\n");
                    LED_set(LED0, LED_ON);
                    LED_set(LED1, LED_ON);
                    LED_set(LED2, LED_ON);
                    LED_set(LED3, LED_ON);
                    k_msleep(1000);
                }else if (BTN_check_clear_pressed(BTN0) ||
                       BTN_check_clear_pressed(BTN1) ||
                       BTN_check_clear_pressed(BTN2)) {
                            seq = 0;
                       }
                break;
        }
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