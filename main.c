#include <stdio.h>
#include "pico/stdlib.h"
#include <stdbool.h>
#include <diagnostic_controller.h>

int main()
{
    if (stdio_init_all() != true){
        software_reset();
    }
    printf("Stdio initialized.\n");
    initialize_adc_onboard_temp();
    while(true){
        float temp = read_onboard_temp('C');
        printf("Temperature = %0.2f°C\n", temp);
        sleep_ms(1000);
    }
    
}