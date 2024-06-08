#include <stdio.h>
#include "pico/stdlib.h"
#include <stdbool.h>
#include <diagnostic_controller.h>
#include <LED_controller.h>

#define NUM_PIXELS 29

int main()
{
    if (stdio_init_all() != true){
        software_reset();
    }
    printf("Stdio initialized.\n");
    initialize_adc_onboard_temp();
    init_LED();
    // while(true){
    //     cont_light(NUM_PIXELS);
    //     sleep_ms(10);
    // }
    const_light(NUM_PIXELS);
    
}